
#ifndef Sphere_h
#define Sphere_h

#include <stdio.h>
#include "chai3d.h"
#include <vector>



using namespace chai3d;
using namespace std;

class Sphere 
{

  
  // Is the sphere capable of moving
  bool fixed;
  double radius = 0.015;
  double k = 1000.0;
  
  vector<cVector3d> forcesToBeApplied;
  
public:

  // graphical component of the sphere
  cShapeSphere* point;
  double mass = 1; // Kg
  cVector3d velocity = cVector3d(0,0,0); // m/s


  Sphere(cVector3d, double, bool stationary = false);
  
  // Goes through the list of calculated forces and applies them to the sphere
  void updateSphere(double);
  
  // Given the cursor position will calculate the forces to be applied to the sphere
  // Will return force applied back to the cursor
  cVector3d calculateForces(cVector3d cursorPos, double cursorRadius);
  void addForce(cVector3d);
  cVector3d getPosition();
  
};




#endif
