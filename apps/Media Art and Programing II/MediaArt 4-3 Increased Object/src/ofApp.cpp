#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){ //ofAppクラスの中のsetup関数を記述
    ofSetCircleResolution(64);
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){ //ofAppクラスの中のupdate関数を記述
    ParticleVec2 p; //ParticleVec2クラスのオブジェクトpを作成
    particles.push_back(p);
    for (int i = 0; i < particles.size(); i++) { //全てのparticles配列に関数を呼び出し
        particles[i].update();
        particles[i].bounce();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){ //ofAppクラスの中のdraw関数を記述
    ofSetColor(0, 127, 255, 200);
    for (int i = 0; i < particles.size(); i++) {
        particles[i].draw();
    }
}
