#pragma once

#ifdef _OPENMP
#include <omp.h>
#endif

#include <lua.hpp>
#include <string>
#include <functional>
#include <thread>
#include <vector>
#include <memory>
#include "..\..\opencv\modules\core\include\opencv2\core.hpp"

using namespace std;

typedef unsigned long integer;
typedef unsigned char byte;


const char license[569] =
"���̃t�@�C����Apache License 2.0�ɂ���ĕی삳��Ă��܂��B\n\r"
"���̃t�@�C�������ς��邱�Ƃɂ���Ĕ��������u���ʕ�(Work)�v���Ĕz�z����ꍇ�́A�Ĕz�z�ł���|�Ɖ��L�̃����N��README.txt���ɋL�q���Ă��������B\n\r"
"����L�́u���ʕ��v�ɂ͂��̃A�j���[�V�������ʂ��g�p���Đ��삵��������܂�ł��܂���B�C�ɂ����Ɉ��S���Ă����p���������B\n\r"
"\n\r"
"THIS FILE IS PROTECTED BY APACHE LICENSE 2.0.\n\r"
"\n\r"
"Apache License 2.0: https://github.com/H-J-Ainashi/Aviutl-AnimationEffects/blob/master/LICENSE \n\r"
"GitHub: https://github.com/H-J-Ainashi/Aviutl-AnimationEffects \n\r"
"\n\r"
"Copyright 2020 H_J - Ainashi - ";


string getlicense();

struct RGBA
{

	byte b;
	byte g;
	byte r;
	byte a;

	/// <summary>
	/// �V�����C���X�^���X���쐬���܂��B
	/// </summary>
	/// <param name="b">�F�l�B</param>
	/// <param name="g">�ΐF�l�B</param>
	/// <param name="r">�ԐF�l�B</param>
	/// <param name="a">�����x�l�B</param>
	RGBA(const byte& b, const byte& g, const byte& r, const byte& a);

};

