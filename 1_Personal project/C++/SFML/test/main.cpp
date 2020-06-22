#include <iostream>
#include <SFML/Graphics.hpp>






int main(){
        std::locale brasilLocale("pt_BR.UTF-8");; // spanish
        std::locale::global (brasilLocale); // needed for console output only???


        int _w = 800,_h = 400;
        std::string _title = "SFML Tutorial";
        sf::RenderWindow window(sf::VideoMode(_w,_h),_title, sf::Style::Close | sf::Style::Resize | sf::Style::Titlebar);
        //draw square
        sf::RectangleShape player(sf::Vector2f(100.0f,100.0f));
        player.setFillColor(sf::Color::Red);
        player.setPosition(10,10);
        
        
        //font
        sf::Font font;
        if (!font.loadFromFile("arial.ttf")){
                std::cout << "Error to load Font!\n";
        }
        std::string  txt=  "" ; 
        sf::Text text;

        // select the font
        text.setFont(font); // font is a sf::Font

        // // set the string to display
        // text.setString("Hello world");

        // set the character size
        text.setCharacterSize(24); // in pixels, not points!

        // set the color
        text.setFillColor(sf::Color::Green);

        // set the text style
        //text.setStyle(/*sf::Text::Bold |*/ sf::Text::Underlined);




        //loop
        while (window.isOpen()){
                
                
                //event
                sf::Event evnt;
                while(window.pollEvent(evnt)){

                        switch (evnt.type)
                        {
                        case sf::Event::Closed :
                                window.close();
                                break;
                        case  sf::Event::Resized:
                                std::cout << "Window: " << evnt.size.width << ", " << evnt.size.height << "\n";
                                break;
                        case sf::Event::TextEntered:
                                if(evnt.text.unicode < 128)
                                        txt +=  evnt.text.unicode;      
                                         text.setString(txt);                           
                                        //printf("%c", evnt.text.unicode);
                                
                                break;
                        default:
                                break;
                        }



                        
                }
                //draw
                window.draw(text);
                window.display();
        } 

    return 0;
}