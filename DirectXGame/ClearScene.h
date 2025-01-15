#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Skydome.h"
#include "TextureManager.h"
#include <Input.h>
#include <Model.h>
#include <Sprite.h>
// #include "imgui.h"

#pragma once
class ClearScene {
public:
	/// <summary>
	/// コンストクラタ
	/// </summary>
	ClearScene();

	/// <summary>
	/// デストクラタ
	/// </summary>
	~ClearScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	// デスフラグの getter
	bool IsFinished() const { return finished_; }

private:
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	// ワールドトランスフォーム
	WorldTransform worldTransform_;
	// ビュープロジェクション
	ViewProjection viewProjection_;

	// 終了フラグ
	bool finished_ = false;

	// 天球
	Skydome* skydome_ = nullptr;
	Model* modelSkydome_ = nullptr;

	Model* modelClear_ = nullptr;
	WorldTransform modelClearForm_;

	Model* modelPushFont_ = nullptr;
	WorldTransform PushFontForm_;

	// テクスチャハンドル
	uint32_t skyDometextureHandle_ = 0;

	// uint32_t soundSEData_1 = 0;
	// uint32_t soundSE_1 = 0;
	// bool soundSE_Clear_ = false;

	// uint32_t soundSEData_2 = 0;
	// uint32_t soundSE_2 = 0;
};