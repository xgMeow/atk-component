#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
class CStar;
class IVODataDisplayCollection;

///
/// 二维
///
class IATKOBJECT_API IStGraphics
{
public:
    IStGraphics(const IStGraphics&) = delete;
    IStGraphics& operator=(const IStGraphics&) = delete;

	IStGraphics(CStar* pCStar);
	~IStGraphics();

	//********************************************************************
	/// 设置 是否显示
	/// @author	Gan Shu Long
	/// @date	2024-06-12
	/// @param[in]	bIsObjectGraphicsVisible  是否显示
	//********************************************************************
	void SetIsObjectGraphicsVisible(bool bIsObjectGraphicsVisible);

	//********************************************************************
	/// 获得 是否显示
	/// @author	Gan Shu Long
	/// @date	2024-06-12
	/// @return	是否显示
	//********************************************************************
	bool GetIsObjectGraphicsVisible();

	//********************************************************************
	/// 设置 是否显示标签
	/// @author	Gan Shu Long
	/// @date	2026-03-09
	/// @param[in]	bLabelVisible  是否显示标签
	//********************************************************************
	void SetLabelVisible(bool bLabelVisible);

	//********************************************************************
	/// 获得 是否显示标签
	/// @author	Gan Shu Long
	/// @date	2026-03-09
	/// @return	是否显示标签
	//********************************************************************
	bool GetLabelVisible();

	//********************************************************************
	/// 设置二维显示颜色
	/// @author	Gan Shu Long
	/// @date	2024-06-11
	/// @param[in]	nColor  二维显示颜色，例绿色-65280
	//********************************************************************
	void SetColor(int nColor);

	//********************************************************************
	/// 获得二维显示颜色
	/// @author	Gan Shu Long
	/// @date	2024-06-11
	/// @return	二维显示颜色
	//********************************************************************
	int GetColor();

	//********************************************************************
	/// 获得三维数据显示属性
	/// @author	Gan Shu Long
	/// @date	2026-03-09
	/// @return	三维数据显示指针		
	//********************************************************************
	IVODataDisplayCollection* GetDataDisplay() { return m_DataDisplay; }

private:
	CStar*										m_pCStar;
	IVODataDisplayCollection*		m_DataDisplay;				//三维数据显示指针
};

