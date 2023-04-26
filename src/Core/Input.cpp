#include <Yekate/Core/Input.hpp>

namespace Yekate{
bool isKeyHeld(sf::Keyboard::Key key)
{
	return sf::Keyboard::isKeyPressed(key);
}
}
