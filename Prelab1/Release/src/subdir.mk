################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/USARTDebug.c \
../src/ledButton.c \
../src/ledTimer.c \
../src/main.c \
../src/serialEcho.c 

OBJS += \
./src/USARTDebug.o \
./src/ledButton.o \
./src/ledTimer.o \
./src/main.o \
./src/serialEcho.o 

C_DEPS += \
./src/USARTDebug.d \
./src/ledButton.d \
./src/ledTimer.d \
./src/main.d \
./src/serialEcho.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"M:\Workspace\RBELib\include" -Wall -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega644p -DF_CPU=18432000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


