#include <iostream>
#include "Window.h"
#include "QX_ED.hpp"
#include <string>
//#include "Rect.h"

/*
g++ main.cpp Window.cpp QX_ED.cpp -o main -lSDL2 -lSDL2_ttf

*/


int main(){
    QX_list *l = new  QX_list();
    int n,aux;
    std::cout << "Digite quantos numero add a lista: ";
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cout << ">add: ";
        std::cin >> aux;
        l->push_back(aux);
    }
    
    std::cout << "Lista:\n";
    l->print();
    l->draw();
    

    


    return 0;
}
