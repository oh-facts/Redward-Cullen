#include "Yekate/Core/Component.hpp"
#include "Yekate/EC/Components/SpriteRenderer.hpp"
#include "Yekate/EC/Components/Transform.hpp"
#include "Yekate/Utility/Time.hpp"
#include <SFML/System/Vector2.hpp>
#include <Yekate.hpp>
#include <iostream>

using namespace Yekate;

sf::Vector2f normalize(sf::Vector2f vec)
{
  float length = std::sqrt(vec.x * vec.x + vec.y * vec.y);
  if (length != 0)
    return sf::Vector2f(vec.x / length, vec.y / length);
  return vec;
}

class freeMove : public Component
  {
  public:
    const float speed = 300;
    sf::Vector2f move_input;
    Transform& m_trans;

    freeMove(Entity& en):Component(en), m_trans (en.getComponent<Transform>())
    {
    }
    
    void update() override{

      move_input = sf::Vector2f(0,0);

      if(Input::isKeyHeld(sf::Keyboard::A)){
        move_input.x = -1;
      }
      if(Input::isKeyHeld(sf::Keyboard::D)){
        move_input.x = 1;
      }
      if(Input::isKeyHeld(sf::Keyboard::W)){
        move_input.y = -1;
      }
      if(Input::isKeyHeld(sf::Keyboard::S)){
        move_input.y = 1;
      }
      move_input = normalize(move_input); 
      m_trans.move(speed*Time::delta*move_input);
    }

  };

int main()
{
  YKE::innit();

  Entity player("player");
  player.addComponent<Transform>();
  
  sf::Vector2f py_box_size(40,20);
  
  player.addComponent<freeMove>();
  player.addComponent<BoxCollider>(py_box_size);
  auto sprite = player.addComponent<SpriteRenderer>("res/Sandbox/airplane.png");
  sprite->layer = 10;
  player.addComponent<Camera>();


  auto scene = YKE::createScene();
  scene.addEntity(player);
  


  sf::Vector2f objectPos(400,100);
  sf::Vector2f objectScale(0.5,0.5);
  Entity debugObject("debug obj");
  debugObject.addComponent<Transform>(objectPos);
  auto spriteD = debugObject.addComponent<SpriteRenderer>("res/Sandbox/mascot.png",objectScale);
  spriteD->layer = 0;

  scene.addEntity(debugObject);

  sf::Vector2f towerPos(90,40);
  sf::Vector2f towerSize(40,40);
  Entity tower("tower");
  tower.addComponent<Transform>(towerPos);
  tower.addComponent<BoxCollider>(towerSize);
  
  scene.addEntity(tower);


  YKE::setScene(scene);
  YKE::run();

  return 0;
}

