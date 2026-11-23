#pragma once
#include "../IAtkObj.h"
#include "IFmDefCompute.h" 

///
/// 品质因子定义：数据时龄
///
class IATKOBJECT_API IFmDefAgeOfData :public IFmDefCompute
{
public:
    IFmDefAgeOfData(const IFmDefAgeOfData&) = delete;
    IFmDefAgeOfData& operator=(const IFmDefAgeOfData&) = delete;

	IFmDefAgeOfData(AsCvFmDefn* pAsCvFmDefn);
	~IFmDefAgeOfData();

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
	/// 设置  最少重数
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @param[in]	nMinAssets 最少重数
	//********************************************************************
	void SetMinAssets(int nMinAssets);

	//********************************************************************
	/// 获得 最少重数
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @return	最少重数
	//********************************************************************
	int GetMinAssets();
};
