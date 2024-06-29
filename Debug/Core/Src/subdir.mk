################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/bluetooth_module.c \
../Core/Src/bluetooth_task.c \
../Core/Src/freertos.c \
../Core/Src/main.c \
../Core/Src/main_task.c \
../Core/Src/oled.c \
../Core/Src/queue.c \
../Core/Src/screen_task.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c \
../Core/Src/tlv.c 

OBJS += \
./Core/Src/bluetooth_module.o \
./Core/Src/bluetooth_task.o \
./Core/Src/freertos.o \
./Core/Src/main.o \
./Core/Src/main_task.o \
./Core/Src/oled.o \
./Core/Src/queue.o \
./Core/Src/screen_task.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o \
./Core/Src/tlv.o 

C_DEPS += \
./Core/Src/bluetooth_module.d \
./Core/Src/bluetooth_task.d \
./Core/Src/freertos.d \
./Core/Src/main.d \
./Core/Src/main_task.d \
./Core/Src/oled.d \
./Core/Src/queue.d \
./Core/Src/screen_task.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d \
./Core/Src/tlv.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -DSTM32_THREAD_SAFE_STRATEGY=4 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/ThreadSafe -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/bluetooth_module.cyclo ./Core/Src/bluetooth_module.d ./Core/Src/bluetooth_module.o ./Core/Src/bluetooth_module.su ./Core/Src/bluetooth_task.cyclo ./Core/Src/bluetooth_task.d ./Core/Src/bluetooth_task.o ./Core/Src/bluetooth_task.su ./Core/Src/freertos.cyclo ./Core/Src/freertos.d ./Core/Src/freertos.o ./Core/Src/freertos.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/main_task.cyclo ./Core/Src/main_task.d ./Core/Src/main_task.o ./Core/Src/main_task.su ./Core/Src/oled.cyclo ./Core/Src/oled.d ./Core/Src/oled.o ./Core/Src/oled.su ./Core/Src/queue.cyclo ./Core/Src/queue.d ./Core/Src/queue.o ./Core/Src/queue.su ./Core/Src/screen_task.cyclo ./Core/Src/screen_task.d ./Core/Src/screen_task.o ./Core/Src/screen_task.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su ./Core/Src/tlv.cyclo ./Core/Src/tlv.d ./Core/Src/tlv.o ./Core/Src/tlv.su

.PHONY: clean-Core-2f-Src

