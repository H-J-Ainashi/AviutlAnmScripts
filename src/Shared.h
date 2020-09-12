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
"このファイルはApache License 2.0によって保護されています。\n\r"
"このファイルを改変することによって発生した「成果物(Work)」を再配布する場合は、再配布である旨と下記のリンクをREADME.txt等に記述してください。\n\r"
"※上記の「成果物」にはこのアニメーション効果を使用して制作した動画を含んでいません。気にせずに安心してご利用ください。\n\r"
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
	/// 新しいインスタンスを作成します。
	/// </summary>
	/// <param name="b">青色値。</param>
	/// <param name="g">緑色値。</param>
	/// <param name="r">赤色値。</param>
	/// <param name="a">透明度値。</param>
	RGBA(const byte& b, const byte& g, const byte& r, const byte& a);

};

