#ifndef I2C_DRIVER_H
#define I2C_DRIVER_H

#include <stdint.h>

// Example Base Address for I2C Peripheral (Adjust based on your target MCU, e.g., STM32)
#define I2C1_BASE_ADDR   0x40005400UL

// I2C Register Definition Structure
typedef struct {
    volatile uint32_t CR1;   // Control Register 1
    volatile uint32_t CR2;   // Control Register 2
    volatile uint32_t OAR1;  // Own Address Register 1
    volatile uint32_t DR;    // Data Register
    volatile uint32_t SR1;   // Status Register 1
    volatile uint32_t SR2;   // Status Register 2
    volatile uint32_t CCR;   // Clock Control Register
} I2C_TypeDef;

#define I2C1   ((I2C_TypeDef *) I2C1_BASE_ADDR)

// Function Prototypes
void I2C1_Init(uint32_t clock_speed);
int8_t I2C1_MasterTransmit(uint8_t slave_addr, uint8_t *pData, uint16_t size);

#endif // I2C_DRIVER_H