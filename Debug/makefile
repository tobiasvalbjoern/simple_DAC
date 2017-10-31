################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include example/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: E3ISD1_DAC_tonegenerator.axf

# Tool invocations
E3ISD1_DAC_tonegenerator.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\Users\Test Bruger\Documents\MCUXpressoIDE_10.0.2_411\workspace\lpc_chip_40xx\Debug" -L"C:\Users\Test Bruger\Documents\MCUXpressoIDE_10.0.2_411\workspace\lpc_board_ea_devkit_4088\Debug" -Xlinker -Map="E3ISD1_DAC_tonegenerator.map" -Xlinker --gc-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -T "E3ISD1_printf_Debug.ld" -o "E3ISD1_DAC_tonegenerator.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) E3ISD1_DAC_tonegenerator.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "E3ISD1_DAC_tonegenerator.axf"; # arm-none-eabi-objcopy -v -O binary "E3ISD1_DAC_tonegenerator.axf" "E3ISD1_DAC_tonegenerator.bin" ; # checksum -p LPC4088 -d "E3ISD1_DAC_tonegenerator.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
