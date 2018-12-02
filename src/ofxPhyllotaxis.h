#pragma once
#include "ofMain.h"

class ofxPhyllotaxis{
    public:
    static glm::vec3 simple(const int i, const float angleInRadians,
                          const float spread){
        float currentAngle = i * angleInRadians;
        float radius = spread * sqrt(i);
        float x = radius * cos(currentAngle);
        float z = radius * sin(currentAngle);
        return glm::vec3(x,0.0,z);
    }

    static glm::vec3 conical(const int i, const float angleInRadians,
                           const float spread, const float extrude){
        float currentAngle = i * angleInRadians;
        float radius = spread * sqrt(i);
        float x = radius * cos(currentAngle);
        float z = radius * sin(currentAngle);
        float y = i * (extrude) * -1;
        return glm::vec3(x,y,z);
    }

    static glm::vec3 apple(const int i, const float angleInRadians,
                         const float spread, const int total){
        float inc = PI / float(total);
        float currentAngleA = i * inc;
        float currentAngleB = i * angleInRadians;
        float radius = spread * sqrt(i);
        float x = radius * sin(currentAngleA) * cos(currentAngleB);
        float z = radius * sin(currentAngleA) * sin(currentAngleB);
        float y = radius * cos(currentAngleA);
        return glm::vec3(x,y,z);
    }
};
