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
    tracker.drawDebug(); //トラッキングできているかを確認
}
