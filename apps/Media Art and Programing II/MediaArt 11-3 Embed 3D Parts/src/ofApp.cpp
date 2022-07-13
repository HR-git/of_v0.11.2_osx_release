#include "ofApp.h"

void ofApp::setup() {
    //grabber.listDevices(); //コンソールにデバイス番号を表示
    //grabber.setDeviceID(0); //デバイス番号を指定して接続
    grabber.setup(1280, 720);
    tracker.setup();
    light.setSpotlight(); //スポットライト
    light.setPosition(400, 100, 200);
    light.enable();
}

void ofApp::update() {
    grabber.update(); //ビデオカメラの更新
    if (grabber.isFrameNew()) {
        tracker.update(grabber);
    }
}

void ofApp::draw() {
    ofSetColor(255);
    ofDisableLighting(); //カメラの映像を撮る前に一時的にライトをオフにする
    grabber.draw(0, 0); //映像を描画
    ofEnableLighting();
    ofEnableDepthTest(); //球体を正常に描画する
    //顔を検出
    vector<ofxFaceTracker2Instance> faces = tracker.getInstances();
    for (int i = 0; i < faces.size(); i++) {
        ofRectangle faceRect = faces[i].getBoundingBox(); //目の大きさを距離に合わせて拡大縮小するための四角形
        ofPushMatrix();
        {
            faces[i].loadPoseMatrix(); //向きと大きさのMatrixを取り出す
            ofSetLineWidth(2);
            ofSetSphereResolution(8);
            //左目
            ofPushMatrix();
            ofTranslate(-48, 0, 0); //loadPoseMatrixされているので実数値で指定できる
            ofSetColor(255);
            ofDrawSphere(30); //loadPoseMatrixされているので実数値で指定できる
            ofSetColor(0);
            ofTranslate(0, 0, -15);
            ofDrawSphere(20);
            ofPopMatrix();
            //右目
            ofPushMatrix();
            ofTranslate(48, 0, 0);
            ofSetColor(255);
            ofDrawSphere(30);
            ofSetColor(0);
            ofTranslate(0, 0, -15);
            ofDrawSphere(20);
            ofPopMatrix();
            //鼻
            ofPushMatrix();
            ofTranslate(0, -40, 0);
            ofSetColor(255, 1, -10);
            ofDrawSphere(32);
            ofPopMatrix();
        }
        ofPopMatrix();
    }
    ofDisableDepthTest();
}
