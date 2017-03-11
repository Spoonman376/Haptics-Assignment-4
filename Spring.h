
#ifndef Spring_h
#define Spring_h

#include <stdio.h>
#include "chai3d.h"
#include "Sphere.h"

class Spring
{
  Sphere* pointA;
  Sphere* pointB;
  double restLength;
  double k;
  double damp; // Ns/m
  
public:
  
  Spring(Sphere*, Sphere*, double, double, double);
  
  cShapeLine* line;

  void calculateForces();
  void updateSpring();
  
};


#endif
