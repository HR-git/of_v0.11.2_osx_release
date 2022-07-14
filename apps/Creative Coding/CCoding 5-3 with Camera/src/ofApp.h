#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        //メッシュの解像度
        int meshWidth;
        int meshHeight;
        int num_particles;
    
        ofEasyCam cam;
        ofLight light;
        ofVboMesh mesh;
        ofVideoGrabber myVideo;
};
