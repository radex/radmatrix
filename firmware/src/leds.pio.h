// -------------------------------------------------- //
// This file is autogenerated by pioasm; do not edit! //
// -------------------------------------------------- //

#pragma once

#if !PICO_NO_HARDWARE
#include "hardware/pio.h"
#endif

#define irq_delaying 0
#define irq_px_pushed 1
#define irq_rclk_sync 2
#define irq_did_latch 3
#define rclk_1_delay 7

// -------------- //
// leds_px_pusher //
// -------------- //

#define leds_px_pusher_wrap_target 0
#define leds_px_pusher_wrap 9

#define leds_px_pusher_srclk_0_delay 0
#define leds_px_pusher_srclk_1_delay 1

static const uint16_t leds_px_pusher_program_instructions[] = {
            //     .wrap_target
    0xf037, //  0: set    x, 23           side 0     
    0x7001, //  1: out    pins, 1         side 0     
    0x1941, //  2: jmp    x--, 1          side 1 [1] 
    0x7028, //  3: out    x, 8            side 0     
    0x0020, //  4: jmp    !x, 0                      
    0xc001, //  5: irq    nowait 1                   
    0x2040, //  6: wait   0 irq, 0                   
    0x20c2, //  7: wait   1 irq, 2                   
    0xe701, //  8: set    pins, 1                [7] 
    0xe000, //  9: set    pins, 0                    
            //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program leds_px_pusher_program = {
    .instructions = leds_px_pusher_program_instructions,
    .length = 10,
    .origin = -1,
};

static inline pio_sm_config leds_px_pusher_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + leds_px_pusher_wrap_target, offset + leds_px_pusher_wrap);
    sm_config_set_sideset(&c, 2, true, false);
    return c;
}
#endif

// ----------------- //
// leds_row_selector //
// ----------------- //

#define leds_row_selector_wrap_target 0
#define leds_row_selector_wrap 9

#define leds_row_selector_srclk_0_delay 0
#define leds_row_selector_srclk_1_delay 1

static const uint16_t leds_row_selector_program_instructions[] = {
            //     .wrap_target
    0x20c1, //  0: wait   1 irq, 1                   
    0x7001, //  1: out    pins, 1         side 0     
    0x603f, //  2: out    x, 31                      
    0xb942, //  3: nop                    side 1 [1] 
    0xb003, //  4: mov    pins, null      side 0     
    0x0043, //  5: jmp    x--, 3                     
    0xc022, //  6: irq    wait 2                     
    0xe701, //  7: set    pins, 1                [7] 
    0xe000, //  8: set    pins, 0                    
    0xc003, //  9: irq    nowait 3                   
            //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program leds_row_selector_program = {
    .instructions = leds_row_selector_program_instructions,
    .length = 10,
    .origin = -1,
};

static inline pio_sm_config leds_row_selector_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + leds_row_selector_wrap_target, offset + leds_row_selector_wrap);
    sm_config_set_sideset(&c, 2, true, false);
    return c;
}
#endif

// ---------- //
// leds_delay //
// ---------- //

#define leds_delay_wrap_target 0
#define leds_delay_wrap 4

#define leds_delay_output_on 0
#define leds_delay_output_off 1

static const uint16_t leds_delay_program_instructions[] = {
            //     .wrap_target
    0x20c3, //  0: wait   1 irq, 3                   
    0xc000, //  1: irq    nowait 0                   
    0x6020, //  2: out    x, 32                      
    0x1043, //  3: jmp    x--, 3          side 0     
    0xd840, //  4: irq    clear 0         side 1     
            //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program leds_delay_program = {
    .instructions = leds_delay_program_instructions,
    .length = 5,
    .origin = -1,
};

static inline pio_sm_config leds_delay_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + leds_delay_wrap_target, offset + leds_delay_wrap);
    sm_config_set_sideset(&c, 2, true, false);
    return c;
}
#endif

