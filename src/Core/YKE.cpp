#include "Yekate/Core/Input.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <Yekate/Core/YKE.hpp>
#include <iostream>
#include <memory>

namespace Yekate
{

std::shared_ptr<sf::RenderWindow> YKE::m_win = std::make_shared<sf::RenderWindow>();

std::shared_ptr<Scene> YKE::m_currentScene = std::make_shared<Scene>();

sf::Image YKE::m_icon = sf::Image();

int YKE::m_totalScenes = 0;

YKE::YKE(){}

void YKE::innit()
{
  m_win->create(sf::VideoMode(800, 600), "Redward Cullen Engine");

  sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
  m_win->setPosition(sf::Vector2i(desktop.width/2 - m_win->getSize().x/2, desktop.height/2 - m_win->getSize().y/2));


  if (!m_icon.loadFromFile("res/Engine/icon/mascot.png")) {
    // Error loading the icon
  }

  m_win->setIcon(m_icon.getSize().x, m_icon.getSize().y, m_icon.getPixelsPtr());

}

void YKE::run()
{
  sf::Clock clock;
  
  for(const auto& entity: m_currentScene->m_entities)
      {
        entity->start();
      }


  while (m_win->isOpen())
    {
      sf::Event event;
      Time::delta = clock.restart().asSeconds();

      while (m_win->pollEvent(event) )
        {
          if (event.type == sf::Event::Closed|| event.key.code == sf::Keyboard::Escape)
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

Scene YKE::createScene()
{
  Scene scene;
  scene.m_id = m_totalScenes;
  m_totalScenes++;
  return scene;
}
void YKE::setScene(const Scene& scene)
{ 
  m_currentScene = std::make_shared<Scene>(scene); 
}

std::shared_ptr<Entity> YKE::createEntity()
{
  std::shared_ptr<Entity> entity = std::make_shared<Entity>();
  return entity;
}


void YKE::setWindow(unsigned int x, unsigned int y, const char *title)
{
  m_win->setSize(sf::Vector2(x,y));
  //m_win->setView(sf::View(sf::FloatRect(0, 0, m_win->getSize().x, m_win->getSize().y)));
  m_win->setTitle(title);

}


std::shared_ptr<sf::RenderWindow> YKE::getWin()
{
  return m_win;
}

}  








