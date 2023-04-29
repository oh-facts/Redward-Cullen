#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
namespace Yekate
{
class Window
  {
  public:
    Window();
    void create(int, int, const char*); 
    void setTitle(const char* title);
    void resize(int x, int y);
    void toggleFullScreen();
    void setActive(bool);
    bool poll(sf::Event&);
    void clear();
    void display();
    void draw(sf::Drawable&);
    void close();
    void setView(sf::View);
    sf::Vector2u getSize();
    bool isOpen();

  private:
    sf::RenderWindow m_win;
  };

}



#endif // !WINDOW_HPP
