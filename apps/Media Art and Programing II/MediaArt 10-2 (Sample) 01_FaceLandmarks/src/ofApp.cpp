#include "ofApp.h"

void ofApp::setup() {
    //grabber.listDevices();
    //grabber.setDeviceID(0);
    grabber.setup(1280, 720);
    tracker.setup(); //FaceaTrackerの初期化
}

void ofApp::update() {
    grabber.update();
    //カメラが画像を取得した時のみofも更新する
    if (grabber.isFrameNew()) {
        tracker.update(grabber);
    }
}

void ofApp::draw() {
    //draw video
    grabber.draw(0, 0);
    // Draw all tracker landmarks points
    // 1. Get tracked faces
    vector<ofxFaceTracker2Instance> faces = tracker.getInstances(); //顔を配列に入れる
    for (int i = 0; i < faces.size(); i++) { //検出された顔の数だけ繰り返す
        //2. get face's landmarks
        ofxFaceTracker2Landmarks landmarks = faces[i].getLandmarks(); //顔の特徴点(Landmarks)を取り出す
        //3. get landmark's imagepoints
        vector<glm::vec2> imagePoints = landmarks.getImagePoints(); //Landmarksの(x, y)座標をベクトルにして取り出す
        //4. draw all points
        for (int j = 0; j < imagePoints.size(); j++) { //座標に点と数字を描く
            glm::vec2 pos = imagePoints[j];
            ofSetColor(255);
            ofDrawCircle(pos, 5);
            ofSetColor(255, 0, 0);
            ofDrawBitmapString(ofToString(i * tracker.getInstances().size() + j), pos.x, pos.y);
        }
    }

    // show log
    ofSetColor(255);
    ofDrawBitmapStringHighlight("Framerate : " + ofToString(ofGetFrameRate()), 10, 20);
    ofDrawBitmapStringHighlight("Tracker thread framerate : "
        + ofToString(tracker.getThreadFps()), 10, 40);
}
