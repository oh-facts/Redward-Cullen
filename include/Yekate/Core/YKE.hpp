#ifndef YKE_HPP
#define YKE_HPP

#include "Yekate/Core/Window.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <Yekate/Core/Scene.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <Yekate/Utility/Time.hpp>
#include <Yekate/Core/Input.hpp>
#include <mutex>

namespace Yekate
{

class YKE{
public:
  static void innit();
  static void run();
  
  static Scene createScene();
  static void setScene(const Scene&);
  
  static void toggleFullscreen();


private:
  static Scene m_currentScene;
  static int m_totalScenes;
  static Window m_window; 
  static void renderingThread();
  static std::atomic<bool> lockRenderThread;
  static std::mutex mut;
  YKE();
};

}



#endif // !DEBUG
