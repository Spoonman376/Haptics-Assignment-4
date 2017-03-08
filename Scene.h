#ifndef SCENE_H
#define SCENE_H

#include "Spring.h"

class Scene
{
  vector<vector<Sphere*>> spheres;
  vector<Spring*> springs;
  int size = 4;


public:

  Scene();

  void addToWorld(cWorld*);

  cVector3d calculateForces(cVector3d, double);



};




#endif 

