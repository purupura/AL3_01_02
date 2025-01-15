#include "ClearScene.h"

ClearScene::ClearScene() {}

ClearScene::~ClearScene() {
	delete skydome_;
	delete modelSkydome_;
}

void ClearScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	// ワールドトランスフォームの初期化
	worldTransform_.Initialize();
	// ビュープロジェクションの初期化
	viewProjection_.Initialize();

	// 天球を生成
	skydome_ = new Skydome();
	modelSkydome_ = Model::CreateFromOBJ("skydome", true);
	// 天球を初期化
	skydome_->Initialize(modelSkydome_, skyDometextureHandle_, &viewProjection_);

	modelClear_ = Model::CreateFromOBJ("GameClear");
	modelClearForm_.Initialize();

	modelClearForm_.translation_ = {-38.0f, 0.0f, 0.0f}; // x, y, zの値を調整
	PushFontForm_.translation_ = {-15.0f, -10.0f, 0.0f}; // x, y, zの値を調整
}

void ClearScene::Update() {

	skydome_->Update();
	if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {

		finished_ = true;
	}


}


void ClearScene::Draw() {
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
	skydome_->Draw();

	modelClear_->Draw(modelClearForm_, viewProjection_);


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