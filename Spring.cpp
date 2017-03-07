
#include "Spring.h"


Spring::Spring(Sphere* a, Sphere* b, double stiffness)
{
  pointA = a;
  pointB = b;
  k = stiffness;
}


void Spring::calculateForces()
{
  cVector3d a = pointA->getPosition();
  cVector3d b = pointB->getPosition();
  
  cVector3d force(0,0,0);
  
  pointA->addForce(force);
  pointB->addForce(-force);
}


