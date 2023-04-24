#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <Entity.hpp>
#include <memory>
class Scene{
public:
  int m_id;

  Scene(){};

  std::vector<std::shared_ptr<Entity>> m_entities;
  void addEntity(std::shared_ptr<Entity>);
  ~Scene(){};
};

#endif // !DEBUG
