#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(16);
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
    //配列の末尾にlocation, velocityを追加する(要素の格納)
    glm::vec2 loc = glm::vec2(ofGetWidth() / 2, ofGetHeight() / 2);
    location.push_back(loc);
    glm::vec2 vel = glm::vec2(ofRandom(-10, 10), ofRandom(-10, 10));
    velocity.push_back(vel);
    
    if (location.size() > MAX) { //定数MAXを超えたら配列の先頭が削除
        location.erase(location.begin());
        velocity.erase(velocity.begin());
    }
    
    for (int i = 0; i < location.size(); i++) { //全ての位置ベクトルと速度ベクトルにupdateを適用
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
    for (int i = 0; i < location.size(); i++) { //全てのlocation[i]にofDrawCircleを適用
        ofSetColor(0, 127, 255, 200);
        ofDrawCircle(location[i], 4); //glm::vec2ならlocationと書くだけで(x, y)座標を同時に指定できる
    }
    ofSetColor(255);
    ofDrawBitmapString(ofGetFrameRate(), 20, 20); //画面左上のビットレートの表示
    ofDrawBitmapString("NUM = " + ofToString(location.size()), 20, 40); //円の数をカウント
}
