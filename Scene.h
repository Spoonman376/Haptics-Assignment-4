#ifndef SCENE_H
#define SCENE_H

#include "Spring.h"

class Scene
{
  vector<vector<Sphere*>> spheres;
  vector<Spring*> springs;

public:

  void Scene1();
  void Scene2();

  void addToWorld(cWorld*);

  cVector3d calculateForces(cVector3d, double, double);



};




#endif 

