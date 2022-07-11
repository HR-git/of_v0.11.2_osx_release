#include "ofApp.h"

void ofApp::setup(){
    //オブジェクトを指し示す伝統的なポインタ
    int* ptr = new int(12345); //intクラスを初期化 > クラスを初期化したアドレスをポインタに渡す
    cout << "ptr : " << ptr << endl;
    cout << "*ptr : " << *ptr << endl; //アドレスの中身を取り出す
    delete ptr; //必要無くなったメモリを削除して領域を解放する(C++のメモリ管理は自分の操作:マニュアルで行う)
    
    //スマートポインタを使った場合(メモリをdeleteする必要がない)
    ofPtr<int> optr(new int(12345));//ofのスマートポインター:ofPtrをint型として宣言 > ofPtrオブジェクトoptrに整数12345を代入して初期化
    cout << "optr : " << optr << endl;
    cout << "*optr : " << *optr << endl;
}

void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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
