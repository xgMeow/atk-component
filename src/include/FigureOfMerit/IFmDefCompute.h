#pragma once
#include "../IAtkObj.h"
#include "IFmDefinition.h" 
#include "../ICEnum.h"
#include <vector>
#include <string>
class IFmDefinitionData;

///
/// 品质因子定义：多重覆盖
///
class IATKOBJECT_API IFmDefCompute :public IFmDefinition
{
public:
    IFmDefCompute(const IFmDefCompute&) = delete;
    IFmDefCompute& operator=(const IFmDefCompute&) = delete;

	IFmDefCompute(AsCvFmDefn* pAsCvFmDefn);
	~IFmDefCompute();

	//********************************************************************
	/// 获得 支持的计算类型
	/// @author	Gan Shu Long
	/// @date	2026-05-09
	/// @return 支持的计算类型
	//********************************************************************
	virtual std::vector<std::string> GetComputeSupportedTypes();

	//********************************************************************
	/// 获得 是否支持计算类型
	/// @author	Gan Shu Long
	/// @date	2026-05-09
	/// @param[in]	eFmCompute  计算类型
	/// @return	bool 是否支持计算类型	
	//********************************************************************
	virtual bool IsComputeTypeSupported(EFmCompute eFmCompute);

	//********************************************************************
	/// 设置 计算类型
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @param[in]	eFmCompute  计算类型
	//********************************************************************
	void SetComputeType(EFmCompute eFmCompute);

	//********************************************************************
	/// 获得  计算类型
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @return	 计算类型
	//********************************************************************
	EFmCompute GetComputeType();

	//********************************************************************
	/// 获得  计算
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @return	 计算
	//*******************************************************
	IFmDefinitionData* GetCompute() { return m_Compute; }

private:
	IFmDefinitionData*					m_Compute;
};
