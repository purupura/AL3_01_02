#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include"MathUtilityForText.h"


GameScene::GameScene() {
	
}

GameScene::~GameScene() { 

delete model_; 
delete player_;

delete modelBlock_;

delete debugCamera_;
for (std::vector<WorldTransform*>&worldTransformBlockLine:worldTransformBlocks_) {
	for (WorldTransform* worldTransformBlock : worldTransformBlockLine)
	{
		delete worldTransformBlock;
	}

	

}
worldTransformBlocks_.clear();
}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	
	textureHandle_ = TextureManager::Load("sample.png");

	model_ = Model::Create();

	viewProjection_.Initialize();
	//自キャラの生成
	 player_ = new Player();
	//自キャラの初期化
	 player_->Initialize(model_,textureHandle_,&viewProjection_);

	 modelBlock_ = Model::CreateFromOBJ("cube");

	 const uint32_t kNumBlockVertical   = 10;
	 const uint32_t kNumBlockHorizontal = 20;

	 const float kBlockHeigt = 2.0f;
	 const float kBlockWidth = 2.0f;

	 worldTransformBlocks_.resize(kNumBlockVertical);
	 for (uint32_t i = 0; i < kNumBlockVertical; ++i) {
		 worldTransformBlocks_[i].resize(kNumBlockHorizontal);
	 }

	 for (uint32_t i = 0; i < kNumBlockVertical; ++i) {
		 for (uint32_t j = 0; j < kNumBlockHorizontal; ++j){

			 worldTransformBlocks_[i][j] = new WorldTransform();
			 worldTransformBlocks_[i][j]->Initialize();
			 worldTransformBlocks_[i][j]->translation_.x = kBlockWidth * j*2;
			 worldTransformBlocks_[i][j]->translation_.y = kBlockHeigt * i*2;
		 }
	 }

	 debugCamera_ = new DebugCamera(1280, 720);

}
//更新
void GameScene::Update() {

	//自キャラの更新
	player_->Update();
	//ブロックの更新
	for (std::vector<WorldTransform*>& worldTransformBlockLine : worldTransformBlocks_) {
		for (WorldTransform* worldTransformBlock : worldTransformBlockLine) {
			if (!worldTransformBlock)
				continue;
			worldTransformBlock->UpdateMatrix();
		
		}
	}

	#ifdef _DEBUG
	if (input_->TriggerKey(DIK_SPACE)) {
		isDebugCameraActive_ = !isDebugCameraActive_;
	}
	#endif

	if (isDebugCameraActive_) {
		debugCamera_->Update();
		viewProjection_.matView = debugCamera_->GetViewProjection().matView;
		viewProjection_.matProjection = debugCamera_->GetViewProjection().matProjection;

		viewProjection_.TransferMatrix();

	} else {
		viewProjection_.UpdateMatrix();
	}

	
	
}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理     
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	player_->Draw();
	for (std::vector<WorldTransform*>& worldTransformBlockLine : worldTransformBlocks_) {
		for (WorldTransform* worldTransformBlock : worldTransformBlockLine) {
			if (!worldTransformBlock)
				continue;
			modelBlock_->Draw(*worldTransformBlock, viewProjection_);
		}
	}
	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
