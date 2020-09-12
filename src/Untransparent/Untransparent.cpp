#pragma once
#include "Untransparent.h"
#include <lua.hpp>
#ifdef _OPENMP
#	include <omp.h>
#endif

using namespace std;


int Untransparent(lua_State* L)
{

	char s[512];
	RGBA* data;
	integer w, h, inverted, targetARGB;
	byte targetA, targetR, targetG, targetB;

	int argn = lua_gettop(L);

	if (8 != argn)
	{

		sprintf_s(s, "%s: line %d: invalid args number(%d)", __FILE__, __LINE__, argn);
		return luaL_error(L, s);

	}
	if (!lua_isuserdata(L, 1))
	{

		sprintf_s(s, "%s: line %d: invalid argument.", __FILE__, __LINE__);
		return luaL_error(L, s);

	}

	data = reinterpret_cast<RGBA*>(lua_touserdata(L, 1));
	w = (integer)lua_tointeger(L, 2);
	h = (integer)lua_tointeger(L, 3);
	inverted = (integer)lua_tointeger(L, 4);
	targetA = (integer)lua_tointeger(L, 5);
	targetR = (integer)lua_tointeger(L, 6);
	targetG = (integer)lua_tointeger(L, 7);
	targetB = (integer)lua_tointeger(L, 8);
	lua_settop(L, 1);

	for (int i = 0, l = w * h; i < l; i++)
		if (data[i].a == 0)
		{

			data[i].a = targetA;
			data[i].r = targetR;
			data[i].g = targetG;
			data[i].b = targetB;

		}

		else if (data[i].a == 255)
			if (inverted == 1)
			{

				data[i].a = 0;
				data[i].r = targetR;
				data[i].g = targetG;
				data[i].b = targetB;

			}
			else
				continue;
		else if (inverted == 1)
		{

			data[i].a = targetA - ((targetA * data[i].a) / 255);
			data[i].r = targetR;
			data[i].g = targetG;
			data[i].b = targetB;

		}
		else
		{

			data[i].r = (data[i].r * data[i].a + targetR * (255 - data[i].a)) / 255;
			data[i].g = (data[i].g * data[i].a + targetG * (255 - data[i].a)) / 255;
			data[i].b = (data[i].b * data[i].a + targetB * (255 - data[i].a)) / 255;
			data[i].a = targetA + ((255 - targetA) * data[i].a) / 255;

		}

	return 1;

}