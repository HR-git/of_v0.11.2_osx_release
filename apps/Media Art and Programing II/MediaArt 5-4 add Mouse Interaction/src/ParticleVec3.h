//
//  ParticleVec2.hpp
//  MediaArt 4-2 Create a Class
//
//  Created by Hiroyuki Y on 2022/07/07.
//

#pragma once //一度だけ読み込むように指定（インクルードガード）
#include "ofMain.h" //openFrameworksの機能を読み込む
class ParticleVec3 {
public: //クラスの外から参照できる(カプセル化)
    ParticleVec3(); //コンストラクタ(初期化関数)
    void update(); //関数
    void draw();
    void bounce();
    void addForce(glm::vec3 force);
    
    glm::vec3 location; //ベクトル
    glm::vec3 velocity;
    glm::vec3 acceleration;
    glm::vec3 gravity; //重力
    float friction; //摩擦力
    float mass; //質量
    
    float lifeTime; //寿命
    float initTime; //プログラムが実行されてからの時間
    bool isLive; //現在の状態(生きているか)
private: //クラスの中でのみ参照できる
};
