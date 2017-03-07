
#include "Spring.h"


Spring::Spring(Sphere* a, Sphere* b, double stiffness)
{
  pointA = a;
  pointB = b;
  k = stiffness;
  
  line = new cShapeLine(pointA->point, pointB->point);
  line->m_material->setYellow();
}


void Spring::calculateForces()
{
  cVector3d a = pointA->getPosition();
  cVector3d b = pointB->getPosition();
  
  cVector3d force = -k * (a - b);

  pointA->addForce(force);
  pointB->addForce(-force);
}


