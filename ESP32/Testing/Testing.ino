#include "BluetoothA2DPSink.h"
BluetoothA2DPSink a2dp_sink;

void setup () {
  i2s_pin_config_t my_pin_config = {
    .bck_io_num = 26,
    .ws_io_num = 25,
    .data_out_num = I2S_PIN_NO_CHANGE,
    .data_in_num = I2S_PIN_NO_CHANGE
  };
  a2dp_sink.set_pin_config (my_pin_config);
  a2dp_sink.start ("MyMusic");
}

void loop () {
  // Read the analog values from the socket
  int left_value = analogRead (33);
  int right_value = analogRead (32);

  // Convert the values to PCM format
  int16_t left_pcm = (left_value - 2048) * 16;
  int16_t right_pcm = (right_value - 2048) * 16;

  // Create a frame with two channels
  Frame frame;
  frame.left = left_pcm;
  frame.right = right_pcm;

  // Write the frame to the I2S output
  a2dp_sink.write_data (&frame, sizeof (frame));
}


#include "BluetoothA2DPSink.h"
BluetoothA2DPSink a2dp_sink;

void setup () {
  // Use the internal DAC of the ESP32
  static const i2s_config_t i2s_config = {
    .mode = (i2s_mode_t) (I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_DAC_BUILT_IN),
    .sample_rate = 44100, // corrected by info from bluetooth
    .bits_per_sample = (i2s_bits_per_sample_t) 16, /* the DAC module will only take the 8bits from MSB */
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = (i2s_comm_format_t)I2S_COMM_FORMAT_STAND_MSB,
    .intr_alloc_flags = 0, // default interrupt priority
    .dma_buf_count = 8,
    .dma_buf_len = 64,
    .use_apll = false
  };
  a2dp_sink.set_i2s_config (i2s_config);
  
  // Start the Bluetooth device with the name "MyMusic"
  a2dp_sink.start ("MyMusic");
}

void loop () {
  // Do nothing
}

