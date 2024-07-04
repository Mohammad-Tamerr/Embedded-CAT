################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/PORT/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/External_Interrupt/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/SWITCH_DRIVER/subdir.mk
-include HAL/SEVEN_SEG_DRIVER/subdir.mk
-include HAL/LED_DRIVER/subdir.mk
-include HAL/LCD_DRIVER/subdir.mk
-include HAL/KEYPAD_DRIVER/subdir.mk
-include APP/Ping_Pong/subdir.mk
-include APP/EXTI_TEST/subdir.mk
-include APP/Calculator_Project/subdir.mk
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
COTS.lss \

FLASH_IMAGE += \
COTS.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: COTS.elf secondary-outputs

# Tool invocations
COTS.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,COTS.map -mmcu=atmega32 -o "COTS.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

COTS.lss: COTS.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S COTS.elf  >"COTS.lss"
	@echo 'Finished building: $@'
	@echo ' '

COTS.hex: COTS.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex COTS.elf  "COTS.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: COTS.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 COTS.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) COTS.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
