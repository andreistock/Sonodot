# Makefile for Writing Make Files Example
# *****************************************************
# Variables to control Makefile operation

CXX = g++-4.8 -std=c++11
CXXFLAGS = -lwiringPi -pthread -Wall -larmadillo

# ****************************************************
# Targets needed to bring the executable up to date

sensor2: sensor2.cpp Point.o RCSwitch.o
	$(CXX) $(CXXFLAGS) -o sensor2 sensor2.cpp Point.o RCSwitch.o

Point.o: Point.cpp
         $(CXX) -c Point.o Point.cpp 
RCSwitch.o: RCSwitch.o
            $(CXX) -c RCSwitch.o RCSwitch.cpp
