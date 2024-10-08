#include <Arduino.h>
#include "hardware/gpio.h"
#include "audio.h"
#include "sd.h"
#include "leds.h"
#include "can.h"
#include "gfx_decoder.h"
#include "can2040.h"
#include "config.h"

void loadVideo(size_t index);

void setup() {
  leds_init();
  pinMode(NEXT_PIN, INPUT_PULLUP);

  delay(2000);
  Serial.begin(115200);
  Serial.println("Hello worldd!");

  if (CPU_CLOCK_HZ != rp2040.f_cpu()) {
    Serial.println("CPU clock speed is not set correctly!");
    while (true) {}
  }

  init_audio();
  leds_initRenderer();

  #if CAN_ENABLED
  canbus_setup();
  #endif

  #if SD_HAS_DETECTION
  while (!isSDCardInserted()) {
    Serial.println("SD card not connected, waiting...");
    delay(1000);
  }
  delay(100);
  #endif

  setupSD();
  sd_loadPlaylist();

  #if DEBUG_TEST_FRAME
  gfx_decoder_setTestFrame();
  #else
  loadVideo(0);
  #endif
}

size_t currentVideoIndex = 0;
bool isLoaded = false;

void loadVideo(size_t index) {
  #if DEBUG_TEST_FRAME
  return;
  #endif

  audio_stop();

  sd_loadAudio(index);

  if (!sd_loadGfxFrameLengths(index)) {
    Serial.println("Failed to load gfx frame lengths");
    return;
  }

  if (!sd_loadGfxBlob(index)) {
    Serial.println("Failed to load gfx blob");
    return;
  }

  isLoaded = true;
}

void nextSong() {
  Serial.println("Next song!");
  currentVideoIndex = (currentVideoIndex + 1) % playlistSize;
  loadVideo(currentVideoIndex);
}

void loop() {
  if (digitalRead(NEXT_PIN) == LOW) {
    delay(100);
    nextSong();
    delay(50);
  }

  // if (Serial.available() > 0) {
  //   char c = Serial.read();
  //   if (c == 'p') {
  //     Serial.println("Paused. Press any key to continue.");
  //     leds_disable();
  //     while (Serial.available() == 0) {
  //       Serial.read();
  //       delay(50);
  //     }
  //     Serial.println("Continuing...");
  //   }
  // }

  if (isLoaded) {
    sd_loadNextAudio();

    auto loopStatus = gfx_decoder_handleLoop();

    if (loopStatus == -1) {
      Serial.println("Failed to load frame...");
    } else if (loopStatus == -2) {
      nextSong();
    }
  }

  #if CAN_ENABLED
  auto canbus_status = canbus_loop();
  if (canbus_status.wants_next_song) {
    delay(100);
    nextSong();
    delay(50);
  }
  #endif
}
