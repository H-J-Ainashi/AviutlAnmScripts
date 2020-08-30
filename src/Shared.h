#pragma once

#ifdef _OPENMP
#include <omp.h>
#endif

#include <lua.hpp>
#include <string>
#include <functional>
#include <thread>
#include <vector>

using namespace std;

typedef unsigned long DWORD;
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


static string getlicense();

struct RGBA
{

	byte b;
	byte g;
	byte r;
	byte a;

};

typedef class _Canvas
{

public:
	
	_Canvas(int width, int height, RGBA* data)
	{

		canvas = new RGBA*[height];
		this->width = width;
		this->height = height;
		auto input = 0;

		for (int y = 0; y < height; ++y)
		{
			canvas[y] = new RGBA[width];

			for (int x = 0; x < width; ++x, ++input)
				canvas[y][x] = data[input];

		}

	}

	void Copy(RGBA* dest)
	{

		auto input = 0;

		for (int y = 0; y < height; ++y)
			for (int x = 0; x < width; ++x, ++input)
				dest[input] = canvas[y][x];

	}

	void PixelUpdater(RGBA(*converter)(int x, int y))
	{

		for (int y = 0; y < height; ++y)
			for (int x = 0; x < width; ++x)
				canvas[y][x] = converter(x, y);

	}

private:
	int width;
	int height;
	RGBA** canvas;
	
}Canvas;



void PixelConverter(RGBA* data, const int& width, const int& height, function<RGBA(int, int, RGBA)> converter);