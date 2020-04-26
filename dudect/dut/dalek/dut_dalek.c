#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h> // memcmp

#include "dut.h"
#include "random.h"

// the rust wrappers
extern int sign(unsigned char* keypair, unsigned char* message, size_t message_len);
extern int keypair(const unsigned char* keypair_buf);

//
const size_t chunk_size = 64;
const size_t number_measurements = 1e5; // per test

void init_dut(void) {}

uint8_t do_one_computation(uint8_t *data) {
  uint8_t out[64] = {0};
  uint8_t ret = 0;

  sign(data, out, 64); memcpy(data, out, 64);
  sign(data, out, 64); memcpy(data, out, 64);
  sign(data, out, 64); memcpy(data, out, 64);
  sign(data, out, 64); memcpy(data, out, 64);
  sign(data, out, 64); memcpy(data, out, 64);
  sign(data, out, 64); memcpy(data, out, 64);
  sign(data, out, 64); memcpy(data, out, 64);
  sign(data, out, 64); memcpy(data, out, 64);
  
  ret ^= out[0];
  return ret;
}

void prepare_inputs(uint8_t *input_data, uint8_t *classes) {
  for (size_t i = 0; i < number_measurements; i++) {
    // generate a keypair and store it
    uint8_t keypair_bytes[64] = {0};
    keypair(keypair_bytes);
    memcpy(input_data + i * (size_t)chunk_size, keypair_bytes, chunk_size);

    // decide if we want all 0 keypair or not
    classes[i] = randombit();
    if (classes[i] == 0) {
      memset(input_data + i * (size_t)chunk_size, 0x00, 32);
    } else {
      // leave random
    }
  }
}




