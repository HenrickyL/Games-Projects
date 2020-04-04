#include <iostream>
#include "../Header/Game.h"
/*
    g++ main.cpp ../Model/Window.cpp  ../Model/Obstacle.cpp ../Model/T_rex.cpp ../Model/variable.cpp ../Model/Rect.cpp ../Model/Text.cpp ../Model/Game.cpp ../Model/Entitie.cpp ../Model/Floor.cpp -o main -lSDL2 -lSDL2_ttf && ./main
*/



int main(){
    Game *g = new Game();
    g->start();
}