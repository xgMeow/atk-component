#pragma once
#include "../IAtkObj.h"
#include "IFmDefDilutionOfPrecision.h" 
class IFmUncertainties;

///
/// 品质因子定义：导航精度
///
class IATKOBJECT_API IFmDefNavigationAccuracy :public IFmDefDilutionOfPrecision
{
public:
    IFmDefNavigationAccuracy(const IFmDefNavigationAccuracy&) = delete;
    IFmDefNavigationAccuracy& operator=(const IFmDefNavigationAccuracy&) = delete;

	IFmDefNavigationAccuracy(AsCvFmDefn* pAsCvFmDefn);
	~IFmDefNavigationAccuracy();

	//********************************************************************
	/// 获得 支持的计算类型
	/// @author	Gan Shu Long
	/// @date	2026-05-11
	/// @return 支持的计算类型
	//********************************************************************
	std::vector<std::string> GetComputeSupportedTypes() override;

	//********************************************************************
	/// 获得 是否支持计算类型
	/// @author	Gan Shu Long
	/// @date	2026-05-11
	/// @param[in]	eFmCompute  计算类型
	/// @return	bool 是否支持计算类型	
	//********************************************************************
	bool IsComputeTypeSupported(EFmCompute eFmCompute) override;

	//********************************************************************
	/// 获得  不确定度
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @return	 不确定度
	//*******************************************************
	IFmUncertainties* GetUncertainties() { return m_Uncertainties; }

private:
	IFmUncertainties*					m_Uncertainties;
};
