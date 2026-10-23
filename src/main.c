#include "i2c_driver.h"

int main(void) {
    // Initialize I2C1 at 100 kHz
    I2C1_Init(100000);

    // Simple dummy payload to test driver function call
    uint8_t data[] = {0xAA, 0xBB};
    I2C1_MasterTransmit(0x3C, data, sizeof(data));

    return 0;
}