#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    
    //ofxBox2dの世界設定
    box2d.init(); //box2dの初期化
    box2d.setFPS(30.0); //物理演算する際のフレームレートを描画する際のフレームレートと別に設定できる(演算量を抑えて、よりスムーズな物理演算)
    box2d.registerGrabbing(); //オブジェクトをマウスで掴む
    box2d.createBounds(); //画面の四隅に壁を作る
    
    //円
    circle.setPhysics(3.0, 0.5, 0.1); //円の初期設定
    circle.setup(box2d.getWorld(), 400, 100, 40); //円をofxBox2dに追加(.getWorldでbox2dの中身を取り出す)(追加する世界, 初期位置x, 初期位置y, 半径)
}

void ofApp::update(){
    box2d.update(); //物理演算はこの一行で全て行なってくれる
}

void ofApp::draw(){
    ofSetColor(31, 127, 255);
    circle.draw(); //円を描画
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
