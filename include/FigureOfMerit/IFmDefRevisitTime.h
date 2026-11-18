#pragma once
#include "../IAtkObj.h"
#include "../ICEnum.h"
#include "IFmDefResponseTime.h" 

///
/// 品质因子定义：重访时间
///
class IATKOBJECT_API IFmDefRevisitTime :public IFmDefResponseTime
{
public:
    IFmDefRevisitTime(const IFmDefRevisitTime&) = delete;
    IFmDefRevisitTime& operator=(const IFmDefRevisitTime&) = delete;

	IFmDefRevisitTime(AsCvFmDefn* pAsCvFmDefn);
	~IFmDefRevisitTime();

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

	//********************************************************************
	/// 设置 结尾间隔段类型
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @param[in]	eFmEndGapOption  结尾间隔段类型
	//********************************************************************
	void SetEndGapOption(EFmEndGapOption eFmEndGapOption);

	//********************************************************************
	/// 获得  结尾间隔段类型
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @return	 结尾间隔段类型
	//********************************************************************
	EFmEndGapOption GetEndGapOption();
};
