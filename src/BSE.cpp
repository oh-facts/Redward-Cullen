#include "Component.hpp"
#include "Input.hpp"
#include <BSE.hpp>
#include <SFML/Graphics/Image.hpp>
#include <memory>
#include <filesystem>


std::shared_ptr<sf::RenderWindow> BSE::m_win = std::make_shared<sf::RenderWindow>();

std::shared_ptr<Scene> BSE::m_currentScene = std::make_shared<Scene>();

sf::Image BSE::m_icon = sf::Image();

int BSE::m_totalScenes = 0;

BSE::BSE(){}

void BSE::innit()
{
  m_win->create(sf::VideoMode(200, 200), "SFML works!");
  if (!m_icon.loadFromFile("res/Engine/icon/mascot.png")) {
    // Error loading the icon
  }

  m_win->setIcon(m_icon.getSize().x, m_icon.getSize().y, m_icon.getPixelsPtr());
}

void BSE::run()
{

  while (m_win->isOpen())
    {
      sf::Event event;
      while (m_win->pollEvent(event))
        {
          if (event.type == sf::Event::Closed)
            m_win->close();
        }


      for(const auto& entity: m_currentScene->m_entities)
      {
        entity->update();
      }


      m_win->clear();


      for(const auto& entity: m_currentScene->m_entities)
      {
        entity->render();
      }

      m_win->display();
    }

}

Scene BSE::createScene()
{
  Scene scene;
  scene.m_id = m_totalScenes;
  m_totalScenes++;
  return scene;
}
void BSE::setScene(const Scene& scene)
{ 
  m_currentScene = std::make_shared<Scene>(scene); 
}

std::shared_ptr<Entity> BSE::createEntity()
{
  std::shared_ptr<Entity> entity = std::make_shared<Entity>();
  return entity;
}


void BSE::innit(int x, int y, const char *title)
{
  m_win->create(sf::VideoMode(x, y), title);
  m_win->setView(sf::View(sf::FloatRect(0.f, 0.f, m_win->getSize().x, m_win->getSize().y)));

  sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
  m_win->setPosition(sf::Vector2i(desktop.width/2 - m_win->getSize().x/2, desktop.height/2 - m_win->getSize().y/2));


  if (!m_icon.loadFromFile("res/Engine/icon/mascot.png")) {
    // Error loading the icon
  }

  m_win->setIcon(m_icon.getSize().x, m_icon.getSize().y, m_icon.getPixelsPtr());
}


std::shared_ptr<sf::RenderWindow> BSE::getWin()
{
  return m_win;
}











