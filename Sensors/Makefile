OBJS = sensor2.o RCSwitch.o
CXX = g++-4.8 -std=c++11
DEBUG = -g
CXXFLAGS = -lwiringPi  -pthread -Wall -larmadillo -I.  -c $(DEBUG)

sensor2 : $(OBJS)
    $(CXX) $(CXXFLAGS) $(OBJS) -o sensor2 

MovieList.o : MovieList.h MovieList.cpp Movie.h NameList.h Name.h Iterator.h
    $(CC) $(CFLAGS) MovieList.cpp

Movie.o : Movie.h Movie.cpp NameList.h Name.h
    $(CC) $(CFLAGS) Movie.cpp

NameList.o : NameList.h NameList.cpp Name.h 
    $(CC) $(CFLAGS) NameList.cpp

Name.o : Name.h Name.cpp 
    $(CC) $(CFLAGS) Name.cpp

Iterator.o : Iterator.h Iterator.cpp MovieList.h
    $(CC) $(CFLAGS) Iterator.cpp

clean:
    \rm *.o *~ p1


CXX = g++-4.8 -std=c++11
CXXFLAGS = -lwiringPi  -pthread -Wall -larmadillo -I.

sensor2: sensor2.o  RCSwitch.o
	$(CXX) $(CXXFLAGS) -o sensor2 RCSwitch.o  sensor2.o   
