################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.c 

OBJS += \
./Core/.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.o 

C_DEPS += \
./Core/.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.d 


# Each subdirectory must supply rules for building sources it contributes
Core/.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/%.o Core/.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/%.su Core/.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/%.cyclo: ../Core/.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/%.c Core/.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f--2e-metadata-2f--2e-plugins-2f-org-2e-eclipse-2e-cdt-2e-managedbuilder-2e-core

clean-Core-2f--2e-metadata-2f--2e-plugins-2f-org-2e-eclipse-2e-cdt-2e-managedbuilder-2e-core:
	-$(RM) ./Core/.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.cyclo ./Core/.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.d ./Core/.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.o ./Core/.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.su

.PHONY: clean-Core-2f--2e-metadata-2f--2e-plugins-2f-org-2e-eclipse-2e-cdt-2e-managedbuilder-2e-core

