
#include "Sphere.h"

Sphere::Sphere(cVector3d pos, bool stationary)
{
  fixed = stationary;
  point = new cShapeSphere(0.01);
  point->setLocalPos(pos);

}

void Sphere::updateSphere(double time)
{
  cVector3d force(0, 0, 0);

  for (cVector3d f : forcesToBeApplied)
    force += f;

  forcesToBeApplied.clear();

  double cair = 0.5;
  cVector3d Fdamping = -cair * velocity;

  cVector3d acc = (force + Fdamping) / mass;
  
  velocity = velocity + time * acc;
  cVector3d position = point->getLocalPos() + time * velocity;

  point->setLocalPos(position);
}

void Sphere::addForce(cVector3d force)
{
  if (!fixed)
    forcesToBeApplied.push_back(force);
}

cVector3d Sphere::getPosition()
{
  return point->getLocalPos();
}
