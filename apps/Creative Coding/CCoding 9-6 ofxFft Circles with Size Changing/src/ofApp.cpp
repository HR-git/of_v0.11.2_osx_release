#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);
    //FFTのサンプル数(2の累乗)を指定して初期化
    fft.setup(pow(2.0, 8.0)); //周波数の解像度を上げると時間解像度が下がる
    //GUI
    gui.setup();
    gui.add(saturation.setup("saturation", 127, 0, 255));
    gui.add(alpha.setup("alpha", 127, 0, 255));
}

void ofApp::update(){
    fft.update(); //FFTを更新
}

void ofApp::draw(){
    //float型の配列にFFTの結果を格納
    vector<float> buffer;
    buffer = fft.getBins();
    //グラフに描画
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetLineWidth(ofGetWidth() / float(buffer.size()) / 2.0);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetCircleResolution(64);
    for (int i = 0; i < buffer.size(); i++) {
        //色を設定
        float hue = ofMap(i, 0, buffer.size(), 0, 160);
        float br = ofMap(buffer[i], 0, 1, 0, 255);
        float radius = ofMap(buffer[i], 0, 1, 0, ofGetHeight() / 2.0);
        ofColor col;
        col.setHsb(hue, saturation, br, alpha);
        ofSetColor(col);
        //右
        float rx = ofMap(i, 0, buffer.size(), 0, ofGetWidth() / 2.0);
        ofCircle(rx, 0, radius);
        //左
        float lx = ofMap(i, 0, buffer.size(), 0, -ofGetWidth() / 2.0);
        ofCircle(lx, 0, radius);
    }
    ofPopMatrix();
    gui.draw(); //GUI描画
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
