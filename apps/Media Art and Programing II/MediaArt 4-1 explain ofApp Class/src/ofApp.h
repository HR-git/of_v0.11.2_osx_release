#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{ //ofAppクラスを作成している

	public:
		void setup();
		void update();
		void draw();
		
        glm::vec2 location;
        glm::vec2 velocity;
};
