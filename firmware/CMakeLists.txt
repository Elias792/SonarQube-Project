cmake_minimum_required(VERSION 3.10)
project(ESP32_FIRMWARE ASM)

add_library(esp32_bootloader STATIC esp32_bootloader.S)
add_library(rpi_blink STATIC raspberry_blink.asm advanced_blink.asm)
