#pragma once

#include "Shared_Types.h"


/* *'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'* *\
 *
 * ��f�ҏW�n���\�b�h
 *
\* *,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,* */

/// <summary>
/// RGBA�\���̂���ԐF�����擾���܂��B
/// </summary>
/// <param name="rgba">�ԐF�����i�[����RGBA�\���̂ł��B</param>
/// <returns></returns>
inline byte GetRed(const RGBA& rgba);

/// <summary>
/// RGB�\���̂���ԐF�����擾���܂��B
/// </summary>
/// <param name="rgb">�ԐF�����i�[����RGB�\���̂ł��B</param>
/// <returns></returns>
inline byte GetRed(const RGB& rgb);

/// <summary>
/// RGBA�\���̂���ΐF�����擾���܂��B
/// </summary>
/// <param name="rgba">�ΐF�����i�[����RGBA�\���̂ł��B</param>
/// <returns></returns>
inline byte GetGreen(const RGBA& rgba);

/// <summary>
/// RGB�\���̂���ΐF�����擾���܂��B
/// </summary>
/// <param name="rgb">�ΐF�����i�[����RGB�\���̂ł��B</param>
/// <returns></returns>
inline byte GetGreen(const RGB& rgb);

/// <summary>
/// RGBA�\���̂���F�����擾���܂��B
/// </summary>
/// <param name="rgba">�F�����i�[����RGBA�\���̂ł��B</param>
/// <returns></returns>
inline byte GetBlue(const RGBA& rgba);

/// <summary>
/// RGB�\���̂���F�����擾���܂��B
/// </summary>
/// <param name="rgb">�F�����i�[����RGB�\���̂ł��B</param>
/// <returns></returns>
inline byte GetBlue(const RGB& rgb);

/// <summary>
/// RGBA�\���̂��瓧���x�����擾���܂��B
/// </summary>
/// <param name="rgba">�����x�����i�[����RGBA�\���̂ł��B</param>
/// <returns></returns>
inline byte GetAlpha(const RGBA& rgba);

/// <summary>
/// RGBA�\���̂ɐԐF�����i�[���܂��B
/// </summary>
/// <param name="rgba">�ԐF�����i�[����RGBA�\���̂ł��B</param>
/// <param name="red">�i�[����ԐF���ł��B</param>
inline void PutRed(RGBA& rgba, const byte& red);

/// <summary>
/// RGB�\���̂ɐԐF�����i�[���܂��B
/// </summary>
/// <param name="rgb">�ԐF�����i�[����RGB�\���̂ł��B</param>
/// <param name="red">�i�[����ԐF���ł��B</param>
inline void PutRed(RGB& rgb, const byte& red);

/// <summary>
/// RGBA�\���̂ɗΐF�����i�[���܂��B
/// </summary>
/// <param name="rgba">�ΐF�����i�[����RGBA�\���̂ł��B</param>
/// <param name="green">�i�[����ΐF���ł��B</param>
inline void PutGreen(RGBA& rgba, const byte& green);

/// <summary>
/// RGB�\���̂ɗΐF�����i�[���܂��B
/// </summary>
/// <param name="rgb">�ΐF�����i�[����RGB�\���̂ł��B</param>
/// <param name="green">�i�[����ΐF���ł��B</param>
inline void PutGreen(RGB& rgb, const byte& green);

/// <summary>
/// RGBA�\���̂ɐF�����i�[���܂��B
/// </summary>
/// <param name="rgba">�F�����i�[����RGBA�\���̂ł��B</param>
/// <param name="blue">�i�[����F���ł��B</param>
inline void PutBlue(RGBA& rgba, const byte& blue);

/// <summary>
/// RGB�\���̂ɐF�����i�[���܂��B
/// </summary>
/// <param name="rgb">�F�����i�[����RGB�\���̂ł��B</param>
/// <param name="blue">�i�[����F���ł��B</param>
inline void PutBlue(RGB& rgb, const byte& blue);

/// <summary>
/// RGBA�\���̂ɓ����x�����i�[���܂��B
/// </summary>
/// <param name="rgba">�����x�����i�[����RGBA�\���̂ł��B</param>
/// <param name="alpha">�i�[���铧���x���ł��B</param>
inline void PutAlpha(RGBA rgba, const byte& alpha);
