#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    gui.setup("Test GUI"); //GUIの名前
    gui.add(rectSize.setup("Rect Size", 400, 0, 800)); //GUIにスライダーを追加(名前, 初期値, 最小値, 最大値)
    gui.add(rectSpeed.setup("Rotate Speed", 100, 0, 400));
    ofColor initColor = ofColor(31, 127, 255, 255);
    ofColor minColor = ofColor(0, 0, 0, 0);
    ofColor maxColor = ofColor(255, 255, 255, 255);
    gui.add(rectColor.setup("Rect Color", initColor, minColor, maxColor)); //初期値、最小値、最大値を決めておいて指定する
}

void ofApp::update(){

}

void ofApp::draw(){
    ofSetColor(rectColor);
    ofPushMatrix(); //左上が原点(0, 0)の状態の座標を保存(GUIの原点は左上のままにしたい)
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2); //画面の中心に座標(0, 0)を移動
    ofSetRectMode(OF_RECTMODE_CENTER); //中心点を基準に四角形を描くモード
    ofRotateZDeg(ofGetElapsedTimef() * rectSpeed); //プログラムを起動してからの経過時間によって回転
    ofDrawRectangle(0, 0, rectSize, rectSize); //osFloatSliderの名前を変数にするだけでfloat値が適用される
    ofPopMatrix(); //原点(0, 0)を画面の中心から左上に戻す
    gui.draw(); //GUIを描く
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
