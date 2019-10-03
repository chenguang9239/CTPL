BOOSTLIB = /usr/local/boost_1_68_0_lib
BOOSTLOGLIB = ../

DLIBS=-Wl,-rpath,$(BOOSTLIB):$(BOOSTLOGLIB)

POS=-L$(BOOSTLIB) -L$(BOOSTLOGLIB)

LIBS= -lboost_system -lpthread

CXXFLAGS += -std=c++11
CXXFLAGS += -O3
CXXFLAGS += -g
CXXFLAGS += -I../

BIN=test

all: $(BIN)

clean:
	rm -rf *.o $(BIN)

test: test.o
	$(CXX) -o $@ test.o $(POS) $(LIBS) $(DLIBS) -pthread
	@g++ -v