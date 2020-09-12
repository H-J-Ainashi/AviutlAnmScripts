#pragma once

#include "Shared_Types.h"


/* *'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'* *\
 *
 * 画素編集系メソッド
 *
\* *,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,* */

/// <summary>
/// RGBA構造体から赤色情報を取得します。
/// </summary>
/// <param name="rgba">赤色情報を格納するRGBA構造体です。</param>
/// <returns></returns>
inline byte GetRed(const RGBA& rgba);

/// <summary>
/// RGB構造体から赤色情報を取得します。
/// </summary>
/// <param name="rgb">赤色情報を格納するRGB構造体です。</param>
/// <returns></returns>
inline byte GetRed(const RGB& rgb);

/// <summary>
/// RGBA構造体から緑色情報を取得します。
/// </summary>
/// <param name="rgba">緑色情報を格納するRGBA構造体です。</param>
/// <returns></returns>
inline byte GetGreen(const RGBA& rgba);

/// <summary>
/// RGB構造体から緑色情報を取得します。
/// </summary>
/// <param name="rgb">緑色情報を格納するRGB構造体です。</param>
/// <returns></returns>
inline byte GetGreen(const RGB& rgb);

/// <summary>
/// RGBA構造体から青色情報を取得します。
/// </summary>
/// <param name="rgba">青色情報を格納するRGBA構造体です。</param>
/// <returns></returns>
inline byte GetBlue(const RGBA& rgba);

/// <summary>
/// RGB構造体から青色情報を取得します。
/// </summary>
/// <param name="rgb">青色情報を格納するRGB構造体です。</param>
/// <returns></returns>
inline byte GetBlue(const RGB& rgb);

/// <summary>
/// RGBA構造体から透明度情報を取得します。
/// </summary>
/// <param name="rgba">透明度情報を格納するRGBA構造体です。</param>
/// <returns></returns>
inline byte GetAlpha(const RGBA& rgba);

/// <summary>
/// RGBA構造体に赤色情報を格納します。
/// </summary>
/// <param name="rgba">赤色情報を格納するRGBA構造体です。</param>
/// <param name="red">格納する赤色情報です。</param>
inline void PutRed(RGBA& rgba, const byte& red);

/// <summary>
/// RGB構造体に赤色情報を格納します。
/// </summary>
/// <param name="rgb">赤色情報を格納するRGB構造体です。</param>
/// <param name="red">格納する赤色情報です。</param>
inline void PutRed(RGB& rgb, const byte& red);

/// <summary>
/// RGBA構造体に緑色情報を格納します。
/// </summary>
/// <param name="rgba">緑色情報を格納するRGBA構造体です。</param>
/// <param name="green">格納する緑色情報です。</param>
inline void PutGreen(RGBA& rgba, const byte& green);

/// <summary>
/// RGB構造体に緑色情報を格納します。
/// </summary>
/// <param name="rgb">緑色情報を格納するRGB構造体です。</param>
/// <param name="green">格納する緑色情報です。</param>
inline void PutGreen(RGB& rgb, const byte& green);

/// <summary>
/// RGBA構造体に青色情報を格納します。
/// </summary>
/// <param name="rgba">青色情報を格納するRGBA構造体です。</param>
/// <param name="blue">格納する青色情報です。</param>
inline void PutBlue(RGBA& rgba, const byte& blue);

/// <summary>
/// RGB構造体に青色情報を格納します。
/// </summary>
/// <param name="rgb">青色情報を格納するRGB構造体です。</param>
/// <param name="blue">格納する青色情報です。</param>
inline void PutBlue(RGB& rgb, const byte& blue);

/// <summary>
/// RGBA構造体に透明度情報を格納します。
/// </summary>
/// <param name="rgba">透明度情報を格納するRGBA構造体です。</param>
/// <param name="alpha">格納する透明度情報です。</param>
inline void PutAlpha(RGBA rgba, const byte& alpha);
