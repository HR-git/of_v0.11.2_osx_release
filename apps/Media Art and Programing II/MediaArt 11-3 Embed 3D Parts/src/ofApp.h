#pragma once

#include "ofMain.h"
#include "ofxFaceTracker2.h" //include

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();

    ofxFaceTracker2 tracker; //addons
    ofVideoGrabber grabber; //標準クラス
    ofLight light;
};
