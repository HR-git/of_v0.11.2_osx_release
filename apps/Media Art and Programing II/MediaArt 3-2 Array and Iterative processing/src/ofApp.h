#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
        static const int NUM = 100; //ヘッダファイルでint NUMを初期化とすることは出来ない > static constをつけると定数という扱いになり可能
        glm::vec2 location[NUM]; //位置ベクトル (glmライブラリのvec2型)
        glm::vec2 velocity[NUM]; //速度ベクトル
};
