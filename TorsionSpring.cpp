#include "TorsionSpring.h"

TorsionSpring::TorsionSpring(Sphere* a, Sphere* p, Sphere* b, double stiff)
{
  pointA = a;
  pivot = p;
  pointB = b;

  k = stiff;
}

void TorsionSpring::calculateForces()
{
  cVector3d a = pointA->getPosition();
  cVector3d p = pivot->getPosition();
  cVector3d b = pointB->getPosition();



}


