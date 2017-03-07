
#ifndef Spring_h
#define Spring_h

#include <stdio.h>
#include "chai3d.h"

class Spring
{
  Sphere* pointA;
  Sphere* pointB;
  double k;
  
public:
  
  Spring(Sphere*, Sphere*, double);
  
  void calculateForces();
  
};


#endif
