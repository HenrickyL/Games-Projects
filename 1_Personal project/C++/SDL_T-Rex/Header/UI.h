/* Header
    - classe que gerencia UserInterface interfaces de texto ou imagem que o usuário
    visualiza e interage

    -Henrikcyl1@gmail.com (HenrickyL)
    - font: https://youtu.be/PHaP3wDggnw
*/
#ifndef UI_H
#define UI_H
#include "Text.h"
#include "Window.h"
class UILabel: private Window{
public:
    UILabel(Window* window,int posX, int posY, std::string text, std::string font, std::string color);
    UILabel(Window* window,int posX, int posY);
    ~UILabel();
    //métodos
    void setLabelText(std::string text);    // criar um texto
    void render();          // Renderizar UI
    void addFont(std::string path,int size);
    void setSize(int size){_fontSize = size;}
    void setColor(std::string color){_textColor = colors[color];}
private:
    SDL_Rect _position;
    SDL_Color _textColor = {0,0,255};
    std::string _labelText;
    std::string _labelFont;
    SDL_Texture* _labelTexture;
    TTF_Font* _font;
    
    int _fontSize = 16;
    std::string _fontPath = "../Fonts/arial.ttf";
    //método auxiliar
    void updateRect();      // atualizar posição e comprimento do retangulo
}; 

#endif 