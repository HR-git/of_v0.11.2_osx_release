#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    bgColor = ofColor(0);
    circleColor = ofColor(255);
    curPos = glm::vec2(ofGetWidth()/2, ofGetHeight()/2);
    velocity = glm::vec2(0, 0);//速度をリセット
    stiffness = 0.05; //バネ定数
    friction = 0.95; //摩擦
    mass = 1.0; //質量
}

void ofApp::update(){
    toPos = glm::vec2(mouseX, mouseY);
    glm::vec2 force = stiffness * (toPos - curPos); //バネ定数 x バネの伸びたながさ = バネにかかっている力
    glm::vec2 accel = force / mass; // f = ma
    velocity = velocity + accel; //次のフレームでの速度
    velocity = velocity * friction; //摩擦力をかける
    curPos += velocity; //次の位置
}

void ofApp::draw(){
    ofBackground(bgColor);
    ofSetColor(circleColor);
    ofDrawCircle(curPos, 40);
    ofSetColor(190);
    ofDrawLine(curPos, toPos); //バネとのラインを引く
}

void ofApp::keyPressed(int key){
    if (key == 'r') {
    bgColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255)); //キーを押すと画面の色を変更
    }
    if (key == 'f') {
        ofToggleFullscreen();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    bgColor = ofColor(0); //キーを放すと画面が黒
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    circleColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    circleColor = ofColor(255);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
