#pragma once
#include "ofMain.h"
#include "ofxProcessFFT.h"
#include "ofxGui.h"
#include "ofSoundStream.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    ProcessFFT fft;
    
    ofEasyCam cam;
    ofMaterial material;
    ofLight light;
    ofMesh mesh;
    ofxPanel gui;
    ofxFloatSlider lowSize;
    ofxFloatSlider midSize;
    ofxFloatSlider highSize;
    
//    ofSoundStream soundStream;
//    ofSoundStreamSettings settings;
};

