CPP_EXEC=g++
CPP_STD=-std=c++11
CPP_FLAGS=-g
RSDL_FLAGS=-l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
RSDL_DIR= RSDL/
GAME_MANAGER_DIR=GameManager/
SOCCER_STARS_DIR=SoccerStars/
PLAYER_DIR=Player/
BODY_DIR=Body/


CPP=$(CPP_EXEC) $(CPP_STD) $(CPP_FLAGS)

all: soccerStars.out

soccerStars.out: obj/main.o obj/rsdl.o obj/SoccerStars.o obj/Body.o obj/Player.o
	$(CPP) obj/main.o obj/rsdl.o obj/SoccerStars.o obj/Body.o obj/Player.o $(RSDL_FLAGS) -o soccerStars.out

obj/main.o: main/main.cpp $(RSDL_DIR)rsdl.hpp
	$(CPP) -c main/main.cpp -o obj/main.o

obj/rsdl.o: $(RSDL_DIR)rsdl.hpp $(RSDL_DIR)rsdl.cpp
	$(CPP) -c $(RSDL_DIR)rsdl.cpp -o obj/rsdl.o

obj/Player.o: $(PLAYER_DIR)Player.hpp $(PLAYER_DIR)Player.cpp
	$(CPP) -c $(PLAYER_DIR)Player.cpp -o obj/Player.o

obj/Body.o: $(BODY_DIR)Body.hpp $(BODY_DIR)Body.cpp
	$(CPP) -c $(BODY_DIR)Body.cpp -o obj/Body.o

obj/SoccerStars.o: $(SOCCER_STARS_DIR)SoccerStars.hpp $(SOCCER_STARS_DIR)SoccerStars.cpp
	$(CPP) -c $(SOCCER_STARS_DIR)SoccerStars.cpp -o obj/SoccerStars.o

clean:
	rm -r *.out
	rm -r obj/*.o