#pragma once
#include "../IAtkObj.h"
#include "IFmDefinitionData.h" 

///
/// 品质因子定义数据：百分比高于
///
class IATKOBJECT_API IFmDefDataPercentLevel :public IFmDefinitionData
{
public:
    IFmDefDataPercentLevel(const IFmDefDataPercentLevel&) = delete;
    IFmDefDataPercentLevel& operator=(const IFmDefDataPercentLevel&) = delete;

	IFmDefDataPercentLevel(AsCvFmDefn* pAsCvFmDefn);
	~IFmDefDataPercentLevel();

	//********************************************************************
	/// 设置  值
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @param[in]	dPercentLevel 值
	//********************************************************************
	void SetPercentLevel(double dPercentLevel);

	//********************************************************************
	/// 获得 值
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @return	值
	//********************************************************************
	double GetPercentLevel();
};
