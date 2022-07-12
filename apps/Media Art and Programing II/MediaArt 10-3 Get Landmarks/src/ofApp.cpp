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
        //顔を取り囲む四角形を作ってその大きさの比率で目の丸の大きさを更新する
        ofRectangle faceRect = faces[i].getBoundingBox();
        //Landmaarksの中からLEFT_EYEに関する点だけを抽出 > さらに中心点を出して代入
        glm::vec2 leftPos = landmarks.getImageFeature(ofxFaceTracker2Landmarks::LEFT_EYE).getCentroid2D();
        //右目
        glm::vec2 rightPos = landmarks.getImageFeature(ofxFaceTracker2Landmarks::RIGHT_EYE).getCentroid2D();
        ofSetColor(255);
        ofDrawCircle(leftPos, faceRect.getWidth() / 6.0); //左めに丸を描画
        ofDrawCircle(rightPos, faceRect.getWidth() / 6.0);
        ofSetColor(0);
        ofDrawCircle(leftPos, faceRect.getWidth() / 12.0); //左めに小さい丸を描画
        ofDrawCircle(rightPos, faceRect.getWidth() / 12.0);
    }

    // show log
    ofSetColor(255);
    ofDrawBitmapStringHighlight("Framerate : " + ofToString(ofGetFrameRate()), 10, 20);
    ofDrawBitmapStringHighlight("Tracker thread framerate : "
        + ofToString(tracker.getThreadFps()), 10, 40);
}
