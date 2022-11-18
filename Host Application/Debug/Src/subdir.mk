################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/readPort.c \
../Src/serialPort.c 

C_DEPS += \
./Src/main.d \
./Src/readPort.d \
./Src/serialPort.d 

OBJS += \
./Src/main.o \
./Src/readPort.o \
./Src/serialPort.o 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"C:\Embedded system\STM32\MIKROE-F415RG\Host Application\Headers" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Src

clean-Src:
	-$(RM) ./Src/main.d ./Src/main.o ./Src/readPort.d ./Src/readPort.o ./Src/serialPort.d ./Src/serialPort.o

.PHONY: clean-Src

