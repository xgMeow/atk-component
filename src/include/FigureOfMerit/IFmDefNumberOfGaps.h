#pragma once
#include "../IAtkObj.h"
#include "IFmDefCompute.h" 

///
/// 品质因子定义：覆盖间隔次数
///
class IATKOBJECT_API IFmDefNumberOfGaps :public IFmDefCompute
{
public:
    IFmDefNumberOfGaps(const IFmDefNumberOfGaps&) = delete;
    IFmDefNumberOfGaps& operator=(const IFmDefNumberOfGaps&) = delete;

	IFmDefNumberOfGaps(AsCvFmDefn* pAsCvFmDefn);
	~IFmDefNumberOfGaps();

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
