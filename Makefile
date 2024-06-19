CPPFLAGS = -g
CPP_SOURCE = $(wildcard *.cpp)
HPP_SOURCE = $(wildcard *.hpp)
OBJ = $(subst .cpp,.o, $(addprefix obj/, $(CPP_SOURCE)))

./output.exe: $(OBJ)
	g++ $(CPPFLAGS) -o $@ $^

./obj/main.o: main.cpp $(HPP_SOURCE)
	g++ $(CPPFLAGS) -o $@ $< -c

./obj/%.o: %.cpp %.hpp
	g++ $(CPPFLAGS) -o $@ $< -c