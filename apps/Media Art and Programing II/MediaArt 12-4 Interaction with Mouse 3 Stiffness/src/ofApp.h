#pragma once

#include "ofMain.h"

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
		
        ofColor bgColor;
        ofColor circleColor;
        glm::vec2 curPos; //現在の円の位置
        glm::vec2 toPos; //目標の位置
        glm::vec2 velocity;//速度
        float stiffness;//バネ定数
        float friction;//摩擦力
        float mass;//質量
};
