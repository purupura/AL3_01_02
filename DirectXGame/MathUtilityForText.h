#pragma once
#include "Matrix4x4.h"
#include "Vector3.h"
#include <cmath>

// 加算
Vector3 Add(const Vector3& v1, const Vector3& v2);

Vector3 Add2(const Vector3 v1, const Vector3 v2);

// 積
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

// 1.X軸回転行列
Matrix4x4 MakeRotateXMatrix(float radian);

// 2.Y軸回転行列
Matrix4x4 MakeRotateYMatrix(float radian);

// 3.Z軸回転行列
Matrix4x4 MakeRotateZMatrix(float radian);

// 回転行列の合成
Matrix4x4 RotateXYZMatrix(const Vector3& radian);

// 3次元アフィン変換行列
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

Vector3 Lerp(const Vector3& a, const Vector3& b, float t);

Vector3 Multiply(float scalar, const Vector3& v);