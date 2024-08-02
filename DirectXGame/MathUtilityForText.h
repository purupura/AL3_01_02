#pragma once
#include "Vector3.h"
#include <Matrix4x4.h>

Vector3& operator+=(Vector3& lhv, const Vector3& rhv);
Matrix4x4 MatrixMultiply(Matrix4x4& m1, Matrix4x4& m2);
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate);
float EaseInOut(float x1, float x2, float t);
float Lerp(float x1, float x2, float t);
Vector3 Lerp(const Vector3& v1, const Vector3& v2, float t);

class MathUtilityForText {};