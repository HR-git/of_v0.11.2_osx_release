#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
        glm::vec2 location; //位置ベクトル (glmライブラリのvec2型)
        glm::vec2 velocity; //速度ベクトル
};
