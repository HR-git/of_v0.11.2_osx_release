#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending(); //透明度を有効にする
    ofSetCircleResolution(64); //円を描画する精度
    ofBackground(0); //背景色(R, G, B)
    ofSetFrameRate(60); //フレームレートを設定(1秒間に60回更新)
    locationX = 0; //変数の初期値を0にする
    locationY = 0;
}

//--------------------------------------------------------------
void ofApp::update(){ //更新 = 変化量
    locationX = locationX + 3; //前のフレームからの(x, y)の変化量を指定
    locationY = locationY + 2;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 127, 255, 127); //0~255で(Red, Green, Blue, Alpha)
    ofDrawCircle(locationX, locationY, 20); //(中心のx座標, 中心のy座標, 半径の長さ)
    //更新した位置で円を描く
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
