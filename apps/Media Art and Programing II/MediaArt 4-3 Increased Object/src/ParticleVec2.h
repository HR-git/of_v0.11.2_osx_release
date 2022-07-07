//
//  ParticleVec2.hpp
//  MediaArt 4-2 Create a Class
//
//  Created by Hiroyuki Y on 2022/07/07.
//

#pragma once //一度だけ読み込むように指定（インクルードガード）
#include "ofMain.h" //openFrameworksの機能を読み込む
class ParticleVec2 {
public: //クラスの外から参照できる(カプセル化)
    ParticleVec2(); //コンストラクタ(初期化関数)
    void update(); //関数
    void draw();
    void bounce();
    
    glm::vec2 location; //ベクトル
    glm::vec2 velocity;
private: //クラスの中でのみ参照できる
};
