#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <Yekate/Core/Window.hpp>


namespace Yekate
{
Window::Window()
{
}
void Window::create(int x, int y, const char* title)
{
  m_win.create(sf::VideoMode(x, y), title);
  sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
  m_win.setPosition(sf::Vector2i(desktop.width/2 - m_win.getSize().x/2, desktop.height/2 - m_win.getSize().y/2));
}
bool Window::poll(sf::Event& event)
{
  return m_win.pollEvent(event);
}
void Window::setActive(bool e)
{
  m_win.setActive(e);
}
void Window::close()
{
  m_win.close();
}

void Window::toggleFullScreen()
{

  // Toggle fullscreen mode on alt+enter
  if (m_win.isOpen() && m_win.hasFocus())
  {
    if (m_win.getSize() == sf::Vector2u(sf::VideoMode::getDesktopMode().width,sf::VideoMode::getDesktopMode().height))
    {
      m_win.create(sf::VideoMode(1280, 720), "Yekate2D", sf::Style::Titlebar | sf::Style::Close);
    }
  else
    {
      m_win.create(sf::VideoMode::getDesktopMode(), "Yekate2D", sf::Style::Fullscreen);
    }

  }

}
void Window::clear()
{
  m_win.clear();
}
void Window::draw(sf::Drawable& sprite)
{
  m_win.draw(sprite);
}
void Window::display()
{
  m_win.display();
}
void Window::setView(sf::View view)
  {
  m_win.setView(view);
}
sf::Vector2u Window::getSize()
  {
  return m_win.getSize();
}

bool Window::isOpen()
  {
  return m_win.isOpen();
}


}
