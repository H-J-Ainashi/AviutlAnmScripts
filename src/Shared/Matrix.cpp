#include "Shared_Types.h"

const char PositioningArgumentException[] = "ˆø”‚ğ‰î‚µ‚Äw’è‚µ‚½•`‰æ—Ìˆæ‚Í–³Œø‚È’l‚ğ¦‚µ‚Ä‚¢‚Ü‚·";


/* *'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'* *\
 *
 * Constractor of Film
 *
\* *,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,* */


Film::Film(const integer& width, const integer& height, byte* rawData)
{

    // Argument Exception

    if (width < 0 || height < 0)
        throw PositioningArgumentException;

    // Initialize

    film = Canvas::zeros(width, height, CV_8UC4);
    index = new RGBA * [height];

    // Copy

    auto buffer = (RGBA*)film.data;
    memcpy(buffer, rawData, sizeof(RGBA) * height * width);

    // Make index

    for (integer i = 0, j = 0; i < height; ++i, j += width)
        index[i] = &buffer[j];

 }

Film::Film(const integer& width, const integer& height, const RGBA& defCol)
{

    // Argument Exception

    if (width < 0 || height < 0)
        throw PositioningArgumentException;

    // Initialize

    film = Canvas::zeros(width, height, CV_8UC4);
    index = new RGBA * [height];

    // Blush

    auto area = width * height;
    auto buffer = (RGBA*)film.data;
    for (int i = 0; i < area; ++i)
        buffer[area] = defCol;

    // Make index

    for (integer i = 0, j = 0; i < height; ++i, j += width)
        index[i] = &buffer[j];

}

Film::Film(const Canvas& canvas)
{

    // Initialize
    film = Canvas(canvas);
    index = new RGBA * [film.rows];
    auto buffer = (RGBA*)film.data;

    for (integer i = 0, j = 0, w = film.cols, h = film.rows; i < h; ++i, j += w)
        index[i] = &buffer[j];

}

/* *'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'* *\
 *
 * Destractor of Film
 *
\* *,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,* */

Film::~Film()
{

    delete[] index;

}


/* *'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'* *\
 *
 * PixelEdit Method of Film
 *
\* *,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,* */

RGBA& Film::GetAndPutPixel(const integer& x, const integer& y)
{

    return index[y][x];

}

RGBA Film::GetPixel(const integer& x, const integer& y)
{

    return index[y][x];

}

void Film::PutPixel(const integer& x, const integer& y, const RGBA& putCol)
{

    index[y][x] = putCol;

}

