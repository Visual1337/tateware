#pragma once
#include <windows.h>
#include <winternl.h>
#include <process.h>
#include <tlhelp32.h>
#include <inttypes.h>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <chrono>
#include <sstream>
#include <d3d9.h>

#pragma comment (lib, "d3d9.lib")

#include "Imgui/imgui.h"
#include "Imgui/imgui_impl_dx9.h"
#include "Imgui/imgui_impl_win32.h"
#include "defs.h"


HWND hwnd = NULL;

int Width;
int Height;
int Depth;

#define M_PI 3.14159265358979323846264338327950288419716939937510

class Vector3
{
public:
	Vector3() : x(0.f), y(0.f), z(0.f)
	{

	}

	Vector3(double _x, double _y, double _z) : x(_x), y(_y), z(_z)
	{

	}
	~Vector3()
	{

	}


	double x;
	double y;
	double z;

	inline double Dot(Vector3 v)
	{
		return x * v.x + y * v.y + z * v.z;
	}

	inline float Distance(Vector3 v)
	{
		return float(sqrtf(powf(v.x - x, 2.0) + powf(v.y - y, 2.0) + powf(v.z - z, 2.0)));
	}

	Vector3 operator+(Vector3 v)
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	Vector3 operator-(Vector3 v)
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	Vector3 operator*(float number) const {
		return Vector3(x * number, y * number, z * number);
	}
};

struct FQuat
{
	double x;
	double y;
	double z;
	double w;
};

struct FTransform
{
	FQuat rot;
	Vector3 translation;
	char pad[4];
	Vector3 scale;
	char pad1[4];
	D3DMATRIX ToMatrixWithScale()
	{
		D3DMATRIX m;
		m._41 = translation.x;
		m._42 = translation.y;
		m._43 = translation.z;

		float x2 = rot.x + rot.x;
		float y2 = rot.y + rot.y;
		float z2 = rot.z + rot.z;

		float xx2 = rot.x * x2;
		float yy2 = rot.y * y2;
		float zz2 = rot.z * z2;
		m._11 = (1.0f - (yy2 + zz2)) * scale.x;
		m._22 = (1.0f - (xx2 + zz2)) * scale.y;
		m._33 = (1.0f - (xx2 + yy2)) * scale.z;

		float yz2 = rot.y * z2;
		float wx2 = rot.w * x2;
		m._32 = (yz2 - wx2) * scale.z;
		m._23 = (yz2 + wx2) * scale.y;

		float xy2 = rot.x * y2;
		float wz2 = rot.w * z2;
		m._21 = (xy2 - wz2) * scale.y;
		m._12 = (xy2 + wz2) * scale.x;

		float xz2 = rot.x * z2;
		float wy2 = rot.w * y2;
		m._31 = (xz2 + wy2) * scale.z;
		m._13 = (xz2 - wy2) * scale.x;

		m._14 = 0.0f;
		m._24 = 0.0f;
		m._34 = 0.0f;
		m._44 = 1.0f;

		return m;
	}
};

struct FRotator
{
	double Pitch;
	double Yaw;
	double Roll;
};

FRotator* Rotator(FQuat* Current, struct FRotator* retstr)
{
	float Z; // xmm4_4
	float Y; // xmm0_4
	float W; // xmm2_4
	float v7; // xmm5_4
	float v8; // xmm7_4
	float v9; // xmm8_4
	float v10; // xmm0_4
	float v11; // xmm1_4
	float v12; // xmm7_4
	float X; // xmm0_4
	float v14; // xmm0_4
	float v15; // xmm0_4
	float v16; // xmm0_4
	float v17; // xmm1_4
	float v18; // xmm5_4
	float v19; // xmm2_4
	float v20; // xmm4_4
	float v21; // xmm0_4
	float v22; // xmm0_4
	float v23; // xmm2_4
	float v24; // xmm4_4

	Z = Current->z;
	Y = Current->y;
	W = Current->w;
	v7 = (float)(Current->x * Z) - (float)(Y * W);
	v8 = (float)((float)(Y * Current->x) + (float)(Y * Current->x)) + (float)((float)(W * Z) + (float)(W * Z));
	v9 = 1.0 - (float)((float)((float)(Y * Y) + (float)(Y * Y)) + (float)((float)(Z * Z) + (float)(Z * Z)));
	if (v7 >= -0.49999949)
	{
		if (v7 <= 0.49999949)
		{
			v18 = v7 + v7;
			v19 = v18;
			v20 = sqrtf(fmaxf(1.0 - v19, 0.0))
				* (float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)(0.0066700899 - (float)(v19 * 0.0012624911)) * v19)
					- 0.017088126)
					* v19)
					+ 0.03089188)
					* v19)
					- 0.050174303)
					* v19)
					+ 0.088978991)
					* v19)
					- 0.2145988)
					* v19)
					+ 1.5707963);
			if (v18 < 0.0)
				v21 = v20 - 1.5707963;
			else
				v21 = 1.5707963 - v20;
			retstr->Pitch = v21 * 57.295776;
			v22 = atan2(v8, v9);
			v23 = Current->x * Current->x;
			v24 = Current->w * Current->w;
			retstr->Yaw = v22 * 57.295776;
			v15 = atan2(
				(float)((float)(Current->y * Current->z) * -2.0) - (float)(v24 + v24),
				1.0 - (float)((float)(v23 + v23) + (float)((float)(Current->y * Current->y) + (float)(Current->y * Current->y))))
				* 57.295776;
			goto LABEL_13;
		}
		retstr->Pitch = 90.0;
		v16 = atan2(v8, v9);
		v17 = Current->w;
		retstr->Yaw = v16 * 57.295776;
		v14 = retstr->Yaw - (float)((float)(atan2(Current->w, v17) * 2.0) * 57.295776);
	}
	else
	{
		retstr->Pitch = -90.0;
		v10 = atan2(v8, v9);
		v11 = Current->w;
		v12 = v10 * 57.295776;
		X = Current->x;
		retstr->Yaw = v12;
		//v14 = COERCE_FLOAT(LODWORD(v12) ^ _xmm) - (float)((float)(FGenericPlatformMath::Atan2(X, v11) * 2.0) * 57.295776);
	}
