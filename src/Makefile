CXX = g++-4.8 -std=c++11
DEBUG = -g
CXXFLAGS = -lwiringPi  -pthread -Wall -larmadillo 

IDIR =../include
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

_DEPS = sensor.hpp RCSwitch.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = sensor2.o RCSwitch.o Kalman_3D.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

sensor2: sensor2.cpp RCSwitch.o
	$(CXX) -o $@ $^ $(CXXFLAGS) 

clean:
	rm -f $(ODIR)/*.
