//
//  ParticleVec2.cpp
//  MediaArt 4-2 Create a Class
//
//  Created by Hiroyuki Y on 2022/07/07.
//

#include "ParticleVec2.h"

ParticleVec2::ParticleVec2() { //コンストラクタ(クラス::関数)
    location = glm::vec2(ofGetWidth() / 2, ofGetHeight()/ 2);
    velocity = glm::vec2(ofRandom(-10, 10), ofRandom(-10, 10));
    initTime = ofGetElapsedTimef(); //プログラムが実行されてからの経過時間を秒で記録
    lifeTime = 10.0; //持続時間
    isLive = true; //現在の状態
}

void ParticleVec2::update() {
    location = location + velocity;
    //現在の経過時間からプログラムが実行されてからの経過時間を引くとオブジェクトが生成されてからの経過時間が算出される
    if (ofGetElapsedTimef() - initTime > lifeTime) { //オブジェクトガ生成されてからの経過時間がlifeTimeを超えたらfalse
        isLive = false;
    }
}

void ParticleVec2::draw() {
    ofDrawCircle(location, 10);
}

void ParticleVec2::bounce() {
    if (location.x > ofGetWidth() || location.x < 0) {
        velocity.x = velocity.x * -1;
    }
    if (location.y > ofGetHeight() || location.y < 0) {
        velocity.y = velocity.y * -1;
    }
}
