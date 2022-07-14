#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    bgColor = ofColor(0);
}

void ofApp::update(){

}

void ofApp::draw(){
    ofBackground(bgColor);
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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
