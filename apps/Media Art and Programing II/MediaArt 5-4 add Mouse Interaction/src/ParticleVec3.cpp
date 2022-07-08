//
//  ParticleVec2.cpp
//  MediaArt 4-2 Create a Class
//
//  Created by Hiroyuki Y on 2022/07/07.
//

#include "ParticleVec3.h"

ParticleVec3::ParticleVec3() { //コンストラクタ(クラス::関数)
    location = glm::vec3(ofGetWidth() / 2, ofGetHeight()/ 2, 0);
    velocity = glm::vec3(0, 0, 0);
    acceleration = glm::vec3(0, 0, 0);
    gravity = glm::vec3(0, 0.2, 0); //下方向に重力
    initTime = ofGetElapsedTimef(); //プログラムが実行されてからの経過時間を秒で記録
    lifeTime = 10.0; //持続時間
    isLive = true; //現在の状態
    friction = 0.01; //摩擦力
    mass = 0.5; //質量
}

void ParticleVec3::update() {
    addForce(gravity);
    velocity = velocity + acceleration; //次のフレームでの速度(加速度から速度を算出)
    velocity = velocity * (1.0 - friction); //摩擦力から速度を補正
    location = location + velocity; //速度から位置を算出
    acceleration = glm::vec3(0, 0, 0); //加速度をリセット
    //現在の経過時間からプログラムが実行されてからの経過時間を引くとオブジェクトが生成されてからの経過時間が算出される
    if (ofGetElapsedTimef() - initTime > lifeTime) { //オブジェクトガ生成されてからの経過時間がlifeTimeを超えたらfalse
        isLive = false;
    }
}

void ParticleVec3::draw() {
    ofDrawCircle(location, 3);
}

void ParticleVec3::addForce(glm::vec3 force) {
    // f = ma
    // a = f/m
    acceleration = acceleration + (force / mass); //加速度を算出
}

void ParticleVec3::bounce() {
    if (location.x > ofGetWidth() || location.x < 0) {
        velocity.x = velocity.x * -1;
    }
    if (location.y > ofGetHeight() || location.y < 0) {
        velocity.y = velocity.y * -1;
    }
    if (location.z > ofGetHeight() || location.z < -ofGetHeight()) {
        velocity.z = velocity.z * -1;
    }
}