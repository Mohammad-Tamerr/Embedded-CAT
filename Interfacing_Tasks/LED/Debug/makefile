################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -f

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/PORT/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/SWITCH_DRIVER/subdir.mk
-include HAL/SEVEN_SEG_DRIVER/subdir.mk
-include HAL/LED_DRIVER/subdir.mk
-include HAL/LCD_DRIVER/subdir.mk
-include HAL/KEYPAD_DRIVER/subdir.mk
-include APP/test/subdir.mk
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
libLED.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: libLED.a secondary-outputs

# Tool invocations
libLED.a: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR Archiver'
	avr-ar -r  "libLED.a" $(OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

libLED.lss: libLED.a
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S libLED.a  >"libLED.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: libLED.a
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 libLED.a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(ARCHIVES)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) libLED.a
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
