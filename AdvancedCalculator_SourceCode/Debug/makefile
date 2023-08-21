################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/GPT/subdir.mk
-include MCAL/External_Interrupt/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/_7Seg/subdir.mk
-include HAL/Switch/subdir.mk
-include HAL/Stepper_Motor/subdir.mk
-include HAL/Led/subdir.mk
-include HAL/LM35/subdir.mk
-include HAL/LDR/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/Keypad/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
atmega32_drivers.lss \

FLASH_IMAGE += \
atmega32_drivers.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: atmega32_drivers.elf secondary-outputs

# Tool invocations
atmega32_drivers.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,atmega32_drivers.map -mmcu=atmega32 -o "atmega32_drivers.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

atmega32_drivers.lss: atmega32_drivers.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S atmega32_drivers.elf  >"atmega32_drivers.lss"
	@echo 'Finished building: $@'
	@echo ' '

atmega32_drivers.hex: atmega32_drivers.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex atmega32_drivers.elf  "atmega32_drivers.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: atmega32_drivers.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 atmega32_drivers.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) atmega32_drivers.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
