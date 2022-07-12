#include "ofApp.h"

void ofApp::setup(){
    grabber.listDevices(); //自分の環境で使っているカメラのデバイス番号を確認する
    grabber.setDeviceID(0); //0番のデバイスを選択
    grabber.setup(1280, 720); //カメラを設定(解像度) > main.cppのOpenGLの解像度(開くウィンドウの大きさ)も揃える
}

void ofApp::update(){
    grabber.update(); //毎フレーム更新する必要がある
}

void ofApp::draw(){
    grabber.draw(0, 0); //左上に位置を指定して描画
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
