//arquivo de "Interface"
#ifndef TREX_H
#define TREX_H
#include "Entitie.h"
#include <vector>


class T_REX : public Entitie{
private: 
	//int _ticks = 0;
	int _x0,_y0;//iniciais
	double _vx = 0.1 ,_vy=0;
	double _ymax = 30;
	double _g = 0.1; //gravidade
	double _impulse = 1.5;
	double _t=0; // tempo
	int frames;
	int frameCurrent;//frame atual
	int status; // 0-normal, 1- pulando, 2- abaixado, -1  não começou
	bool dead;
	int run; // quantidade corrida (*se colocar mais de um dinossauro tem que trocar)
	//metodos privados
	void applyGravity();
	void howMuchRun();
	void checkKey();
	void up(); //pular
	void down(); //abaixar

public:
	T_REX(Window &window , double x, double y); //Construtor Dinosauro
	//~T_REX();//Destrutor
	
	//Métodos
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