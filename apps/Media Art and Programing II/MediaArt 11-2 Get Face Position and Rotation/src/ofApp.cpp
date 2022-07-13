#include "ofApp.h"

void ofApp::setup() {
    //grabber.listDevices(); //コンソールにデバイス番号を表示
    //grabber.setDeviceID(0); //デバイス番号を指定して接続
    grabber.setup(1280, 720);
    tracker.setup();
}

void ofApp::update() {
    grabber.update(); //ビデオカメラの更新
    if (grabber.isFrameNew()) {
        tracker.update(grabber);
    }
}

void ofApp::draw() {
    ofSetColor(255);
    grabber.draw(0, 0); //映像を描画
    //顔を検出
    vector<ofxFaceTracker2Instance> faces = tracker.getInstances();
    for (int i = 0; i < faces.size(); i++) {
        ofRectangle faceRect = faces[i].getBoundingBox(); //目の大きさを距離に合わせて拡大縮小するための四角形
        ofPushMatrix();
        faces[i].loadPoseMatrix(); //向きと大きさのMatrixを取り出す
        ofNoFill();
        ofSetLineWidth(2);
        ofSetSphereResolution(8);
        ofDrawSphere(faceRect.getWidth() / 2.0);
        ofFill();
        ofPopMatrix();
    }
}
