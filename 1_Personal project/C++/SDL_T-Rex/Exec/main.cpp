#include <iostream>
#include "../Header/Game.h"
#include "../Header/Components.h"
/*
    g++ main.cpp ../Model/Window.cpp ../Model/UI.cpp ../Model/Obstacle.cpp ../Model/T_rex.cpp ../Model/variable.cpp ../Model/Rect.cpp ../Model/Text.cpp ../Model/Game.cpp ../Model/Entitie.cpp ../Model/Floor.cpp -o main -lSDL2 -lSDL2_ttf && ./main
*/



int main(){
    //Game *g = new Game();
    //g->start();
    Window *w = new Window("Teste",800,600);
    w->color("white");

    Text *font = new Text;
    font->addFont(20);
    UILabel *ui = new UILabel(w,100,100);
    ui->setSize(20);
    ui->setColor("red");
    int backTime;
    bool run = true;
    std::string str = "";
    while(!w->isClosed()){
        if(Window::getTime() != backTime){
			std::cout <<"Time: " << Window::getTime() << "\n";
            str = "Time: "+std::to_string(backTime+1);
			backTime = Window::getTime();
		}
        
        ui->render();
        
        w->clear();//sempre no final
		w->pollEvents();
    }

}