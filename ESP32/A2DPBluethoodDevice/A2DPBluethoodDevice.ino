#include <Arduino.h>
#include "BluetoothA2DPSink.h"
#include <driver/i2s.h>

#define SAMPLE_RATE     44100
#define I2S_BCK_PIN     26
#define I2S_WS_PIN      25
#define I2S_DATA_PIN    22

BluetoothA2DPSink ESP32A2DP;

void audioDataCallback(const uint8_t *data, uint32_t len) {
  i2s_write(I2S_NUM_0, data, len, &len, portMAX_DELAY); // Write audio data to I2S
}

void setup() {
  Serial.begin(115200);
  
  i2s_config_t i2s_config = {
    .mode = I2S_MODE_MASTER | I2S_MODE_TX,
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = I2S_COMM_FORMAT_I2S_MSB,
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 8,
    .dma_buf_len = 64,
    .use_apll = false,
    .tx_desc_auto_clear = true,
    .fixed_mclk = 0
  };

  i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_BCK_PIN,
    .ws_io_num = I2S_WS_PIN,
    .data_out_num = I2S_DATA_PIN,
    .data_in_num = I2S_PIN_NO_CHANGE
  };

  i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
  i2s_set_pin(I2S_NUM_0, &pin_config);

  ESP32A2DP.begin("ESP32-A2DP"); // Initialize ESP32-A2DP with your device name
  ESP32A2DP.onAudioData(audioDataCallback); // Set the audio data callback
}

void loop() {
  // You can add your custom logic here if needed
}
