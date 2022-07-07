#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
        //位置と速度の可変長配列(vector)を定義
        vector<glm::vec2> location;
        vector<glm::vec2> velocity;
        static const int MAX = 100; //描画される上限の数
};
