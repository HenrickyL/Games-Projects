#include <iostream>
#include "../Header/Window.h"
#include "../Header/variable.h"
#include "../Header/T_rex.h"
#include "../Header/Entitie.h"
#include "../Header/Rect.h"

/*terminal:
	g++ main.cpp ../Model/Window.cpp ../Model/T_rex.cpp ../Model/Rect.cpp -o main -lSDL2 && ./main
	g++ -o main main.cpp ../Model/Window.cpp ../Model/Floor.cpp ../Model/Entitie.cpp ../Model/T_rex.cpp ../model/variable.h  -lSDL2 -lGL && ./main
*/


int main(){
	Window window(title, WIDTH,HEIGHT);
	window.color("white");
	T_REX dino(window,50,HEIGHT-H_Floor);
	//loop do game
	while(!window.isClosed()){
		window.pollEvents();//verificar Quit


		dino.tick();
		dino.render();
		
		
		window.clear();//sempre no final
		
		
	}
	return 0;
}
