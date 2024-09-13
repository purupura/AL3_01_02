#pragma once
#define NOMINMAX
#include "Input.h"
#include "MathUtilityFortext.h"
#include "Model.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "Easing.h"
#include <algorithm>
#include <cassert>
#include <numbers>

class MapChipField;

class Player {
public:
	/*Player();

	~Player();*/
	///< summary>
	/// 初期化
	///</summary>
	void Initialize(Model* model, uint32_t textureHandle, ViewProjection* viewProjection, const Vector3& position);

	///< summary>
	/// 更新
	///</summary>
	void Update();

	///< summary>
	/// 描画
	///</summary>
	void Draw();

	const WorldTransform& GetWorldTransform() const { return worldTransform_; };

	const Vector3& GetVelocity() const { return velocity_; }

	void SetMapChipField(MapChipField* mapChipField) { mapChipField_ = mapChipField; }

private:
	enum class LRDirection {
		kRight,
		kLeft,
	};

	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
	// テクスチャハンドル
	uint32_t texturehandle_ = 0u;

	ViewProjection* viewprojection_ = nullptr;

	Vector3 velocity_ = {};

	static inline const float kAcceleration = 0.01f;
	static inline const float kAttenuation = 0.03f;
	static inline const float kLimitSpeed = 4.0f;

	LRDirection lrDirection_ = LRDirection::kRight;

	// 旋回開始時の角度
	float turnFirstRotationY_ = 0.0f;
	// 旋回タイマー
	float turnTimer_ = 0.0f;

	// 旋回時間<秒>
	static inline const float kTimeTurn = 0.3f;

	bool onGround_ = true;

	MapChipField* mapChipField_ = nullptr;

	static inline const float kGravityAcceleration = 0.05f;
	static inline const float kJumpAcceleration = 0.5f;
	static inline const float kLimitFallSpeed = .0f;
};
