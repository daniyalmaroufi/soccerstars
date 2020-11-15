CPP_EXEC=g++
CPP_STD=-std=c++11
CPP_FLAGS=-g
RSDL_FLAGS=-l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
RSDL_DIR= RSDL/



CPP=$(CPP_EXEC) $(CPP_STD) $(CPP_FLAGS)

all: soccerStars.out

soccerStars.out: obj/main.o obj/rsdl.o
	$(CPP) obj/main.o obj/rsdl.o $(RSDL_FLAGS) -o soccerStars.out

obj/main.o: main.cpp $(RSDL_DIR)rsdl.hpp
	$(CPP) -c main.cpp -o obj/main.o

obj/rsdl.o: $(RSDL_DIR)rsdl.hpp $(RSDL_DIR)rsdl.cpp
	$(CPP) -c $(RSDL_DIR)rsdl.cpp -o obj/rsdl.o

clean:
	rm -r *.o
	rm -r obj/*.o