#pragma once

#include "ofMain.h"
#include "ofxProcessFFT.h"
#include "ofxGui.h"
#include "ofxGLSLSimplexNoise.h"
#include "ofSoundStream.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ProcessFFT fft;
    ofxGLSLSimplexNoise noise;
    
    ofxPanel gui;
    ofxFloatSlider level;
    ofxFloatSlider noiseFrequency;
    ofxFloatSlider noiseSpeed;
    bool showGui;
    
    ofSoundStream soundStream;
    ofSoundStreamSettings settings;
};

