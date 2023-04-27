#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <Yekate/Core/Input.hpp>
#include <iostream>

namespace Yekate{
namespace Input
{
 

bool isKeyHeld(sf::Keyboard::Key key)
{
  return sf::Keyboard::isKeyPressed(key);
}

bool isKeyTapped(sf::Keyboard::Key key)
{
   static bool prevKeyState = false; 
    bool currKeyState = sf::Keyboard::isKeyPressed(key); 

    if (currKeyState && !prevKeyState) {
        prevKeyState = true;  
        return true;
    } else {
        prevKeyState = currKeyState;  
        return false;
    }
  
}


}
}
