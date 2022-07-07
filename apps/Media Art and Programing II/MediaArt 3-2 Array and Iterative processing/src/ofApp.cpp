#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(16);
    ofSetFrameRate(60);
    for (int i = 0; i < NUM; i++) { //位置ベクトルと速度ベクトルの配列を全て初期化
        location[i] = glm::vec2(ofGetWidth()/2, ofGetHeight()/2);
        velocity[i] = glm::vec2(ofRandom(-10, 10), ofRandom(-10, 10));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < NUM; i++) { //全ての位置ベクトルと速度ベクトルにupdateを適用
        location[i] = location[i] + velocity[i]; //位置ベクトルに速度ベクトルを加算すると次のフレームの位置が算出できる
    
        //画面の端まで来たら跳ね返る処理
        if (location[i].x > ofGetWidth() || location[i].x < 0) { //xが画面の幅より大きくなるか又は、xが0より小さくなったら速度のx成分に-1をかける
            velocity[i].x = velocity[i].x * -1;
        }
        if (location[i].y > ofGetHeight() || location[i].y < 0) {
            velocity[i].y = velocity[i].y * -1;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < NUM; i++) { //全てのlocation[i]にofDrawCircleを適用
        ofSetColor(0, 127, 255, 200);
        ofDrawCircle(location[i], 20); //glm::vec2ならlocationと書くだけで(x, y)座標を同時に指定できる
    }
    ofSetColor(255);
    ofDrawBitmapString(ofGetFrameRate(), 20, 20); //画面左上のビットレートの表示
}
