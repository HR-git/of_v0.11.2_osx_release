#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    ofEnableDepthTest(); //立体が手前に来たときに背後の図形を隠す処理を有効に
}

void ofApp::update(){

}

void ofApp::draw(){
    cam.begin(); //以下をカメラで映す
    box.set(200); //ofBoxPrimitiveの大きさ
    box.setPosition(-150, 0, 0); //x座標を150左に移動
    box.draw(); //塗りつぶして描画
    sphere.set(100, 16); //ofSpherePrimitiveの大きさ
    sphere.setPosition(150, 0, 0);
    sphere.draw();
    cam.end(); //ここまでカメラで映す
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
