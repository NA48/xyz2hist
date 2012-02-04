###################################
### Compiling Variables 	###
###################################

ROOTSYS=/Users/matthewleblanc/root
include $(ROOTSYS)/test/Makefile.arch


CXX 		= g++
LD		= g++
INSTALL 	= /usr/bin/install

##################################

all:
	$(CXX) $(CXXFLAGS) xyz2hist.cpp $(LIBS) -o xyz2hist

.PHONY: clean
clean:
	rm *.root *~ data.txt xyz2hist