#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(64);
    ofSetFrameRate(60);
    location = glm::vec2(0, 0); //位置ベクトルを初期化
    velocity = glm::vec2(30, 10); //速度ベクトルを初期化
}

//--------------------------------------------------------------
void ofApp::update(){
    location = location + velocity; //位置ベクトルに速度ベクトルを加算すると次のフレームの位置が算出できる
    
    //画面の端まで来たら跳ね返る処理
    if (location.x > ofGetWidth() || location.x < 0) { //xが画面の幅より大きくなるか又は、xが0より小さくなったら速度のx成分に-1をかける
        velocity.x = velocity.x * -1;
    }
    if (location.y > ofGetHeight() || location.y < 0) {
        velocity.y = velocity.y * -1;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 127, 255, 200);
    ofDrawCircle(location, 20); //glm::vec2ならlocationと書くだけで(x, y)座標を同時に指定できる
    ofSetColor(255);
    ofDrawBitmapString(ofGetFrameRate(), 20, 20); //画面左上のビットレートの表示
}
