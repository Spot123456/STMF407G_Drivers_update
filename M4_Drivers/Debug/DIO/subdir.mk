################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO/GPIO.c 

OBJS += \
./DIO/GPIO.o 

C_DEPS += \
./DIO/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
DIO/%.o DIO/%.su DIO/%.cyclo: ../DIO/%.c DIO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-DIO

clean-DIO:
	-$(RM) ./DIO/GPIO.cyclo ./DIO/GPIO.d ./DIO/GPIO.o ./DIO/GPIO.su

.PHONY: clean-DIO

