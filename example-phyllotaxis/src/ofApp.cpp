#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(37, 203, 206);
    gui.setup();
    gui.setPosition(5, 40);
    gui.add(degree.setup("degree", 137.5, 130.00, 140.00));
    gui.add(spread.setup("spread", 11, 2, 40));
    gui.add(extrude.setup("extrude", 0.3, 0.01, 0.90));
    light.setup();
    light.setPosition(-100, 200,0);
    masterColor = ofFloatColor::red;
    secondColor = ofFloatColor::yellow;
    ofEnableDepthTest();
    for(int i = 0;  i < nCubes;i++){
        children.push_back(ofBoxPrimitive(5,5,5));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    float rad = ofDegToRad(degree);
    for (int i = 0;  i < nCubes;i++) {
        glm::vec3 pos;
        if (selectedType == "simple") {
            pos = ofxPhyllotaxis::simple(i, rad, spread);
        }

        if (selectedType == "conical") {
            pos = ofxPhyllotaxis::conical(i, rad, spread, extrude);
        }

        if (selectedType == "apple") {
            pos = ofxPhyllotaxis::apple(i, rad, spread, nCubes);
        }
        children[i].setPosition(pos);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    maybeDrawGui();
    camera.begin();

    secondMaterial.setEmissiveColor(masterColor);
    for (int i = 0;  i < nCubes;i++) {
        float lerp = ofMap(i, 0, nCubes, 0.0, 1.0);
        auto interpolatedColor = masterColor.getLerped(secondColor, lerp);
        secondMaterial.setEmissiveColor(interpolatedColor);
        secondMaterial.begin();
        children[i].draw();
        secondMaterial.end();
    }
    camera.end();
}

void ofApp::maybeDrawGui(){
    if(!hideGui){
        ofDisableDepthTest();
        gui.draw();
        ofPushStyle();
        string displayGui = "press 'g' to toggle the gui, up and down to change presets";
        ofDrawBitmapString(displayGui, 5, 10);
        string types = "press 1, 2, 3 to try different implementation";
        ofDrawBitmapString(types, 5, 20);
        string currentType = "current: "+ selectedType;
        ofDrawBitmapString(currentType, 5, 30);
        ofPopStyle();
        ofEnableDepthTest();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    switch(key){
        case 'g':
            hideGui = !hideGui;
            break;
        case 49:
            selectedType = "conical";
            break;
        case 50:
            selectedType = "apple";
            break;
        case 51:
            selectedType = "simple";
            break;
        default:
            break;
    }
}

