cmake_minimum_required(VERSION 3.22)

project(STM32G4)
add_library(STM32G4 INTERFACE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

target_compile_definitions(STM32G4 INTERFACE
    USE_FULL_LL_DRIVER
    USE_NUCLEO_64
    USE_HAL_DRIVER
    STM32G474xx
    $<$<CONFIG:Debug>:DEBUG>
)

target_include_directories(STM32G4 INTERFACE
    ../../include
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Inc
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Inc/Legacy
    ../../lib/STM32G4xx/Device/ST/CMSIS/Include
)

target_sources(STM32G4 INTERFACE
    ../../src/main/main.c
    ../../src/main/stm32g4xx_it.c
    ../../src/main/stm32g4xx_hal_msp.c
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_utils.c
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_exti.c
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_gpio.c
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_pwr.c
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_lpuart.c
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Src/stm32g4xx_ll_rcc.c
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal.c
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_rcc.c
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_rcc_ex.c
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash.c
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash_ex.c
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash_ramfunc.c
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_gpio.c
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_exti.c
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_dma.c
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_dma_ex.c
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_pwr.c
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_pwr_ex.c
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_cortex.c
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_usart.c
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_usart_ex.c
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_uart_ex.c
    ../../lib/STM32G4xx/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_uart.c
    ../../src/main/system_stm32g4xx.c
    ../../src/main/sysmem.c
    ../../src/main/syscalls.c
    ../../src/startup/startup_stm32g474xx.s
)

target_link_directories(STM32G4 INTERFACE
)

target_link_libraries(STM32G4 INTERFACE
)

# Validate that STM32G4 code is compatible with C standard
if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()


