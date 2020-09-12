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
/// RGBA�l
/// </summary>
typedef cv::Vec4b RGBA;

/// <summary>
/// RGB�l
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
     * �R���X�g���N�^
     *
    \* *,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,* */

    //! �C���X�^���X���쐬���AAVIUTL����n����鐶�f�[�^���i�[���܂��B
    /// <summary>
    /// �C���X�^���X���쐬���AAviUtl����n����鐶�f�[�^���i�[���܂��B
    /// </summary>
    /// <param name="width">�t�B�����̕��ł��B</param>
    /// <param name="height">�t�B�����̍����ł��B</param>
    /// <param name="rawData">AviUtl����n����郆�[�U�[�f�[�^�ł��B</param>
    Film(const integer& width, const integer& height, byte* rawData);

    //! �w�肵���F�ŗ̈�𖄂ߐs�������߂̃R���X�g���N�^
    /// <summary>
    /// �C���X�^���X���쐬���A�w�肵���̈�𖄂ߐs�����܂��B
    /// </summary>
    /// <param name="width">�t�B�����̕��ł��B</param>
    /// <param name="height">�t�B�����̍����ł��B</param>
    /// <param name="defCol">�̈�𖄂ߐs�����ۂɎg�p����F�ł��B</param>
    Film(const integer& width, const integer& height, const RGBA& defCol);

    /// <summary>
    /// �w�肵���L�����o�X����t�B�������쐬���܂��B
    /// </summary>
    /// <param name="canvas">�t�B�����̍쐬�Ɏg�p����L�����o�X���ł��B</param>
    Film(const Canvas& canvas);

    /* *'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'* *\
     *
     * �f�X�g���N�^
     *
    \* *,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,* */

    ~Film();

    /* *'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'* *\
     *
     * ���W�w��n���\�b�h
     *
    \* *,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,* */

    /// <summary>
    /// �w�肵���s�N�Z���̎Q�Ƃ��擾���܂��B
    /// </summary>
    /// <param name="x">�擾����s�N�Z����X���W�ł��B���̒l��0����n�܂�C���f�b�N�X�ł��B</param>
    /// <param name="y">�擾����s�N�Z����Y���W�ł��B���̒l��0����n�܂�C���f�b�N�X�ł��B</param>
    /// <returns>�߂�l�Ƃ��Ď擾����s�N�Z���͑�����邱�Ƃɂ���ĎQ�ƌ��̃s�N�Z���i<see cref="Film"/>���̃s�N�Z���j��ύX���邱�Ƃ��o���܂��B</returns>
    RGBA& GetAndPutPixel(const integer& x, const integer& y);

    /// <summary>
    /// �w�肵���s�N�Z���̐F���擾���܂��B
    /// </summary>
    /// <param name="x">�擾����s�N�Z���̍��W�ł��B���̒l��0����n�܂�C���f�b�N�X�ł��B</param>
    /// <param name="y">�擾����s�N�Z����Y���W�ł��B���̒l��0����n�܂�C���f�b�N�X�ł��B</param>
    /// <returns>�ύX���̐F�ł��B</returns>
    RGBA GetPixel(const integer& x, const integer& y);

    /// <summary>
    /// �w�肵���s�N�Z���̐F��ύX���܂��B
    /// </summary>
    /// <param name="x">�ύX����s�N�Z����X���W�ł��B���̒l��0����n�܂�C���f�b�N�X�ł��B</param>
    /// <param name="y">�ύX����s�N�Z����Y���W�ł��B���̒l��0����n�܂�C���f�b�N�X�ł��B</param>
    /// <param name="putCol">�ύX��̐F�ł��B</param>
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
     * �R���X�g���N�^
     *
    \* *,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,*,* */

    Mask(const Canvas& src, const RGBAToMask& designer);

};
