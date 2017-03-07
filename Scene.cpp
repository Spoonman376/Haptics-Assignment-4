#include "Scene.h"

Scene::Scene()
{
  for (int i = -2; i <= 2; ++i)
  {
    spheres.push_back(vector<Sphere*>());
    for (int j = -2; j <= 2; ++j)
    {
      Sphere* s = new Sphere(cVector3d((double)i * 0.1, (double)j* 0.1, 0), abs(i * j) == 4);
      s->point->m_material->setGrayDarkSlate();
      spheres[i + 2].push_back(s);
    }
  }

  for (int i = 0; i < spheres.size(); ++i)
  {
    for (int j = 0; j < spheres[i].size(); ++j)
    {
      if (j < spheres[i].size() -1)
        springs.push_back(new Spring(spheres[i][j], spheres[i][j + 1], 200));
      
      if (i < spheres.size() - 1)
        springs.push_back(new Spring(spheres[i][j], spheres[i + 1][j], 200));
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
      s->addForce(cVector3d(0, 0, -9.81) * 0.5);
  }

  for (vector<Sphere*> vs : spheres)
  {
    for (Sphere* s : vs)
      s->updateSphere(t);
  }

  return cVector3d(0,0,0);
}
