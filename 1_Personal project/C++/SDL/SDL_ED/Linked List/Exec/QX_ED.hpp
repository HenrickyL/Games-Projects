#ifndef QX_ED_HPP
#define QX_ED_HPP

#include "Window.h"
#include "Rect.h"
#include <vector>
#include "Text.h"
struct Node;
struct Point;//draw

class QX_list{
public: 
    QX_list();
    ~QX_list();
    void push_back(int key);
    int pop_back();
    int at(int i);
    bool empth();
    void print();
    int size();
    void draw();
private:
    Node *_head = nullptr;
    Text *_text = nullptr;
    Window *_window;
    int _Width = 800;
    int _Heigth = 400;
    int _drawNodeDist = 20;
    int _w = 60;
    int _h = 45;
    int _x; 
    int _y;
    std::vector<Rect*> _nodes;

    void drawNode();
    void draw_CreateNode(Node *node);
    //auxiliares
    void drawNode_Arrow(Point p1, Point p2);//do ponto 1 ao 2
    void drawNodeL_Head(Point p1, Point p2);
    void drawNodeL_Last(Point p1, Point p2);
    void drawNull(Point p);
    


};




#endif