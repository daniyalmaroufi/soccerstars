#include "SoccerStars.hpp"

SoccerStars::SoccerStars(){
    manager= GameManager();
    run();
}

void SoccerStars::run(){
    manager.run();
}