################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../MemHeap.o \
../Project3.o \
../main.o 

CPP_SRCS += \
../MemHeap.cpp \
../Project3.cpp \
../main.cpp 

OBJS += \
./MemHeap.o \
./Project3.o \
./main.o 

CPP_DEPS += \
./MemHeap.d \
./Project3.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


