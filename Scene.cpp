#include "Scene.h"

Scene::Scene()
{  
  for (int i = -size; i <= size; ++i)
  {
    spheres.push_back(vector<Sphere*>());
    for (int j = -size; j <= size; ++j)
    {
      Sphere* s = new Sphere(cVector3d((double)i * 0.075, (double)j* 0.075, 0), 
        abs(i*j) == size *size);
        //abs(i) == size || abs(j) == size);
      s->point->m_material->setGrayDarkSlate();
      spheres[i + size].push_back(s);
    }
  }

  for (int i = 0; i < spheres.size(); ++i)
  {
    for (int j = 0; j < spheres[i].size(); ++j)
    {
      double s = 1;
      if (i == 0 || i == spheres.size() - 2)
        s += 2;

      if (j == 0 || j == spheres[i].size() - 2)
        s += 2;

      
      if (j < spheres[i].size() -1)
        springs.push_back(new Spring(spheres[i][j], spheres[i][j + 1], 10 * s));
      
      if (i < spheres.size() - 1)
        springs.push_back(new Spring(spheres[i][j], spheres[i + 1][j], 10 * s));
    }
  }
}

void Scene::addToWorld(cWorld* world)
{
  for (vector<Sphere*> vs : spheres)
  {
    for (Sphere* s : vs)
      world->addChild(s->point);
  }
  for (Spring* s : springs)
    world->addChild(s->line);

}

cVector3d Scene::calculateForces(cVector3d toolPos, double t)
{
  for (Spring* s : springs)
    s->calculateForces();

  for (vector<Sphere*> vs : spheres)
  {
    for (Sphere* s : vs)
      s->addForce(cVector3d(0, 0, -9.81) * s->mass);
  }

  for (vector<Sphere*> vs : spheres)
  {
    for (Sphere* s : vs)
      s->updateSphere(t);
  }

  return cVector3d(0,0,0);
}
