################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ADC.c \
../src/DAC.c \
../src/PID.c \
../src/SPI.c \
../src/USARTDebug.c \
../src/armActuator.c \
../src/autoADC.c \
../src/currentSensor.c \
../src/encoder.c \
../src/globals.c \
../src/kinematics.c \
../src/main.c \
../src/myatof.c \
../src/stateMachine.c \
../src/timer.c 

OBJS += \
./src/ADC.o \
./src/DAC.o \
./src/PID.o \
./src/SPI.o \
./src/USARTDebug.o \
./src/armActuator.o \
./src/autoADC.o \
./src/currentSensor.o \
./src/encoder.o \
./src/globals.o \
./src/kinematics.o \
./src/main.o \
./src/myatof.o \
./src/stateMachine.o \
./src/timer.o 

C_DEPS += \
./src/ADC.d \
./src/DAC.d \
./src/PID.d \
./src/SPI.d \
./src/USARTDebug.d \
./src/armActuator.d \
./src/autoADC.d \
./src/currentSensor.d \
./src/encoder.d \
./src/globals.d \
./src/kinematics.d \
./src/main.d \
./src/myatof.d \
./src/stateMachine.d \
./src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"H:\Workspace\RBELib\include" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega644p -DF_CPU=18432000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


