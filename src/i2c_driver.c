#include "i2c_driver.h"

/**
 * @brief Initialize the I2C1 peripheral with a given clock speed.
 * @param clock_speed Desired clock speed in Hz (e.g., 100000 for Standard mode).
 */
void I2C1_Init(uint32_t clock_speed) {
    // 1. Disable I2C peripheral to configure registers
    I2C1->CR1 &= ~(1UL << 0);

    // 2. Configure peripheral clock frequency in CR2 (assuming 16MHz APB1 clock)
    // CR2 bits [5:0] = Peripheral clock frequency in MHz
    uint32_t pclk1_freq = 16000000UL; // 16 MHz standard
    uint32_t freq_mhz = pclk1_freq / 1000000UL;
    I2C1->CR2 = (freq_mhz & 0x3F);

    // 3. Configure Clock Control Register (CCR) for standard mode speed
    // T_high = T_low = CCR * T_PCLK1 -> CCR = PCLK1 / (2 * Desired_Speed)
    uint32_t ccr_value = pclk1_freq / (2U * clock_speed);
    if (ccr_value < 4) {
        ccr_value = 4; // Minimum allowed value for standard mode
    }
    I2C1->CCR = (ccr_value & 0xFFF);

    // 4. Configure Rise Time Register (omitted for brevity, defaulting to standard)

    // 5. Enable I2C peripheral back
    I2C1->CR1 |= (1UL << 0);
}

/**
 * @brief Transmit data as an I2C master.
 * @param slave_addr Target 7-bit slave address.
 * @param pData Pointer to data buffer.
 * @param size Number of bytes to transmit.
 * @return int8_t Status (0 for success, -1 for error/timeout).
 */
int8_t I2C1_MasterTransmit(uint8_t slave_addr, uint8_t *pData, uint16_t size) {
    // Basic stub for master transmission sequence:
    // 1. Generate START condition
    // 2. Send Slave Address with Write bit
    // 3. Wait for address acknowledgment
    // 4. Send data bytes through Data Register (DR)
    // 5. Generate STOP condition

    if (pData == NULL || size == 0) {
        return -1;
    }

    // Placeholder logic for demonstration
    I2C1->CR1 |= (1UL << 8); // Generate START

    for (uint16_t i = 0; i < size; i++) {
        // Wait until data register empty (simulated check)
        while (!(I2C1->SR1 & (1UL << 7))); 
        I2C1->DR = pData[i];
    }

    I2C1->CR1 |= (1UL << 9); // Generate STOP
    return 0;
}