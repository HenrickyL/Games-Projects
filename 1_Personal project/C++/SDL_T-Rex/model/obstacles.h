//arquivo de "Interface"
#ifndef OBSTC_H
#define OBSTC_H

class OBSTC{
private:
	double x,y; //posição
	double Vx; // velocidade x
	int Type;// 1-7
	int timerFrames;
	int FrameCurrent;
	//sprite
public:
	OBSTC();
	~OBSTC();


}


#endif
