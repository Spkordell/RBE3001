################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ADC.c \
../src/PWM.c \
../src/USARTDebug.c \
../src/autoADC.c \
../src/buttonInterrupts.c \
../src/globals.c \
../src/main.c \
../src/timeStamp.c \
../src/timer.c 

OBJS += \
./src/ADC.o \
./src/PWM.o \
./src/USARTDebug.o \
./src/autoADC.o \
./src/buttonInterrupts.o \
./src/globals.o \
./src/main.o \
./src/timeStamp.o \
./src/timer.o 

C_DEPS += \
./src/ADC.d \
./src/PWM.d \
./src/USARTDebug.d \
./src/autoADC.d \
./src/buttonInterrupts.d \
./src/globals.d \
./src/main.d \
./src/timeStamp.d \
./src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"M:\Workspace\RBELib\include" -Wall -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega644p -DF_CPU=18432000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


