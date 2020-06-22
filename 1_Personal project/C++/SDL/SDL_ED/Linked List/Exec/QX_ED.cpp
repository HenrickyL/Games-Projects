#include <iostream>
#include "QX_ED.hpp"
#include "Rect.h"

struct Node{
    int key = -999;
    Node *next = nullptr;
    Node *back = nullptr;

};
struct Point{
    double x;
    double y;
};

QX_list::QX_list(){
    _head = new Node;
    _head->next = _head;
    _head->back = _head;
    std::cout << "<QX_List Criada!>";
}
QX_list::~QX_list(){
    Node *aux = _head->next;
    Node *dell = aux;
    while(aux != nullptr){
        Node *dell = aux;
        aux = aux->next;
        delete dell; 
    }delete _head;
    //destruir Rects
    while(!_nodes.empty()){
        Rect *r = _nodes.at(_nodes.size()-1);
        delete r;
        _nodes.pop_back();
    }

}
void QX_list::push_back(int key){
    Node *novo = new Node;
    novo->key = key;
    Node *aux = _head->back;
    aux->next = novo;
    novo->back = aux;
    novo->next = _head;
    _head->back = novo;
}
int QX_list::pop_back(){
    if(!empth()){
        Node *aux = _head->back;
        aux->back->next = _head;
        _head->back = aux->back;
        aux->next = nullptr;
        aux->back = nullptr;
        
        return aux->key;
        delete aux;       

    }return -999;
}
int QX_list::at(int i){
    int index = 0;
    Node *aux = _head->next;
    while( aux != _head ){
        if(index == i){
            return aux->key;
        }else{
            index++;
            aux = aux->next;
        }
    }
    return -999;
}
bool QX_list::empth(){
    return (_head == nullptr);
}
int QX_list::size(){
    int n=0;
    Node *aux = _head->next;
    while(aux != _head){
        n++;
        aux = aux->next;
    }return n;
}

void QX_list::print(){
    Node *aux = _head->next;
    std::cout <<"\n";
    while(aux != _head){
        std::cout << aux->key<<",";
        aux = aux->next;
    }std::cout <<"\n";
}
//////////////////////////////////////////////////////////
void QX_list::draw(){
    bool runing = true;
    
    _window = new Window("Draw QX_List",_Width,_Heigth);
    _window->color("white");
    //texto
    _text = new Text(_window,30);
    _x = _window->getWidth()*0.05;
    _y = _window->getHeight()/2 - _h;
    //gerar rectangulos
    Node *aux = _head->next;
    draw_CreateNode(_head);
    while(aux != _head){
        draw_CreateNode(aux);
        aux = aux->next;
    }
    while(!_window->isClosed()){
        drawNode();
        _window->pollEvents();
        _window->clear();
    }
    SDL_SetRenderDrawColor(Window::_rendererS, 242, 242, 242, 255);
    //SDL_RenderDrawLine(Window::_rendererS,point4);

}

void QX_list::drawNode(){
    //Desenho
    Node *aux = _head;
    Rect *h;
    for(int i=0;i<_nodes.size();i++){
        Rect *r = _nodes.at(i);
        r->draw();
        //definir pontos
        if(r->getType() == "*H"){
            h = r;
            Point p1;
            p1.x = r->getX();
            p1.y = _y+_h/3;
            Point p2;
            p2.x = r->getX()+_w+ this->size()*(_w+_drawNodeDist);
            p2.y = _y+_h/3;
            drawNodeL_Head(p1,p2);
            p1.x = r->getX()+_w;
            p2.x = r->getX()+_w+_drawNodeDist;
            p2.y = _y+_h/3;
            drawNode_Arrow(p1,p2);

        }
        

        if(r->getType() == "*"){
            Point p1;
            p1.x = r->getX()+_w;
            p1.y = _y+_h/3;
            Point p2;
            p2.x = r->getX()+_w+_drawNodeDist;
            p2.y = _y+_h/3;
            drawNode_Arrow(p1,p2);
            if(_nodes.size()-2 == i){
                p2.x = h->getX();
                drawNodeL_Last(p1,p2);
            }

        }
        if(r->getType() == "*"){
            aux = aux->next;  
        }      
    }

}
void QX_list::draw_CreateNode(Node *node){
    //definindo comprimentos:   
    if(node == nullptr){
        Rect *n = nullptr;
        _nodes.push_back(n);
    }else{
        if(node == _head){
            int x = _window->getWidth()*0.05;
            Rect *pointerNodeHead = new Rect(_window,_w,_h,x,_y);
            pointerNodeHead->color("black");
            pointerNodeHead->setType("*H");
            _nodes.push_back(pointerNodeHead);
            Rect *nodeHead  = new Rect(_window,_w*0.6,_h,(x+_w*0.2),_y);
            nodeHead->color("pink");
            _nodes.push_back(nodeHead);
            
        }else{
            Rect *p = new Rect(_window,_w,_h,_x,_y);
            p->color("gray");
            p->setType("*");
            _nodes.push_back(p);
            Rect *r = new Rect(_window,_w*0.6,_h,(_x+_w*0.2),_y);
            r->color("white");
            _nodes.push_back(r);
            

        }

    }_x += _drawNodeDist+_w;
    
}

