#pragma once

#include "ofMain.h"
#include "ParticleVec2.h" //ParticleVec2クラスを読み込めるようにする

class ofApp : public ofBaseApp{ //ofAppクラスを作成している

	public:
		void setup();
		void update();
		void draw();
    
        vector<ParticleVec2> particles; //ParticleVec2の可変長配列を作成
};
