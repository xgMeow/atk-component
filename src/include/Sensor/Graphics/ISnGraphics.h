#pragma once
#include "../../IAtkObj.h"
//#include "ISnProjection.h"
#include "../../ICEnum.h"
class CSensor;
class ISnProjection;

///
/// 传感器二维
///
class IATKOBJECT_API ISnGraphics
{
public:
    ISnGraphics(const ISnGraphics&) = delete;
    ISnGraphics& operator=(const ISnGraphics&) = delete;

	ISnGraphics(CSensor* pCSensor);
	~ISnGraphics();

	//********************************************************************
	/// 设置是否显示
	/// @author	Gan Shu Long
	/// @date	2024-06-12
	/// @param[in]	bIsObjectGraphicsVisible  是否显示
	//********************************************************************
	void SetIsObjectGraphicsVisible(bool bIsObjectGraphicsVisible);

	//********************************************************************
	/// 获得是否显示
	/// @author	Gan Shu Long
	/// @date	2024-06-12
	/// @return	是否显示
	//********************************************************************
	bool GetIsObjectGraphicsVisible();

	//********************************************************************
	/// 设置是否填充
	/// @author	Gan Shu Long
	/// @date	2024-06-12
	/// @param[in]	bFillVisible  是否填充
	//********************************************************************
	void SetFillVisible(bool bFillVisible);

	//********************************************************************
	/// 获得是否填充
	/// @author	Gan Shu Long
	/// @date	2024-06-12
	/// @return	是否填充
	//********************************************************************
	bool GetFillVisible();

	//********************************************************************
	/// 设置二维显示颜色
	/// @author	Gan Shu Long
	/// @date	2024-06-12
	/// @param[in]	nColor  二维显示颜色，例绿色-65280
	//********************************************************************
	void SetColor(int nColor);

	//********************************************************************
	/// 获得二维显示颜色
	/// @author	Gan Shu Long
	/// @date	2024-06-12
	/// @return	二维显示颜色
	//********************************************************************
	int GetColor();

	//********************************************************************
	/// 设置线宽
	/// @author	Gan Shu Long
	/// @date	2024-06-12
	/// @param[in]	eLineWidth  轨迹线宽
	//********************************************************************
	void SetLineWidth(ELineWidth eLineWidth);

	//********************************************************************
	/// 获得线宽
	/// @author	Gan Shu Long
	/// @date	2024-06-12
	/// @return	轨迹线宽
	//********************************************************************
	ELineWidth GetLineWidth();
	
	//********************************************************************
	/// 获得 投影指针
	/// @author	Gan Shu Long
	/// @date	2026-03-24
	/// @return	投影指针
	//********************************************************************
	ISnProjection* GetProjection() { return m_Projection; }

private:
	CSensor*			m_pCSensor;
	ISnProjection*		m_Projection;
};

