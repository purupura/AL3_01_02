#include "matrix.h"
#include <Matrix4x4.h>
#include <math.h>

Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 ret = {};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				ret.m[i][j] += m1.m[i][k] * m2.m[k][j];
			}
		}
	}
	return ret;
}

Matrix4x4 MakeScaleMatrix(const Vector3& scale) {
	Matrix4x4 result = {};

	result.m[0][0] = scale.x;
	result.m[1][1] = scale.y;
	result.m[2][2] = scale.z;
	result.m[3][3] = 1.0f;

	return result;
}

Matrix4x4 MakeTranslateMatrix(const Vector3& translate) {
	Matrix4x4 result = {};

	result.m[0][0] = 1.0f;
	result.m[1][1] = 1.0f;
	result.m[2][2] = 1.0f;
	result.m[3][3] = 1.0f;
	result.m[3][0] = translate.x;
	result.m[3][1] = translate.y;
	result.m[3][2] = translate.z;

	return result;
}

Matrix4x4 MakeRotateMatrix(const Vector3& rotate) {

	Matrix4x4 rotateX = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, cosf(rotate.x), sinf(rotate.x), 0.0f, 0.0f, -sinf(rotate.x), cosf(rotate.x), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};

	Matrix4x4 rotateY = {cosf(rotate.y), 0.0f, -sinf(rotate.y), 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, sinf(rotate.y), 0.0f, cosf(rotate.y), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};

	Matrix4x4 rotateZ = {cosf(rotate.z), -sinf(rotate.z), 0.0f, 0.0f, -sinf(rotate.z), cosf(rotate.z), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
	return Multiply(Multiply(rotateX, rotateY), rotateZ);
}

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate) {
	Vector3 dm = scale;

	Matrix4x4 RotateMatY = {cosf(rot.y), 0, -sinf(rot.y), 0, 0, 1, 0, 0, sinf(rot.y), 0, cosf(rot.y), 0, 0, 0, 0, 1};
	Matrix4x4 TranslateMat = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, translate.x, translate.y, translate.z, 1};

	Matrix4x4 ansMat = Multiply(RotateMatY, TranslateMat);

	return ansMat;
}

