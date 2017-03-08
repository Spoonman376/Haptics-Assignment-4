
#ifndef Sphere_h
#define Sphere_h

#include <stdio.h>
#include "chai3d.h"
#include <vector>



using namespace chai3d;
using namespace std;

class Sphere 
{

  cVector3d velocity = cVector3d(0,0,0); // m/s
  
  // Is the sphere capable of moving
  bool fixed;
  
  vector<cVector3d> forcesToBeApplied;
  //vector<Spring*> springsAttached;
  
public:

  // graphical component of the sphere
  cShapeSphere* point;
  double mass = 0.001; // Kg


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
