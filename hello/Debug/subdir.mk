################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../array.c \
../bit.c \
../bsearch.c \
../circular.c \
../hello.c \
../mmap.c \
../strings.c 

OBJS += \
./array.o \
./bit.o \
./bsearch.o \
./circular.o \
./hello.o \
./mmap.o \
./strings.o 

C_DEPS += \
./array.d \
./bit.d \
./bsearch.d \
./circular.d \
./hello.d \
./mmap.d \
./strings.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


