#pragma once

#include "ofMain.h"
#include "ofxPhyllotaxis.h"
#include "ofxPanel.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void maybeDrawGui();

    int nCubes = 400;
    bool hideGui = false;
    ofFloatColor masterColor;
    ofFloatColor secondColor;
    ofMaterial secondMaterial;
    ofEasyCam camera;
    ofLight light;
    vector<ofBoxPrimitive> children;
    string selectedType = "simple";

    ofxPanel gui;
    ofxFloatSlider degree;
    ofxFloatSlider spread;
    ofxFloatSlider extrude;
};
