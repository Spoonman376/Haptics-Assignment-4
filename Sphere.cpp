
#include "Sphere.h"

Sphere::Sphere(cVector3d pos, double r, bool stationary)
{
  fixed = stationary;
  radius = r;
  point = new cShapeSphere(radius);
  point->setLocalPos(pos);

}

void Sphere::updateSphere(double time)
{
  cVector3d force(0, 0, 0);

  for (cVector3d f : forcesToBeApplied)
    force += f;

  forcesToBeApplied.clear();

  double cair = 1;
  cVector3d Fdamping = -cair * velocity;

  cVector3d acc = (force + Fdamping) / mass;
  
  velocity = velocity + time * acc;
  cVector3d position = point->getLocalPos() + time * velocity;

  point->setLocalPos(position);
}

cVector3d Sphere::calculateForces(cVector3d cursorPos, double cursorRadius)
{
  cVector3d force(0, 0, 0);
  cVector3d pos = getPosition();

  cVector3d dist = cursorPos - pos;
  double d = - dist.length() + (radius + cursorRadius);

  if (d > 0)
  {
    dist.normalize();
    force = dist * d * -k;
    addForce(force);
  }

  return -force;
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
