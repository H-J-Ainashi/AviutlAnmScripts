#pragma once

#include <functional>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;
typedef long integer;
typedef unsigned long uinteger;
typedef long long longer;
typedef unsigned char byte;
typedef byte alpha;
typedef byte colorInfo;

/// <summary>
/// RGBA値
/// </summary>
typedef cv::Vec4b RGBA;

/// <summary>
/// RGB値
/// </summary>
typedef cv::Vec3b RGB;

typedef cv::Vec<byte, 1> A;

typedef cv::Mat Canvas;

typedef function<void(RGBA& dest, const RGBA& src)> FilmsBlender;
typedef function<void(RGBA& dest, const RGBA& src, alpha mask)> FilmsBlenderWithMask;
typedef function<void(RGBA& dest, const alpha& src)> RGBAMask;
typedef function<void(alpha& dest, const RGBA& src)> RGBAToMask;
typedef function<void(alpha& dest, const RGB& src)> RGBToMask;

class Film
{

private:

    Canvas film;
    RGBA** index;


public:

    /* *'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'* *\
     *
     * コンストラクタ
     *
    \* *,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,* */

    //! インスタンスを作成し、AVIUTLから渡される生データを格納します。
    /// <summary>
    /// インスタンスを作成し、AviUtlから渡される生データを格納します。
    /// </summary>
    /// <param name="width">フィルムの幅です。</param>
    /// <param name="height">フィルムの高さです。</param>
    /// <param name="rawData">AviUtlから渡されるユーザーデータです。</param>
    Film(const integer& width, const integer& height, byte* rawData);

    //! 指定した色で領域を埋め尽くすためのコンストラクタ
    /// <summary>
    /// インスタンスを作成し、指定した領域を埋め尽くします。
    /// </summary>
    /// <param name="width">フィルムの幅です。</param>
    /// <param name="height">フィルムの高さです。</param>
    /// <param name="defCol">領域を埋め尽くす際に使用する色です。</param>
    Film(const integer& width, const integer& height, const RGBA& defCol);

    /// <summary>
    /// 指定したキャンバスからフィルムを作成します。
    /// </summary>
    /// <param name="canvas">フィルムの作成に使用するキャンバス情報です。</param>
    Film(const Canvas& canvas);

    /* *'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'* *\
     *
     * デストラクタ
     *
    \* *,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,* */

    ~Film();

    /* *'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'* *\
     *
     * 座標指定系メソッド
     *
    \* *,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,* */

    /// <summary>
    /// 指定したピクセルの参照を取得します。
    /// </summary>
    /// <param name="x">取得するピクセルのX座標です。この値は0から始まるインデックスです。</param>
    /// <param name="y">取得するピクセルのY座標です。この値は0から始まるインデックスです。</param>
    /// <returns>戻り値として取得するピクセルは代入することによって参照元のピクセル（<see cref="Film"/>内のピクセル）を変更することが出来ます。</returns>
    RGBA& GetAndPutPixel(const integer& x, const integer& y);

    /// <summary>
    /// 指定したピクセルの色を取得します。
    /// </summary>
    /// <param name="x">取得するピクセルの座標です。この値は0から始まるインデックスです。</param>
    /// <param name="y">取得するピクセルのY座標です。この値は0から始まるインデックスです。</param>
    /// <returns>変更元の色です。</returns>
    RGBA GetPixel(const integer& x, const integer& y);

    /// <summary>
    /// 指定したピクセルの色を変更します。
    /// </summary>
    /// <param name="x">変更するピクセルのX座標です。この値は0から始まるインデックスです。</param>
    /// <param name="y">変更するピクセルのY座標です。この値は0から始まるインデックスです。</param>
    /// <param name="putCol">変更先の色です。</param>
    void PutPixel(const integer& x, const integer& y, const RGBA& putCol);

};

class Mask
{

private:

    Canvas mask;
    A** index;

public:


    /* *'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'* *\
     *
     * コンストラクタ
     *
    \* *,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,* */

    Mask(const Canvas& src, const RGBAToMask& designer);

};
