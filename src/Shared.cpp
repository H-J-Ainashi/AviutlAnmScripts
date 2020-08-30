#include "Shared.h"

string getlicense()
{

	return license;

}


void PixelConverter(RGBA* data, const int& width, const int& height, function<RGBA(int, int, RGBA)> converter)
{

	int l = width * height;

	for (int i = 0; i < l; i++)
	{

		int x = i % width;
		int y = i / height;
		data[i] = converter(x, y, data[i]);

	}

}