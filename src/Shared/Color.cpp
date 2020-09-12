#pragma once
#include "Shared_Color.h"
#include <algorithm>

//   Constractor of RGBA

RGBA GetRGBA(const byte& r, const byte& g, const byte& b, const byte& a)
{

    return RGBA(b, g, r, a);

}

RGB GetRGB(const byte& r, const byte& g, const byte& b)
{

    return RGB(b, g, r);

}

/* *'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'* *\
 *
 * Editor of RGBA
 *
\* *,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,* */

byte GetBlue(const RGBA& rgba)
{

    return rgba[0];

}

byte GetGreen(const RGBA& rgba)
{

    return rgba[1];

}

byte GetRed(const RGBA& rgba)
{

    return rgba[2];

}

byte GetAlpha(const RGBA& rgba)
{

    return rgba[3];

}

void PutBlue(RGBA& rgba, const byte& blue)
{

    rgba[0] = blue;

}

void PutGreen(RGBA& rgba, const byte& green)
{

    rgba[1] = green;

}

void PutRed(RGBA& rgba, const byte& red)
{

    rgba[2] = red;

}

void PutAllpha(RGBA& rgba, const byte& alpha)
{

    rgba[3] = alpha;

}


/* *'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'* *\
 *
 * Editor of RGB
 *
\* *,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,* */

byte GetBlue(const RGB& rgb)
{

    return rgb[0];

}

byte GetGreen(const RGB& rgb)
{

    return rgb[1];

}

byte GetRed(const RGB& rgb)
{

    return rgb[2];

}

void PutBlue(RGB& rgb, const byte& blue)
{

    rgb[0] = blue;

}

void PutGreen(RGB& rgb, const byte& green)
{

    rgb[1] = green;

}

void PutRed(RGB& rgb, const byte& red)
{

    rgb[2] = red;

}