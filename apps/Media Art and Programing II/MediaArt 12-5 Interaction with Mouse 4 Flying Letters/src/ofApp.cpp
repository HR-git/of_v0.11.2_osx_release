#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    bgColor = ofColor(0);
    circleColor = ofColor(255);
}

void ofApp::update(){
    glm::vec2 pos = glm::vec2(mouseX, mouseY); //マウスが移動するたびにその場所を可変長配列に追加していく
    mousePos.push_back(pos);
    if (mousePos.size() > 60) {  //ある程度長くなったら先頭の要素だけ削除する
        mousePos.erase(mousePos.begin());
    }
}

void ofApp::draw(){
    ofBackground(bgColor);
    ofSetColor(circleColor);
    for (int i = 0; i < mousePos.size(); i += 10) { //一定間隔で飛ばしながら描く
        ofDrawCircle(mousePos[i].x + i * 6, mousePos[i].y, 20); //右に少しずらす
    }
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
