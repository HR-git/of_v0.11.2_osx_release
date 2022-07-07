#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){ //ofAppクラスの中のsetup関数を記述
    ofSetCircleResolution(64);
    ofSetFrameRate(60);
    location = glm::vec2(ofGetWidth() / 2, ofGetHeight()) / 2;
    velocity = glm::vec2(ofRandom(-10, 10), ofRandom(-10, 10));
}

//--------------------------------------------------------------
void ofApp::update(){ //ofAppクラスの中のupdate関数を記述
    location = location + velocity;
    
    if (location.x > ofGetWidth() || location.x < 0) {
        velocity.x = velocity.x * -1;
    }
    if (location.y > ofGetHeight() || location.y < 0) {
        velocity.y = velocity.y * -1;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){ //ofAppクラスの中のdraw関数を記述
    ofSetColor(0, 127, 255, 200);
    ofDrawCircle(location, 10);
}
