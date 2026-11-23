#pragma once
#include "ISnPattern.h"
class CSensor;

///
/// 模式类型：简单圆锥
///
class IATKOBJECT_API ISnSimpleConicPattern : public ISnPattern
{
public:
    ISnSimpleConicPattern(const ISnSimpleConicPattern&) = delete;
    ISnSimpleConicPattern& operator=(const ISnSimpleConicPattern&) = delete;

	ISnSimpleConicPattern(CSensor* pCSensor);
	~ISnSimpleConicPattern();

	//********************************************************************
	/// 设置 半锥角
	/// @author	Gan Shu Long
	/// @date	2025-07-10
	/// @param[in]	dConeAngle  半锥角
	//********************************************************************
	void SetConeAngle(double dConeAngle);

	//********************************************************************
	/// 获得 半锥角
	/// @author	Gan Shu Long
	/// @date	2025-07-10
	/// @return	double 半锥角	
	//********************************************************************
	double GetConeAngle();

private:
	CSensor*			m_pCSensor;
};

