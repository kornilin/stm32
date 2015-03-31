################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/src/stm32f4-spl/misc.c \
../system/src/stm32f4-spl/stm32f4xx_dma.c \
../system/src/stm32f4-spl/stm32f4xx_gpio.c \
../system/src/stm32f4-spl/stm32f4xx_rcc.c \
../system/src/stm32f4-spl/stm32f4xx_spi.c \
../system/src/stm32f4-spl/stm32f4xx_usart.c 

OBJS += \
./system/src/stm32f4-spl/misc.o \
./system/src/stm32f4-spl/stm32f4xx_dma.o \
./system/src/stm32f4-spl/stm32f4xx_gpio.o \
./system/src/stm32f4-spl/stm32f4xx_rcc.o \
./system/src/stm32f4-spl/stm32f4xx_spi.o \
./system/src/stm32f4-spl/stm32f4xx_usart.o 

C_DEPS += \
./system/src/stm32f4-spl/misc.d \
./system/src/stm32f4-spl/stm32f4xx_dma.d \
./system/src/stm32f4-spl/stm32f4xx_gpio.d \
./system/src/stm32f4-spl/stm32f4xx_rcc.d \
./system/src/stm32f4-spl/stm32f4xx_spi.d \
./system/src/stm32f4-spl/stm32f4xx_usart.d 


# Each subdirectory must supply rules for building sources it contributes
system/src/stm32f4-spl/%.o: ../system/src/stm32f4-spl/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DSTM32F405xx -DHSE_VALUE=8000000 -DUSE_STDPERIPH_DRIVER -DSTM32F40XX -I"../include" -I"../system/include" -I"../system/include/cmsis" -I../system/include/stm32f4-spl -I/classF4/lib -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


