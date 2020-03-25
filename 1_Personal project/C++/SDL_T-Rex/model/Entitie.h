//arquivo de "Interface"
#ifndef ENTITIE_H
#define ENTITIE_H
//todo tipo de entidade, como Chão, Nuvem, TRex, Obstaculo

class ENTITIE{
protected:
	//atributos
	double x0,y0;
	double x,y; //posições
	//sprite
	
	//double vX,vY; //velocidade em x e y
	//double width,height; //largura altura 
	//int frameCurrent;//frame atual

	

public:
	ENTITIE(double X, double y); //Construtor Dinosauro
	~ENTITIE();//Destrutor
	
	//Métodos
	
	
	//getter e setter
	double getX();
	void setX(double x);
	double getY();
	void setY(double y);
	/*double getWidth();
	void setWidth(double width);
	double getHeight();
	double setHeight(double height);*/

};


#endif