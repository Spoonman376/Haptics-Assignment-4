#ifndef TORSIONSPRING_H
#define TORSIONSPRING_H


#include "Sphere.h"


class TorsionSpring
{
  Sphere* pointA;
  Sphere* pointB;
  Sphere* pivot;
  double k;

public:

  TorsionSpring(Sphere*, Sphere*, Sphere*, double);

  cShapeLine* lineA;
  cShapeLine* lineB;

  void calculateForces();





};






#endif // !TORSIONSPRING_H

