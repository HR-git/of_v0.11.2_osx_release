#pragma once

#include "ofMain.h"
#include "ofxProcessFft.h"
#include "ofxGui.h" //include

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void resolutionChanged(int & resolution); //関数を作成

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
    
        ProcessFFT fft; //FFT分析
        ofImage lowNoiseImg; //ノイズ画像低域
        ofImage midNoiseImg; //ノイズ画像中域
        ofImage highNoiseImg; //ノイズ画像高域
    
        ofxPanel gui; //GUI
        ofxFloatSlider level;
        ofxIntSlider resolution;
        ofxFloatSlider noiseFrequency;
};
