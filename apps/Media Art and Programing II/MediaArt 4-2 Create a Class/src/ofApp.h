#pragma once

#include "ofMain.h"
#include "ParticleVec2.h" //ParticleVec2クラスを読み込めるようにする

class ofApp : public ofBaseApp{ //ofAppクラスを作成している

	public:
		void setup();
		void update();
		void draw();
    
        ParticleVec2 particle; //ParticleVec2クラスをインスタンス化(C++では全ての変数はクラスとオブジェクトでできているので変数の定義に似ている)
};
