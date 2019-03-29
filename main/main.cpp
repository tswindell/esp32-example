#include <Arduino.h>

#include "esp_system.h"
#include "esp_spi_flash.h"

#include "SSD1306.h"
#include "OLEDDisplayFonts.h"

// Application Global
SSD1306 display(0x3C, 5, 4);

/**
 * Application Entry-Point
 */
void setup () {
  esp_chip_info_t chip_info;
  esp_chip_info(&chip_info);

  Serial.begin(115200);
  Serial.println("Hello, Arduino!");

  Serial.println("System Information:");
  Serial.printf("  Flash %dMB\n", spi_flash_get_chip_size() / (1024 * 1024));

  if (chip_info.features & CHIP_FEATURE_BT) {
    Serial.println("  Bluetooth: Available");
  }
  if (chip_info.features & CHIP_FEATURE_BLE) {
    Serial.println("  Bluetooth LE: Available");
  }

  display.init();
  display.setBrightness(64);
  display.setFont(ArialMT_Plain_16);
  display.drawString(0, 0, "ESP32 Arduino");
  display.display();
}

/**
 * Application Main Loop
 */
void loop () {
  
}