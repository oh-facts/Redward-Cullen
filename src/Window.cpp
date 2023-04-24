#include <Window.hpp>

Window::Window()
{

}

void Window::create(int x, int y, const char *title)
{
    m_win.create(sf::VideoMode(x, y), title);
    m_win.setView(sf::View(sf::FloatRect(0.f, 0.f, m_win.getSize().x, m_win.getSize().y)));

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    m_win.setPosition(sf::Vector2i(desktop.width/2 - m_win.getSize().x/2, desktop.height/2 - m_win.getSize().y/2));
}

void Window::poll()
{
    sf::Event event;
    while (m_win.pollEvent(event))
    {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            m_win.close();
    }
}

void Window::clear()
{
    m_win.clear();
}
void Window::display()
{
    m_win.display();
}
bool Window::isOpen()
{
    return m_win.isOpen();
}
sf::RenderWindow &Window::getWindow()
{
    return m_win;
}
Window::~Window()
{
}
