#include "Scene.h"

void Scene::Scene1()
{  
  int size = 4;
  double sphereDistance = 0.01;
  double radius = 0.015;
  gravityMultiplier = 0.01;

  for (int i = -size; i <= size; ++i)
  {
    spheres.push_back(vector<Sphere*>());
    for (int j = -size; j <= size; ++j)
    {
      Sphere* s = new Sphere(cVector3d((double)i * sphereDistance, (double)j* sphereDistance, 0), radius,
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
      double s = 1.0;


      if (j < spheres[i].size() -1)
        springs.push_back(new Spring(spheres[i][j], spheres[i][j + 1], sphereDistance, 4000, 0));
      
      if (i < spheres.size() - 1)
        springs.push_back(new Spring(spheres[i][j], spheres[i + 1][j], sphereDistance, 4000, 0));
    }
  }
}

void Scene::Scene2()
{
  gravityMultiplier = 1;

  spheres.push_back(vector<Sphere*>());
  spheres[0].push_back(new Sphere(cVector3d(0, -0.04, 0), 0.01));
  spheres[0][0]->mass = 0.2;
  spheres[0].push_back(new Sphere(cVector3d(0, -0.04, 0.05), 0.001, true));
  springs.push_back(new Spring(spheres[0][0], spheres[0][1], 0.05, 400.0, 10));

  spheres.push_back(vector<Sphere*>());
  spheres[1].push_back(new Sphere(cVector3d(0, -0.015, 0), 0.01));
  spheres[1][0]->mass = 2.0;
  spheres[1].push_back(new Sphere(cVector3d(0, -0.015, 0.05), 0.001, true));
  springs.push_back(new Spring(spheres[1][0], spheres[1][1], 0.05, 4000.0, 100));


  spheres.push_back(vector<Sphere*>());
  spheres[2].push_back(new Sphere(cVector3d(0, 0.015, 0), 0.01));
  spheres[2][0]->mass = 0.5;
  spheres[2].push_back(new Sphere(cVector3d(0, 0.015, 0.05), 0.001, true));
  springs.push_back(new Spring(spheres[2][0], spheres[2][1], 0.05, 200, 1));

  spheres.push_back(vector<Sphere*>());
  spheres[3].push_back(new Sphere(cVector3d(0, 0.04, 0), 0.01));
  spheres[3][0]->mass = 0.5;
  spheres[3].push_back(new Sphere(cVector3d(0, 0.04, 0.05), 0.001, true));
  springs.push_back(new Spring(spheres[3][0], spheres[3][1], 0.05, 200, 25));


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

cVector3d Scene::calculateForces(cVector3d toolPos, double cursorRadius, double t)
{
  cVector3d force(0, 0, 0);

  
  for (Spring* s : springs)
    s->calculateForces();

  for (vector<Sphere*> vs : spheres)
  {
    for (Sphere* s : vs)
    {
      s->addForce(cVector3d(0, 0, -9.81) * s->mass * gravityMultiplier);
      force += s->calculateForces(toolPos, cursorRadius);
    }
  }

  for (vector<Sphere*> vs : spheres)
  {
    for (Sphere* s : vs)
      s->updateSphere(t);
  }
  for (Spring* s : springs)
    s->updateSpring();

  return force;
}
