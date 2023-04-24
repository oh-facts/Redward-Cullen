#ifndef BSE_HPP
#define BSE_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <Scene.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
class BSE{
private:
  static sf::Image m_icon;
  static std::shared_ptr<sf::RenderWindow> m_win;
  static std::shared_ptr<Scene> m_currentScene;
  static int m_totalScenes;
  BSE();
public:
  static void innit();
  static void innit(int x, int y, const char*);
  static void run();
  static Scene createScene();
  static void setScene(const Scene&);
  static std::shared_ptr<Entity> createEntity();
  static std::shared_ptr<sf::RenderWindow> getWin();


  template<typename T>
  static std::shared_ptr<T> createComponent();
};

template <typename T>
std::shared_ptr<T> BSE::createComponent()
{
  std::shared_ptr<T> comp = std::make_shared<T>();
  return comp;
}

#endif // !DEBUG
