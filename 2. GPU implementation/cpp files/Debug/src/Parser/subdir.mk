################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Parser/Atomtypes.cpp \
../src/Parser/GroParser.cpp \
../src/Parser/Grofile.cpp \
../src/Parser/ItpParser.cpp \
../src/Parser/Nonbondparams.cpp \
../src/Parser/Pairtypes.cpp \
../src/Parser/RtpParser.cpp \
../src/Parser/RtpRename.cpp 

OBJS += \
./src/Parser/Atomtypes.o \
./src/Parser/GroParser.o \
./src/Parser/Grofile.o \
./src/Parser/ItpParser.o \
./src/Parser/Nonbondparams.o \
./src/Parser/Pairtypes.o \
./src/Parser/RtpParser.o \
./src/Parser/RtpRename.o 

CPP_DEPS += \
./src/Parser/Atomtypes.d \
./src/Parser/GroParser.d \
./src/Parser/Grofile.d \
./src/Parser/ItpParser.d \
./src/Parser/Nonbondparams.d \
./src/Parser/Pairtypes.d \
./src/Parser/RtpParser.d \
./src/Parser/RtpRename.d 


# Each subdirectory must supply rules for building sources it contributes
src/Parser/%.o: ../src/Parser/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


