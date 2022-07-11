#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    
    //ofxBox2dの世界設定
    box2d.init(); //box2dの初期化
    box2d.setFPS(30.0); //物理演算する際のフレームレートを描画する際のフレームレートと別に設定できる(演算量を抑えて、よりスムーズな物理演算)
    box2d.registerGrabbing(); //オブジェクトをマウスで掴む
    box2d.createBounds(); //画面の四隅に壁を作る
    
 
}

void ofApp::update(){
    box2d.update(); //物理演算はこの一行で全て行なってくれる
}

void ofApp::draw(){
    ofSetColor(31, 127, 255);
    //circles配列に含まれているcircleの数だけ円を描く
    for (int i = 0; i < circles.size(); i++) {
        circles[i].get()->draw(); //ofxPtrの場合は.get()をつけて中身を取り出してから->draw()することで中に含まれるdraw関数が呼び出される
    }
    ofSetColor(255, 127, 31);
    for (int i = 0; i < rects.size(); i++) {
        rects[i].get()->draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //Cのキーを押すとマウスの位置に円を追加
    if (key == 'c') {
        ofPtr<ofxBox2dCircle> cir(new ofxBox2dCircle()); //ofBox2dCircle型のポインタとしてオブジェクトcirを作って初期化
        cir->setPhysics(3.0, 0.5, 0.1); //物理法則を適用
        cir->setup(box2d.getWorld(), mouseX, mouseY, ofRandom(5, 50)); //世界に追加
        circles.push_back(cir); //配列の末尾に追加
    }
    //Rのキーを押すとマウスの位置に矩形を追加
    if (key == 'r') {
        ofPtr<ofxBox2dRect> rec(new ofxBox2dRect());
        rec->setPhysics(3.0, 0.5, 0.1); //物理法則を適用
        rec->setup(box2d.getWorld(), mouseX, mouseY, ofRandom(5, 50), ofRandom(5, 50)); //世界に追加
        rects.push_back(rec); //配列の末尾に追加
    }
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
