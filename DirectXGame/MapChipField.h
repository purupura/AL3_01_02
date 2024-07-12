#pragma once
#include <cstdint>
#include <vector>
#include <math.h>
#include <string>
#include <cassert>
#include "Vector3.h"
#include"Model.h"
#include"WorldTransform.h"

enum class MapChipType {
	kBlank, // 空白
	kBlock, // ブロック
};

struct MapChipData {
	std::vector<std::vector<MapChipType>> data;
};



/// <summary>
/// マップチップフィールド
/// </summary>

class MapChipField {

	public:

	static inline const float kBlockWidth = 1.0f;
	static inline const float kBlockHeight = 1.0f;

	static inline const uint32_t kNumBlockVirtical = 20;
	static inline const uint32_t kNumBlockHorizontal = 20;


	MapChipData mapChipData_;
	
	uint32_t GetNumBlockVirtical();

	uint32_t GetNumBlockHorizontal();

	void ResetMapChipData();

	void LoadMapChipCsv(const std::string& filePath);

	
	MapChipType GetMapChipTypeByIndex(uint32_t xIndex, uint32_t yIndex);

	Vector3 GetMapChipPositionTypeByIndex(uint32_t xIndex, uint32_t yIndex);

};
