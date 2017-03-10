
#include "Spring.h"


Spring::Spring(Sphere* a, Sphere* b, double rest, double stiffness)
{
  pointA = a;
  pointB = b;
  restLength = rest;
  k = stiffness;
  
  line = new cShapeLine(pointA->getPosition(), pointB->getPosition());
  line->m_material->setYellow();
}


void Spring::calculateForces()
{
  cVector3d a = pointA->getPosition();
  cVector3d b = pointB->getPosition();

  cVector3d forceD = a - b;
  forceD.normalize();
  double forceL = (a - b).length() - restLength;


  cVector3d force = -k * forceD * forceL;

  pointA->addForce(force);
  pointB->addForce(-force);
}

void Spring::updateSpring()
{
  line->m_pointA = pointA->getPosition();
  line->m_pointB = pointB->getPosition();
}


