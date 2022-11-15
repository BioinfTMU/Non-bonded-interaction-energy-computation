################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Electrostatic.cpp \
../src/Hydrogenbond.cpp \
../src/PDB-itpParser.cpp \
../src/VanderWaals.cpp 

OBJS += \
./src/Electrostatic.o \
./src/Hydrogenbond.o \
./src/PDB-itpParser.o \
./src/VanderWaals.o 

CPP_DEPS += \
./src/Electrostatic.d \
./src/Hydrogenbond.d \
./src/PDB-itpParser.d \
./src/VanderWaals.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


