#pragma once
#include "../IAtkObj.h"
#include "IFmDefCompute.h" 

///
/// 品质因子定义：覆盖时间
///
class IATKOBJECT_API IFmDefCoverageTime :public IFmDefCompute
{
public:
    IFmDefCoverageTime(const IFmDefCoverageTime&) = delete;
    IFmDefCoverageTime& operator=(const IFmDefCoverageTime&) = delete;

	IFmDefCoverageTime(AsCvFmDefn* pAsCvFmDefn);
	~IFmDefCoverageTime();

	//********************************************************************
	/// 获得 支持的计算类型
	/// @author	Gan Shu Long
	/// @date	2026-05-09
	/// @return 支持的计算类型
	//********************************************************************
	std::vector<std::string> GetComputeSupportedTypes() override;

	//********************************************************************
	/// 获得 是否支持计算类型
	/// @author	Gan Shu Long
	/// @date	2026-05-09
	/// @param[in]	eFmCompute  计算类型
	/// @return	bool 是否支持计算类型	
	//********************************************************************
	bool IsComputeTypeSupported(EFmCompute eFmCompute) override;
};
