#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
}

void ofApp::update(){

}

void ofApp::draw(){
    ofTranslate(ofGetWidth() / 2.0, ofGetHeight() / 2.0); //カメラを使うので座標全体を移動(通常は左上が原点(0, 0))
    box.set(200); //ofBoxPrimitiveの大きさ
    box.setPosition(-150, 0, 0); //x座標を150左に移動
    box.drawWireframe(); //ワイヤーフレームを描画
    sphere.set(100, 16); //ofSpherePrimitiveの大きさ
    sphere.setPosition(150, 0, 0);
    sphere.drawWireframe();
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
