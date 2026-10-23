cmake_minimum_required(VERSION 3.10)
project(EdgeConditionMonitor C)

set(CMAKE_C_STANDARD 11)

# Include directories
include_directories(include)

# Add source files
add_executable(firmware
    src/i2c_driver.c
)