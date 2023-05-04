#include "Yekate/Core/Entity.hpp"
#include "Yekate/Core/Input.hpp"
#include "Yekate/Core/Physics.hpp"
#include "Yekate/Core/Window.hpp"
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

std::shared_ptr<Scene> YKE::m_currentScene = std::make_shared<Scene>();

int YKE::m_totalScenes = 0;

std::atomic<bool> YKE::lockRenderThread(false);
std::mutex YKE::mut;

Window YKE::m_window = Window();

YKE::YKE(){}

void YKE::innit()
{
  m_window.create(1280,720,"Yekate");
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
void YKE::run()
{
  sf::Clock clock;

  Physics physEngine;

  //std::sort(m_currentScene->m_entitiesR.begin(), m_currentScene->m_entitiesR.end(), compareEntitiesByLayer);
  m_window.setActive(false);

  sf::Thread thread(&renderingThread);
  thread.launch();

  for(const auto& entity: m_currentScene->m_entities)
  {
    entity->start();
  }

  while (m_window.isOpen())
    {
      sf::Event event;
      Time::delta = clock.restart().asSeconds();

      while (m_window.poll(event) )
        {
          if (event.type == sf::Event::Closed|| event.key.code == sf::Keyboard::Escape)
            m_window.close();
          else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter && event.key.alt)
            {
              mut.lock();
              lockRenderThread = true;

              m_window.setActive(true);
              m_window.toggleFullScreen();
              m_window.setActive(false);

              lockRenderThread = false;
              mut.unlock();
            }
        }
      physEngine.update(m_currentScene->m_entitiesP);

      for(const auto& entity: m_currentScene->m_entities)
      {  
        entity->update();
      }
    }


}



void YKE::renderingThread()
{
  m_window.setActive(true);



  while (m_window.isOpen())
    {
      mut.lock();
      if(!lockRenderThread)
      {
        m_window.setActive(true);  

        m_window.clear();


        for(const auto& entity: m_currentScene->m_entities)
        {
          entity->render(m_window);
        }

        m_window.display();
      }
    else
      {
        m_window.setActive(false);
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

std::shared_ptr<Entity> YKE::createEntity(const char* name)
{
  std::shared_ptr<Entity> entity = std::make_shared<Entity>();
  entity->m_name = name;
  return entity;

}

}



