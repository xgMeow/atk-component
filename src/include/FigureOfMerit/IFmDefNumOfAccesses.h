#pragma once
#include "../IAtkObj.h"
#include "IFmDefCompute.h" 

///
/// 品质因子定义：访问次数
///
class IATKOBJECT_API IFmDefNumOfAccesses :public IFmDefCompute
{
public:
    IFmDefNumOfAccesses(const IFmDefNumOfAccesses&) = delete;
    IFmDefNumOfAccesses& operator=(const IFmDefNumOfAccesses&) = delete;

	IFmDefNumOfAccesses(AsCvFmDefn* pAsCvFmDefn);
	~IFmDefNumOfAccesses();

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
};
