#ifndef INPUT_HPP

#define INPUT_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace Yekate
{
namespace Input
{

bool isKeyHeld(sf::Keyboard::Key key);
bool isKeyTapped(sf::Keyboard::Key key);
}
}
#endif 
