################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/src/led.cpp \
../lib/src/usart.cpp 

OBJS += \
./lib/src/led.o \
./lib/src/usart.o 

CPP_DEPS += \
./lib/src/led.d \
./lib/src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
lib/src/%.o: ../lib/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DSTM32F405xx -DHSE_VALUE=8000000 -DUSE_STDPERIPH_DRIVER -DSTM32F40XX -I"../include" -I"../system/include" -I"../system/include/cmsis" -I../system/include/stm32f4-spl -I/classF4/lib -std=gnu++11 -fabi-version=0 -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