void QX_list::drawNode_Arrow(Point p1, Point p2){
    SDL_SetRenderDrawColor(Window::_rendererS, 0, 0, 0, 255);
    //Left
        SDL_RenderDrawLine(Window::_rendererS,p1.x,p1.y,p2.x,p2.y);
        //arrow
        SDL_RenderDrawLine(Window::_rendererS,p2.x-5,p1.y-5,p2.x,p2.y);
        SDL_RenderDrawLine(Window::_rendererS,p2.x-5,p1.y+5,p2.x,p2.y);
    //Right fica _h/3 para baixo
        p1.y += _h/3;
        p2.y += _h/3;
        SDL_RenderDrawLine(Window::_rendererS,p1.x,p1.y,p2.x,p2.y);
        //arrow
        SDL_RenderDrawLine(Window::_rendererS,p1.x+5,p1.y-5,p1.x,p1.y);
        SDL_RenderDrawLine(Window::_rendererS,p1.x+5,p1.y+5,p1.x,p1.y);
}
void QX_list::drawNodeL_Head(Point p1, Point p2){
    p1.y += _h/3;
    SDL_SetRenderDrawColor(Window::_rendererS, 0, 0, 255, 255);
    //line back (p1)
    SDL_RenderDrawLine(Window::_rendererS,  p1.x - _drawNodeDist,p1.y,p1.x,p1.y);
    //arrow
    SDL_RenderDrawLine(Window::_rendererS,p1.x - _drawNodeDist +5,p1.y-5,p1.x - _drawNodeDist,p1.y);
    SDL_RenderDrawLine(Window::_rendererS,p1.x - _drawNodeDist +5,p1.y+5,p1.x - _drawNodeDist,p1.y);
    //line down
    SDL_RenderDrawLine(Window::_rendererS, (p1.x - _drawNodeDist),p1.y,(p1.x - _drawNodeDist),p1.y+_h*2/3 );
    //line right
    SDL_RenderDrawLine(Window::_rendererS, (p1.x - _drawNodeDist),p1.y+_h*2/3, p2.x+_drawNodeDist,p1.y+_h*2/3);
    //line up
    SDL_RenderDrawLine(Window::_rendererS,p2.x+_drawNodeDist,p1.y+_h*2/3, p2.x+_drawNodeDist,p2.y+_h/3);
    //line back (p2)
    //SDL_RenderDrawLine(Window::_rendererS,p2.x+_drawNodeDist,p2.y,p2.x,p2.y);
    
}
void QX_list::drawNodeL_Last(Point p1, Point p2){ //p1 para p2, meio que voltando
    SDL_SetRenderDrawColor(Window::_rendererS, 0, 0, 255, 255);
    //line up
    SDL_RenderDrawLine(Window::_rendererS,(p1.x + _drawNodeDist),p1.y,(p1.x + _drawNodeDist),(p1.y - _h*2/3));
    //line left
    SDL_RenderDrawLine(Window::_rendererS,(p1.x + _drawNodeDist),(p1.y - _h*2/3), (p2.x - _drawNodeDist),(p2.y - _h*2/3));
    //line down
    SDL_RenderDrawLine(Window::_rendererS,(p2.x - _drawNodeDist),(p2.y - _h*2/3), (p2.x - _drawNodeDist),p2.y);
    //line Right
    SDL_RenderDrawLine(Window::_rendererS,(p2.x - _drawNodeDist),p2.y, p2.x ,p2.y);
    //arrow
    SDL_RenderDrawLine(Window::_rendererS,p2.x-5,p1.y-5,p2.x,p2.y);
    SDL_RenderDrawLine(Window::_rendererS,p2.x-5,p1.y+5,p2.x,p2.y);
}
void QX_list::drawNull(Point p){
    int wLine1 = 8;
    int wLine2 = 16;
    SDL_SetRenderDrawColor(Window::_rendererS, 255, 0, 0, 255);
    //down
    SDL_RenderDrawLine(Window::_rendererS,p.x,p.y,p.x,p.y+5);
    //line 1
    SDL_RenderDrawLine(Window::_rendererS,p.x - wLine1/2,p.y+5, p.x + wLine1/2 ,p.y+5 );
    //line 2
    SDL_RenderDrawLine(Window::_rendererS, p.x - wLine2/2,p.y+10, p.x + wLine2/2 ,p.y+10);
}