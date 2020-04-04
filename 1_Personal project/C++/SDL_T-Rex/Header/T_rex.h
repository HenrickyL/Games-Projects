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
	int _run; // cada dinossauro corre uma quantidade
	
	//metodos privados
	void tickApplyGravity();
	//void howMuchRun();
	void tickCheckKey();
	void tickPosIncrementation();

	bool isFree(double nextY);

public:
	T_REX(Window *window , double x, double y); //Construtor Dinosauro
	//~T_REX();//Destrutor
	
	//Métodos
	void tick(); // atualizações atributos
	void render(); //atualização gráfica
	void start(); // dino pode correr
	void up(); //pular
	void down(); //abaixa
	//getter e setter 
	bool isDead(){return _dead;}
	inline void setDead(bool dead){_dead = dead;};
	int getStatus();
	void setStatus(int status){this->status = status;};
	double getVx();
	void setVx(double vx);
	double getVy(){return _vy;}
	void setVy(double vy){_vy = vy;}
	double getImpulse(){return  _impulse;}
	void setImpulse(double impulse){_impulse = impulse;}
	int getRun(){return _run;}
	void setRun(int score){_run = score;}

};


#endif