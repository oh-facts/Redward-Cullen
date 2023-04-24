#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>
class Window
{
private:
    sf::RenderWindow m_win;
public:
    Window();
    void create(int x, int y, const char*);
    void poll();
    void clear();
    void display();
    bool isOpen();
    sf::RenderWindow &getWindow();
    ~Window()
    ;
};


#endif