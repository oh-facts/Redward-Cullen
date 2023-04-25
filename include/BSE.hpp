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


  template<typename T, typename...T_Args>
  static std::shared_ptr<T> createComponent(T_Args && ... args);
};

template<typename T, typename...T_Args>
std::shared_ptr<T> BSE::createComponent(T_Args && ... args) {
    return std::make_shared<T>(std::forward<T_Args>(args)...);
}


#endif // !DEBUG
