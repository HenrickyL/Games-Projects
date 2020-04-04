#include <iostream>
#include <string>
#include<sstream>
#include "../Header/Window.h"
#include "../Header/variable.h"
#include "../Header/T_rex.h"
#include "../Header/Entitie.h"
#include "../Header/Rect.h"
#include "../Header/Floor.h"
#include "../Header/Obstacle.h"
#include "../Header/Text.h"

/*terminal:
	g++ main.cpp ../Model/Window.cpp  ../Model/Obstacle.cpp ../Model/T_rex.cpp ../Model/variable.cpp ../Model/Rect.cpp ../Model/Text.cpp ../Model/Entitie.cpp ../Model/Floor.cpp -o main -lSDL2 -lSDL2_ttf && ./main
	g++ -o main main.cpp ../Model/Window.cpp ../Model/Floor.cpp ../Model/Entitie.cpp ../Model/T_rex.cpp ../model/variable.h  -lSDL2 -lGL && ./main
*/


int main(){
	Window window(title, WIDTH,HEIGHT);
	window.color("white");
	int pos=0;
	int qtdFloor = 20;
	
	for(int i=0;i < qtdFloor; i++){
		Floor *f = new Floor(window, pos,yFloor);
		pos+=WIDTH/16;
	}
	//Floor 0
	int atvFloor = -1;
	Floor *f0 = floors.at(0); 
	OBSTC *o1 = new OBSTC(window, WIDTH/2,yFloor,1);
	OBSTC *o2 = new OBSTC(window, WIDTH/2+50,yFloor,2);
	
	///Text *text = new Text(window,30);
	
	
	//Floor floor(window,0 ,HEIGHT-H_Floor);
	double imp;
	//std::cout<<"Quanto de impulso?\n";
	//std::cin >> imp;
	T_REX *dino =  new T_REX(window,50,HEIGHT-H_Floor);
	//dino->setVy(imp);
	//loop do game
	int backTime = Window::getTime();
	while(!window.isClosed()){
		if(Window::getTime() != backTime){
			std::cout <<"Time: " << Window::getTime() << "\n";
			backTime = Window::getTime();
		}

		//text->drawText("Timer",WIDTH-text->getWidth(),2);
		
		
		for(int i=0;i<entities.size();i++){ 
			entities.at(i)->draw();			
		}
		f0->tick();
		if(f0->getStart()){
			if(atvFloor == -1){
				for(int i = 1; i < qtdFloor; i++)(floors.at(i))->setStart(true);
				atvFloor = 0;
			}
			for(int i = 1; i < qtdFloor ; i++)(floors.at(i))->tick();
		}
		o1->tick();
		o2->tick();

		dino->tick();
		
		
		
		
		window.clear();//sempre no final
		window.pollEvents();
		
	}
	for(int i = 1; i < qtdFloor ; i++) delete floors.at(i);
	return 0;
}
