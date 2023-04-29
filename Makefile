all: main

CXX = clang++
override CXXFLAGS += -g -Wno-everything

main:
	$(CXX) $(CXXFLAGS) main.cpp extenders.cpp -o "$@"

main-debug:
	$(CXX) $(CXXFLAGS) -O0 main.cpp extenders.cpp -o "$@"