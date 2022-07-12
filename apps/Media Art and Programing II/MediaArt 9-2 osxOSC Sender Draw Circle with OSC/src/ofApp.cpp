#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    sender.setup("127.0.0.1", 8000); //どこに向けて送るか
}

void ofApp::update(){
    ofxOscMessage msg; //ofxOsc型のオブジェクトを作成
    msg.setAddress("/mouse/position"); //アドレスを指定
    msg.addIntArg(mouseX); //マウス座標を値として送信
    msg.addIntArg(mouseY);
    sender.sendMessage(msg); //メッセージを送信
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawCircle(mouseX, mouseY, 40);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
