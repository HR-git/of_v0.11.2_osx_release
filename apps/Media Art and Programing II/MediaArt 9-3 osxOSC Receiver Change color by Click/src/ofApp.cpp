#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    receiver.setup(8000); //受信側はipアドレスの指定は必要ない
    mpos = glm::vec2(0, 0);
    pressed = false;
}

void ofApp::update(){
    //大量のメッセージが同時に送られた場合、メッセージを1つずつ1秒間に60回のフレームレートで処理していては間に合わない
    //メッセージを1つずつではなく、まとめて受け取って後で処理する
    while (receiver.hasWaitingMessages()) { //待っているメッセージがあるかどうかを確認して、それがある間は繰り返す
        ofxOscMessage msg;
        receiver.getNextMessage(msg); //メッセージを順に処理していく
        if (msg.getAddress() == "/mouse/position") { //メッセージのアドレス
            mpos.x = msg.getArgAsInt(0); //マウスのx座標
            mpos.y = msg.getArgAsInt(1); //マウスのy座標
        }
        else if (msg.getAddress() == "/mouse/button") { //新たにアドレスを受信する際はelse if()を使う
            if (msg.getArgAsString(0) == "pressed") { //0番目のメッセージの中身がpressedだったら
                pressed = true;
            }
            else {
                pressed = false;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (pressed == true) { //SenderからPressedメッセージが送られてきたら色を変える
        ofSetColor(255, 0, 0);
    }
    else {
          ofSetColor(0, 0, 255);
          }
    ofDrawCircle(mpos, 40);
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
