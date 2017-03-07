#ifndef SCENE_H
#define SCENE_H

#include "Spring.h"

class Scene
{
  vector<vector<Sphere*>> spheres;
  vector<Spring*> springs;

public:

  Scene();

  void addToWorld(cWorld*);

  cVector3d calculateForces(cVector3d, double);



};




#endif 

