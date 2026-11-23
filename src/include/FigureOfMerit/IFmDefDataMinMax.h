#pragma once
#include "../IAtkObj.h"
#include "IFmDefinitionData.h" 

///
/// 品质因子定义数据：最大值最小值
///
class IATKOBJECT_API IFmDefDataMinMax :public IFmDefinitionData
{
public:
    IFmDefDataMinMax(const IFmDefDataMinMax&) = delete;
    IFmDefDataMinMax& operator=(const IFmDefDataMinMax&) = delete;

	IFmDefDataMinMax(AsCvFmDefn* pAsCvFmDefn);
	~IFmDefDataMinMax();

	//********************************************************************
	/// 设置  最大值
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @param[in]	dMaxValue 最大值
	//********************************************************************
	void SetMaxValue(double dMaxValue);

	//********************************************************************
	/// 获得 最大值
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @return	最大值
	//********************************************************************
	double GetMaxValue();

	//********************************************************************
	/// 设置  最小值
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @param[in]	dMinValue 最小值
	//********************************************************************
	void SetMinValue(double dMinValue);

	//********************************************************************
	/// 获得 最小值
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @return	最小值
	//********************************************************************
	double GetMinValue();
};