LABEL_13:
	retstr->Roll = 0;
	return retstr;
}

D3DMATRIX MatrixMultiplication(D3DMATRIX pM1, D3DMATRIX pM2)
{
	D3DMATRIX pOut;
	pOut._11 = pM1._11 * pM2._11 + pM1._12 * pM2._21 + pM1._13 * pM2._31 + pM1._14 * pM2._41;
	pOut._12 = pM1._11 * pM2._12 + pM1._12 * pM2._22 + pM1._13 * pM2._32 + pM1._14 * pM2._42;
	pOut._13 = pM1._11 * pM2._13 + pM1._12 * pM2._23 + pM1._13 * pM2._33 + pM1._14 * pM2._43;
	pOut._14 = pM1._11 * pM2._14 + pM1._12 * pM2._24 + pM1._13 * pM2._34 + pM1._14 * pM2._44;
	pOut._21 = pM1._21 * pM2._11 + pM1._22 * pM2._21 + pM1._23 * pM2._31 + pM1._24 * pM2._41;
	pOut._22 = pM1._21 * pM2._12 + pM1._22 * pM2._22 + pM1._23 * pM2._32 + pM1._24 * pM2._42;
	pOut._23 = pM1._21 * pM2._13 + pM1._22 * pM2._23 + pM1._23 * pM2._33 + pM1._24 * pM2._43;
	pOut._24 = pM1._21 * pM2._14 + pM1._22 * pM2._24 + pM1._23 * pM2._34 + pM1._24 * pM2._44;
	pOut._31 = pM1._31 * pM2._11 + pM1._32 * pM2._21 + pM1._33 * pM2._31 + pM1._34 * pM2._41;
	pOut._32 = pM1._31 * pM2._12 + pM1._32 * pM2._22 + pM1._33 * pM2._32 + pM1._34 * pM2._42;
	pOut._33 = pM1._31 * pM2._13 + pM1._32 * pM2._23 + pM1._33 * pM2._33 + pM1._34 * pM2._43;
	pOut._34 = pM1._31 * pM2._14 + pM1._32 * pM2._24 + pM1._33 * pM2._34 + pM1._34 * pM2._44;
	pOut._41 = pM1._41 * pM2._11 + pM1._42 * pM2._21 + pM1._43 * pM2._31 + pM1._44 * pM2._41;
	pOut._42 = pM1._41 * pM2._12 + pM1._42 * pM2._22 + pM1._43 * pM2._32 + pM1._44 * pM2._42;
	pOut._43 = pM1._41 * pM2._13 + pM1._42 * pM2._23 + pM1._43 * pM2._33 + pM1._44 * pM2._43;
	pOut._44 = pM1._41 * pM2._14 + pM1._42 * pM2._24 + pM1._43 * pM2._34 + pM1._44 * pM2._44;

	return pOut;
}

std::string string_To_UTF8(const std::string& str)
{
	int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

	wchar_t* pwBuf = new wchar_t[nwLen + 1];
	ZeroMemory(pwBuf, nwLen * 2 + 2);

	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);

	int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	char* pBuf = new char[nLen + 1];
	ZeroMemory(pBuf, nLen + 1);

	::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	std::string retStr(pBuf);

	delete[]pwBuf;
	delete[]pBuf;

	pwBuf = NULL;
	pBuf = NULL;

	return retStr;
}




