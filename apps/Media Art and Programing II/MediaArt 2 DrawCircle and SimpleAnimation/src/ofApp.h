#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
        float locationX; //ofApp全体で使用する変数は、ヘッダファイルに記述する
        float locationY;
};
