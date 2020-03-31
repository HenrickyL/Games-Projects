/*  Tudo relacionado ao game
    *gerenciar, contabilizar e tudo mais
*/  

#ifndef GAME_H
#define GAME_H

#include "Rect.h"

class Game: public Rect{
public:
    Game(Window &window);

    void tick(); //fazer todas as alterações
    void render();//mostrar na tela
    void start();
private:
    void howMuchRun(); // verifica o scorea atual com base no percorrido

private:
    //precisa de *
    //vetor de dinossauros
    //um Chão
    bool _start = false;
    int score = 0;


};

#endif