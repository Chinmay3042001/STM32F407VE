################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Clock_Configuration/clk_config.c 

OBJS += \
./Clock_Configuration/clk_config.o 

C_DEPS += \
./Clock_Configuration/clk_config.d 


# Each subdirectory must supply rules for building sources it contributes
Clock_Configuration/%.o: ../Clock_Configuration/%.c Clock_Configuration/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VETx -c -I../Inc -I/STM32F407VE_BareMetal/CMSIS -I"C:/ST/STM32CubeIDE_1.8.0/STM32CubeIDE/STM32F407VET6_BareMetal/STM32F407VE_BareMetal/Clock_Configuration" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Clock_Configuration

clean-Clock_Configuration:
	-$(RM) ./Clock_Configuration/clk_config.d ./Clock_Configuration/clk_config.o

.PHONY: clean-Clock_Configuration

