#include "Yekate/Core/Entity.hpp"
#include "Yekate/Core/Input.hpp"
#include "Yekate/Core/Physics.hpp"
#include "Yekate/EC/Components/SpriteRenderer.hpp"
#include <SFML/System/Thread.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <Yekate/Core/YKE.hpp>
#include <algorithm>
#include <iostream>
#include <memory>
#include <mutex>

namespace Yekate
{

std::shared_ptr<sf::RenderWindow> YKE::m_win = std::make_shared<sf::RenderWindow>();

std::shared_ptr<Scene> YKE::m_currentScene = std::make_shared<Scene>();

sf::Image YKE::m_icon = sf::Image();

int YKE::m_totalScenes = 0;

std::atomic<bool> YKE::lockRenderThread(false);
std::mutex YKE::mut;


YKE::YKE(){}

void YKE::innit()
{
  m_win->create(sf::VideoMode(1280, 720), "Yekate2D");

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

  Physics physEngine;

  m_win->setActive(false);

  sf::Thread thread(&renderingThread);
  thread.launch();

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
          else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter && event.key.alt)
            {
              mut.lock();
              lockRenderThread = true;
              m_win->setActive(true);
              // Toggle fullscreen mode on alt+enter
              if (m_win->isOpen() && m_win->hasFocus())
              {
                if (m_win->getSize() == sf::Vector2u(sf::VideoMode::getDesktopMode().width,sf::VideoMode::getDesktopMode().height))
                {
                  m_win->create(sf::VideoMode(1280, 720), "Yekate2D", sf::Style::Titlebar | sf::Style::Close);
                }
              else
                {
                  m_win->create(sf::VideoMode::getDesktopMode(), "Window Title", sf::Style::Fullscreen);
                }

                m_win->setActive(false);
                lockRenderThread = false;
                mut.unlock();
              }
            }
        }

      physEngine.update(m_currentScene->m_entities);

      for(const auto& entity: m_currentScene->m_entities)
      {  
        entity->update();
      }

    }

}
bool compareEntitiesByLayer(const std::shared_ptr<Yekate::Entity> a, const std::shared_ptr<Yekate::Entity> b ) {
    auto spriteA = a->getComponent<SpriteRenderer>();
    auto spriteB = b->getComponent<SpriteRenderer>();
    if(spriteA && spriteB )
  {
    return spriteA->layer < spriteB->layer;
  }

    return false;
}
void YKE::renderingThread()
{
  m_win->setActive(true);


 std::sort(m_currentScene->m_entities.begin(), m_currentScene->m_entities.end(), compareEntitiesByLayer);

  while (m_win->isOpen())
    {
      mut.lock();
      if(!lockRenderThread)
      {
        m_win->setActive(true);  

        m_win->clear();


        for(const auto& entity: m_currentScene->m_entities)
        {
          entity->render();
        }

        m_win->display();
      }
    else
      {
        m_win->setActive(false);
      }
      mut.unlock();
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








