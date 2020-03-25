//arquivo de "Interface"
#ifndef TREX_H
#define TREX_H
#include "Entitie.h"
#include <vector>


class T_REX  : public ENTITIE{
private:
	double vx,vy; //velocidade em c e y (>1)
	double width,height; //largura altura 
	int frames;
	int frameCurrent;//frame atual
	int status; // 0-normal, 1- pulando, 2- abaixado
	bool dead;
	int run; // quantidade corrida (*se colocar mais de um dinossauro tem que trocar)
	void applyGravity();
	void howMuchRun();

public:
	T_REX(double x, double y); //Construtor Dinosauro
	~T_REX();//Destrutor
	
	//Métodos
	void up(); //pular
	void down(); //abaixar
	void tick(); // atualizações atributos
	void render(); //atualização gráfica
	void start(); // dino pode correr
	//getter e setter
	bool getDead();
	void setDead(bool live);
	int getStatus();
	void setStatus(int status);
	double getVx();
	void setVx(double vx);
	double getVy();
	double setVy(double vy);

};


#endif