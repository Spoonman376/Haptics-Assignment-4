
#ifndef Spring_h
#define Spring_h

#include <stdio.h>
#include "chai3d.h"
#include "Sphere.h"

class Spring
{
  Sphere* pointA;
  Sphere* pointB;
  double k;
  
public:
  
  Spring(Sphere*, Sphere*, double);
  
  cShapeLine* line;

  void calculateForces();
  
};


#endif
