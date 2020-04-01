//arquivo de "Interface"
#ifndef TREX_H
#define TREX_H
#include "Entitie.h"


class T_REX : public Entitie{
private: 
	double _ymax = 30;
	double _g = 0.08; //gravidade
	double _impulse = 1.5;
	int frames;
	int frameCurrent;//frame atual
	int status = -1; // 0-normal, 1- pulando, 2- abaixado, -1  não começou
	bool _dead = false;
	int run; // cada dinossauro corre uma quantidade
	int _initTime = Window::getTime();
	//metodos privados
	void tickApplyGravity();
	//void howMuchRun();
	void tickCheckKey();
	void up(); //pular
	void down(); //abaixa
	void tickPosIncrementation();

	bool isFree(double nextY);

public:
	T_REX(Window &window , double x, double y); //Construtor Dinosauro
	//~T_REX();//Destrutor
	
	//Métodos
	void tick(); // atualizações atributos
	void render(); //atualização gráfica
	void start(); // dino pode correr
	//getter e setter 
	bool getDead();
	inline void setDead(bool dead){_dead = dead;};
	int getStatus();
	void setStatus(int status){this->status = status;};
	double getVx();
	void setVx(double vx);
	double getVy(){return _vy;}
	void setVy(double vy){_vy = vy;}
	double getImpulse(){return  _impulse;}
	void setImpulse(double impulse){_impulse = impulse;}

};


#endif