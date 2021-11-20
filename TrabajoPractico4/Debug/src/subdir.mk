################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/LinkedList.c \
../src/TP4.c \
../src/persona.c \
../src/utn.c 

OBJS += \
./src/LinkedList.o \
./src/TP4.o \
./src/persona.o \
./src/utn.o 

C_DEPS += \
./src/LinkedList.d \
./src/TP4.d \
./src/persona.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


