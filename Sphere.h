
#ifndef Sphere_h
#define Sphere_h

#include <stdio.h>
#include "chai3d.h"
#include "<vector>"



using namespace chai3d;

class {
  cShapeSphere point;
  
  // Is the sphere capable of moving
  bool fixed;
  
  vector<cVector3d> forcesToBeApplied;
  //vector<Spring*> springsAttached;
  
public:
  
  Sphere(cVector3d, bool stationary = false);
  
  // Goes through the list of calculated forces and applies them to the sphere
  void updateSphere(double);
  
  // Given the cursor position will calculate the forces to be applied to the sphere
  // Will return force applied back to the cursor
  cVector3d calculateForces(cVector3d cursorPos);
  void addForce(cVector3d);
  bool isFixed();
  cVector3d getPosition();
  
};




#endif
