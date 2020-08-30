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