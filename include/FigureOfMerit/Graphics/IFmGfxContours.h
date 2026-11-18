#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
struct GfxFOMGraphics;
class IFmGfxLevelAttributesCollection;
class IFmGfxRampColor;

///
/// 分级轮廓
///
class IATKOBJECT_API IFmGfxContours
{
public:
    IFmGfxContours(const IFmGfxContours&) = delete;
    IFmGfxContours& operator=(const IFmGfxContours&) = delete;

	IFmGfxContours(GfxFOMGraphics* pGfxFOMGraphics);
	~IFmGfxContours();

	//********************************************************************
	/// 设置 是否显示分级轮廓 Contours(否则显示有效区域Satisfaction )
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	/// @param[in]	bIsVisible  是否显示分级轮廓
	//********************************************************************
	void SetIsVisible(bool bIsVisible);

	//********************************************************************
	/// 获得 是否显示分级轮廓
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	/// @return 是否显示分级轮廓
	//********************************************************************
	bool GetIsVisible();

	//********************************************************************
	/// 获得 分级属性列表
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	/// @return	分级属性列表
	//********************************************************************
	IFmGfxLevelAttributesCollection* GetLevelAttributes() { return m_LevelAttributes; }

	//********************************************************************
	/// 设置 是否显示品质因子值超出最大级别的区域
	/// @author	Gan Shu Long
	/// @date	2026-05-13
	/// @param[in]	bIsShowUpToMaxOnly  是否显示品质因子值超出最大级别的区域
	//********************************************************************
	void SetIsShowUpToMaxOnly(bool bIsShowUpToMaxOnly);

	//********************************************************************
	/// 获得 是否显示品质因子值超出最大级别的区域
	/// @author	Gan Shu Long
	/// @date	2026-05-13
	/// @return 是否显示品质因子值超出最大级别的区域
	//********************************************************************
	bool GetIsShowUpToMaxOnly();
	
	//********************************************************************
	/// 设置 取色类型
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	/// @param[in]	eFmGfxColorMethod  取色类型
	//********************************************************************
	void SetColorMethod(EFmGfxColorMethod eFmGfxColorMethod);

	//********************************************************************
	/// 获得  取色类型
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	/// @return	 取色类型
	//********************************************************************
	EFmGfxColorMethod GetColorMethod();

	//********************************************************************
	/// 获得 色阶
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	/// @return	色阶
	//********************************************************************
	IFmGfxRampColor* GetRampColor() { return m_RampColor; }

	//********************************************************************
	/// 设置 轮廓线插值类型
	/// @author	Gan Shu Long
	/// @date	2026-05-13
	/// @param[in]	eFmGfxContourType  轮廓线插值类型
	//********************************************************************
	void SetContourType(EFmGfxContourType eFmGfxContourType);

	//********************************************************************
	/// 获得  轮廓线插值类型
	/// @author	Gan Shu Long
	/// @date	2026-05-13
	/// @return	 轮廓线插值类型
	//********************************************************************
	EFmGfxContourType GetContourType();

	//********************************************************************
	/// 设置 插值采样类型
	/// @author	Gan Shu Long
	/// @date	2026-05-13
	/// @param[in]	eFmGfxSampleType  插值采样类型
	//********************************************************************
	void SetSampleType(EFmGfxSampleType eFmGfxSampleType);

	//********************************************************************
	/// 获得  插值采样类型
	/// @author	Gan Shu Long
	/// @date	2026-05-13
	/// @return	 插值采样类型
	//********************************************************************
	EFmGfxSampleType GetSampleType();

	//********************************************************************
	/// 设置 每个网格插值点数
	/// @author	Gan Shu Long
	/// @date	2026-05-13
	/// @param[in]	dSamplePointNum  每个网格插值点数
	//********************************************************************
	void SetSamplePointNum(double dSamplePointNum);

	//********************************************************************
	/// 获得  每个网格插值点数
	/// @author	Gan Shu Long
	/// @date	2026-05-13
	/// @return	 每个网格插值点数
	//********************************************************************
	double GetSamplePointNum();

	//********************************************************************
	/// 设置 是否显示等高线
	/// @author	Gan Shu Long
	/// @date	2026-05-13
	/// @param[in]	bIsShowContourLines  是否显示等高线
	//********************************************************************
	void SetIsShowContourLines(bool bIsShowContourLines);

	//********************************************************************
	/// 获得 是否显示等高线
	/// @author	Gan Shu Long
	/// @date	2026-05-13
	/// @return 是否显示等高线
	//********************************************************************
	bool GetIsShowContourLines();

	//********************************************************************
	/// 设置 等高线线宽
	/// @author	Gan Shu Long
	/// @date	2026-05-13
	/// @param[in]	eLineWidth  等高线线宽
	//********************************************************************
	void SetLineWidth(ELineWidth eLineWidth);

	//********************************************************************
	/// 获得 等高线线宽
	/// @author	Gan Shu Long
	/// @date	2026-05-13
	/// @return 等高线线宽
	//********************************************************************
	ELineWidth GetLineWidth();

	//********************************************************************
	/// 设置 是否自定义颜色
	/// @author	Gan Shu Long
	/// @date	2026-05-13
	/// @param[in]	bIsCustomColor  是否自定义颜色
	//********************************************************************
	void SetIsCustomColor(bool bIsCustomColor);

	//********************************************************************
	/// 获得 是否自定义颜色
	/// @author	Gan Shu Long
	/// @date	2026-05-13
	/// @return 是否自定义颜色
	//********************************************************************
	bool GetIsCustomColor();

	//********************************************************************
	/// 设置 自定义颜色
	/// @author	Gan Shu Long
	/// @date	2026-05-13
	/// @param[in]	nCustomColor  自定义颜色
	//********************************************************************
	void SetCustomColor(int nCustomColor);

	//********************************************************************
	/// 获得 自定义颜色
	/// @author	Gan Shu Long
	/// @date	2026-05-13
	/// @return 自定义颜色
	//********************************************************************
	int GetCustomColor();

private:
	GfxFOMGraphics*							m_pGfxFOMGraphics;

	IFmGfxLevelAttributesCollection*	m_LevelAttributes;
	IFmGfxRampColor*						m_RampColor;
};

