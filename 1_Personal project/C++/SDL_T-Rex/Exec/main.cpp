#include <iostream>
#include "../Header/Window.h"
#include "../Header/variable.h"
#include "../Header/T_rex.h"
#include "../Header/Entitie.h"
#include "../Header/Rect.h"
#include "../Header/Floor.h"
#include "../Header/Text.h"

#include <vector>

/*terminal:
	g++ main.cpp ../Model/Window.cpp ../Model/T_rex.cpp ../Model/Rect.cpp ../Model/Text.cpp ../Model/Entitie.cpp ../Model/Floor.cpp -o main -lSDL2 && ./main
	g++ -o main main.cpp ../Model/Window.cpp ../Model/Floor.cpp ../Model/Entitie.cpp ../Model/T_rex.cpp ../model/variable.h  -lSDL2 -lGL && ./main
*/


int main(){
	Window window(title, WIDTH,HEIGHT);
	window.color("white");
	std::string str = "";
	str+=Window::getTime();
	Text text(window,30,str,{0,255,0});
	std::vector<Floor> floors;
	int pos=0;
	/*
	for(int i=0;i < 30; i++){
		Floor f(window, pos,yFloor);
		floors.push_back(f);
		pos+=window.getWidth()/16;
	}*/
	Floor f1(window, pos,yFloor);
	pos+=window.getWidth()/16+10;
	Floor f2(window, pos,yFloor);

	
	
	
	Floor floor(window,0 ,HEIGHT-H_Floor);
	//T_REX dino(window,50,HEIGHT-H_Floor);
	//loop do game
	while(!window.isClosed()){
		//verificar Quit
		f1.draw();
		f2.draw();
		text.display(WIDTH-text.getWidth(),2);
		/*
		for(int i=0;i<30;i++){ 
			(floors.at(i)).draw();
			(floors.at(i)).tick();
		}*/


		//dino.tick();
		//dino.render();
		
		
		window.clear();//sempre no final
		window.pollEvents();
		
	}
	return 0;
}
