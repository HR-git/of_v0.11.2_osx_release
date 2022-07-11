#pragma once

#include "ofMain.h"
#include "ofxGui.h" //Addonを使うときはまずincludeする

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
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
    
        ofxPanel gui; //GUIの土台
        ofxFloatSlider rectSize; //float値を生成するスライダー
        ofxFloatSlider rectSpeed;
        ofxColorSlider rectColor;
        
};
