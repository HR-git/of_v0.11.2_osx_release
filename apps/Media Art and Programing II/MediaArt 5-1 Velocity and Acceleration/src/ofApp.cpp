#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){ //ofAppクラスの中のsetup関数を記述
    ofSetCircleResolution(64);
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){ //ofAppクラスの中のupdate関数を記述
    ParticleVec3 p;
    p.acceleration = glm::vec3(ofRandom(-10, 10), ofRandom(-10, 10), ofRandom(-10, 10)); //一瞬加速度を設定
    p.lifeTime = ofRandom(5, 10); //lifeTimeをランダムに(自然)
//    p.location = glm::vec3(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0); //円が生成される位置をランダムに
    particles.push_back(p);
    for (int i = 0; i < particles.size(); i++) {
        particles[i].update();
        particles[i].bounce();
        if (particles[i].isLive == false) { //particlesがもし死んでいたら削除する
            particles.erase(particles.begin() + i); //particles.begin + i: 先頭から数えてi番目
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){ //ofAppクラスの中のdraw関数を記述
    ofSetColor(0, 127, 255, 200);
    for (int i = 0; i < particles.size(); i++) {
        particles[i].draw();
    }
    ofSetColor(255);
    ofDrawBitmapString("Object Num = " + ofToString(particles.size()), 20, 20);
    
}
