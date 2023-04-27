#ifndef YKE_HPP
#define YKE_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <Yekate/Core/Scene.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <Yekate/Utility/Time.hpp>
#include <Yekate/Core/Input.hpp>

namespace Yekate
{

class YKE{
private:
  static sf::Image m_icon;
  static std::shared_ptr<sf::RenderWindow> m_win;
  static std::shared_ptr<Scene> m_currentScene;
  static int m_totalScenes;
  YKE();
public:
  static void innit();
  static void setWindow(unsigned int x, unsigned int y, const char*);
  static void run();
  static Scene createScene();
  static void setScene(const Scene&);
  static std::shared_ptr<Entity> createEntity();
  static std::shared_ptr<sf::RenderWindow> getWin();


  template<typename T, typename...T_Args>
  static std::shared_ptr<T> createComponent(T_Args && ... args);
};

template<typename T, typename...T_Args>
std::shared_ptr<T> YKE::createComponent(T_Args && ... args) {
  return std::make_shared<T>(std::forward<T_Args>(args)...);
}
}



#endif // !DEBUG
