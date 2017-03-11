
#include "Spring.h"


Spring::Spring(Sphere* a, Sphere* b, double rest, double stiffness, double d)
{
  pointA = a;
  pointB = b;
  restLength = rest;
  k = stiffness;
  damp = d;
  
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

  pointA->addForce(force - damp * pointA->velocity);
  pointB->addForce(-force - damp * pointA->velocity);
}

void Spring::updateSpring()
{
  line->m_pointA = pointA->getPosition();
  line->m_pointB = pointB->getPosition();
}


