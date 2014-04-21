################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
robot_stuff.lss \

FLASH_IMAGE += \
robot_stuff.hex \

EEPROM_IMAGE += \
robot_stuff.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: robot_stuff.elf secondary-outputs

# Tool invocations
robot_stuff.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,robot_stuff.map -L"M:\Workspace\RBELib\Release" -mmcu=atmega644p -o "robot_stuff.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

robot_stuff.lss: robot_stuff.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S robot_stuff.elf  >"robot_stuff.lss"
	@echo 'Finished building: $@'
	@echo ' '

robot_stuff.hex: robot_stuff.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex robot_stuff.elf  "robot_stuff.hex"
	@echo 'Finished building: $@'
	@echo ' '

robot_stuff.eep: robot_stuff.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex robot_stuff.elf  "robot_stuff.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: robot_stuff.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega644p robot_stuff.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) robot_stuff.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
