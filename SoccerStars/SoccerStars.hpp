#ifndef __FIELDRUNNERS__
#define __FIELDRUNNERS__
#include <sstream>
#include <string>
#include <vector>

#include "../GameManager/GameManager.hpp"

class SoccerStars {
   public:
    SoccerStars();
    void run();

   private:
    GameManager manager;
};

#endif