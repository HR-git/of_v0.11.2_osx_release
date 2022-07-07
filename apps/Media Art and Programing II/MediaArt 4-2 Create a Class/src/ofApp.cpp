#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){ //ofAppクラスの中のsetup関数を記述
    ofSetCircleResolution(64);
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){ //ofAppクラスの中のupdate関数を記述
    particle.update(); //particleオブジェクト(ParticleVec2クラス)のupdate関数を呼び出し
    particle.bounce();
}

//--------------------------------------------------------------
void ofApp::draw(){ //ofAppクラスの中のdraw関数を記述
    ofSetColor(0, 127, 255, 200); //クラスの外で色を変更できるようにofApp::drawに書いてある
    particle.draw();
}
