// ofxFaceTrack2 example: SIMPLE EXAMPLE
//
// This example shows minimal usage of the ofxFaceTracker2 addon,
// doing simple landmark detection and pose estimation
//

#pragma once

#include "ofMain.h"
#include "ofxFaceTracker2.h" //include

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    ofxFaceTracker2 tracker; //addons
    ofVideoGrabber grabber; //クラス
};
