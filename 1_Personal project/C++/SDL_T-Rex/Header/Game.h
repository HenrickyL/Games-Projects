/*  Tudo relacionado ao game
    *gerenciar, contabilizar e tudo mais
*/  

#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "variable.h"
#include "T_rex.h"
#include "Entitie.h"
#include "Rect.h"
#include "Floor.h"
#include "Obstacle.h"
#include "Text.h"

class Game{
public:
    Game( bool RN);
    Game();
    ~Game();
    void tick();                //fazer todas as alterações
    void render();              //mostrar na tela
    void start();               //dar inicio, game loop, ...
    void pause();               //pausar
    void stop();                // parar de vez

private://métodos privados
    //inicializador
    void init();                // inicializa as variáveis
    //geradores
    void generateWindow();      // criar o ponteiro para a janela
    void generateFloor();       // cria o chão com base no tamanho
    void generateT_rex();       // criar o(s) Dinossauros
    void generateObstacle();    // Geraa os obstaculos
    void randomGenerate(int *pos, int len, int initPos, int distMin);
    
    //Destrutores
    void destroyWindow();       // destroi a janela
    void destroyFloor();        // destroi todo o chão
    void destroyT_rex();        // destroi todos os dinossauros
    void destroyObstacle();     // destroi todos os obstaculos
    
    //renderizadores
    void renderT_rex();
    void renderFloor();
    void renderObstacle();
    //caldulador    
    void CalcScore();          // verifica o scorea atual com base no percorrido

private:
    Window      *_window;       // ponteiro para a janela criada
    Text        *_text;         // ponteiro para o gerador de texto
    bool        _runing = false;// variavel do game loop
    int         score = 0;      //contador
    bool        _RN = false;    //é para rede neural?
    //RN
    int         _qtdDino;       // Quantidade de dinossauros
    int         _qtdFloor;      // Quantidade de Chão
    int         _qtdObstacles;  // Quantidade de Obstaculos
    int        *_obsPositions;  // vetor de posições dos obstaculos
    int         _obsMinDist;    // Distância minima entre obstaculos 



};

#endif