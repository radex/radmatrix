#pragma once
#ifndef LEDS_H
#define LEDS_H
#include <Arduino.h>
#include "config.h"

#if defined(COMMON_SER) && (defined(ROW_SER) || defined(COL_SER))
#error "COMMON_SER and ROW_SER/COL_SER cannot be defined at the same time"
#endif

#if defined(COMMON_SER)
#define COL_SER COMMON_SER
#define ROW_SER COMMON_SER
#endif

#if defined(COMMON_RCLK) && (defined(ROW_RCLK) || defined(COL_RCLK))
#error "COMMON_RCLK and ROW_RCLK/COL_RCLK cannot be defined at the same time"
#endif

#if defined(COMMON_RCLK)
#define COL_RCLK COMMON_RCLK
#define ROW_RCLK COMMON_RCLK
#endif

#if defined(COMMON_SRCLR) && (defined(ROW_SRCLR) || defined(COL_SRCLR))
#error "COMMON_SRCLR and ROW_SRCLR/COL_SRCLR cannot be defined at the same time"
#endif

#if defined(COMMON_SRCLR)
#define COL_SRCLR COMMON_SRCLR
#define ROW_SRCLR COMMON_SRCLR
#endif

#define FPS MAX_FPS
#define MS_PER_FRAME (1000 / FPS)


void leds_init();
void leds_initRenderer();
void leds_disable();
void leds_loop();
void leds_render();

void leds_set_framebuffer(uint8_t *buffer);

#endif
