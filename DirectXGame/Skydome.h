#pragma once

#include <WorldTransform.h>
#include <Model.h>

class Skydome {
	ViewProjection* viewProjection_ = nullptr;

	public:
	 /// <summary>
	 /// 初期化
	 /// <summary>
	 void Initialize(Model* model, ViewProjection* viewProjection);

	    /// <summary>
	 /// 初期化
	 /// <summary>
	 void Update();

	 /// <summary>
	 /// 初期化
	 /// <summary>
	 void Draw();
		

	 private:
		 //ワールド変換データ
	     WorldTransform worldTransform_;

		 Skydome* skydome_ = nullptr;

		 //モデル
	     Model* model_ = nullptr;



};
