//arquivo de "Interface"
#ifndef OBSTC_H
#define OBSTC_H
#include "Entitie.h"

class OBSTC : public Entitie{
private:
	int _status = -1;
	int _obs_type;// 1-CactoPequeno(CP), 2 - CM 3- CG , 3 - Passaro(em alguma posição)
	int timerFrames;
	int FrameCurrent;
	int _initTime;
	bool _RNTest = false; //uso em Rede Neural
	//sprite
public:
	OBSTC(Window &window, double x, double y, int type);
	~OBSTC();
	
	//métodos
	void start();
	void tick();
	void render();
private:
	//métodos
	void generateType(int type);
	void tickPosIncrementation();
	void tickColid();
	void tickSpeedIncrementation();
public:
	//getter e setter
	void setVx(double vx){_vx = vx;}
	double getVx(){return _vx;}
	int getStatus(){return _status;}
	void setStatus(int status){_status = status;}

};


#endif
