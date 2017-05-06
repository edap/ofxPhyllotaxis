#pragma once
#include "ofMain.h"

class ofxPhyllotaxis{
public:
	 static ofVec3f simple(const int i, const float angleInRadians,
                         const float spread){
       float currentAngle = i * angleInRadians;
       float radius = spread * sqrt(i);
       float x = radius * cos(currentAngle);
       float z = radius * sin(currentAngle);
       return ofVec3f(x,0.0,z);
	 }

	  static ofVec3f conical(const int i, const float angleInRadians,
                           const float spread, const float extrude){
         float currentAngle = i * angleInRadians;
         float radius = spread * sqrt(i);
         float x = radius * cos(currentAngle);
         float z = radius * sin(currentAngle);
         float y = i * (extrude) * -1;
         return ofVec3f(x,y,z);
	  }

    static ofVec3f apple(const int i, const float angleInRadians,
                         const float spread, const int total){
        float inc = PI / float(total);
        float currentAngleA = i * inc;
        float currentAngleB = i * angleInRadians;
        float radius = spread * sqrt(i);
        float x = radius * sin(currentAngleA) * cos(currentAngleB);
        float z = radius * sin(currentAngleA) * sin(currentAngleB);
        float y = radius * cos(currentAngleA);
        return ofVec3f(x,y,z);
    }
};
