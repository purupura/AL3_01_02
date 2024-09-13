#pragma once

#include "Audio.h"
#include "CameraController.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "MapChipField.h"
#include "Model.h"
#include "Player.h"
#include "Skydome.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "debugCamera.h"
#include <vector>

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	void GenerateBlocks();

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0;

	// モデル
	Model* model_ = nullptr;

	// ワールドトランスフォーム
	WorldTransform worldTransform_;
	// ビュープロジェクション
	ViewProjection viewProjection_;

	// 自キャラ
	Player* player_ = nullptr;

	Model* modelBlock_ = nullptr;

	std::vector<std::vector<WorldTransform*>> worldTransformBlocks_;

	// デバッグカメラ
	DebugCamera* debugCamera_ = nullptr;

	bool isDebugCameraActive_ = false;

	// 天球
	Skydome* skydome_ = nullptr;

	Model* modelSkydome_ = nullptr;

	// テクスチャハンドル
	uint32_t skyDometextureHandle_ = 0;

	// マップチップフィールド
	MapChipField* mapChipField_;

	// カメラコントローラ
	CameraController* cameraController_;

	/// <summary>
	/// ゲームシーン用
	/// </summary>
};
