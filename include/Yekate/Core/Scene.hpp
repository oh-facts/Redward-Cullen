#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <Yekate/Core/Entity.hpp>
#include <memory>

namespace Yekate
{
class Scene{
public:
  int m_id;

  Scene(){};

  std::vector<std::shared_ptr<Entity>> m_entities;
  std::vector<std::shared_ptr<Entity>> m_entitiesR;
  std::vector<std::shared_ptr<Entity>> m_entitiesP;

  void addEntity(Entity&);
  void reset();
  ~Scene(){};
};
}

#endif // !DEBUG
