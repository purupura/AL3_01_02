#include "MapChipField.h"
#include "Model.h"
#include "WorldTransform.h"

enum class LRDirection {
	kRight,
	kLeft,
};

class Player {

public:
	static inline const float kAcceleration = 0.01f;
	static inline const float kAttenuation = 1.0f;
	static inline const float kLimitRunSpeed = 1.0f;
	LRDirection lrDirection_ = LRDirection::kRight;
	float turnFirstRotationY_ = 0.0f;
	float turnTimer_ = 0.0f;
	static inline const float kTimeTurn = 0.3f;
	bool onGround_ = true;
	static inline const float kGravityAcceleration = 0.5f;
	static inline const float kLimitFallSpeed = 0.3f;
	static inline const float kJumpAcceleration = 2.0f;

	///< summary>
	/// 初期化
	///</summary>
	void Initialize(Model* model, uint32_t textureHandle, ViewProjection* viewProjection, const Vector3& position);
	///< summary>
	/// 更新
	///  <summary>
	void Update();
	///< summary>
	/// 描画
	///< summary>
	void Draw();

	Vector3 velocity_ = {};

private:
	WorldTransform worldTransform_;
	Model* model_ = nullptr;
	uint32_t textureHandle_ = 0u;
	ViewProjection* viewProjection_ = nullptr;
	Player* player_ = nullptr;
};