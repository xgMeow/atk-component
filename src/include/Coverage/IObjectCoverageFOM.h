#pragma once
#include "../IAtkObject.h"
#include "../ICEnum.h"
#include <vector>
#include <string>
struct AsCvFmDefn;
class IFmDefinition;

///
/// 覆盖性品质因子
///
class IATKOBJECT_API IObjectCoverageFOM
{
public:
	IObjectCoverageFOM(const IObjectCoverageFOM&) = delete;
	IObjectCoverageFOM& operator=(const IObjectCoverageFOM&) = delete;

	IObjectCoverageFOM();
	~IObjectCoverageFOM();

	//********************************************************************
	/// 获得 支持的定义类型
	/// @author	Gan Shu Long
	/// @date	2026-10-14
	/// @return 支持的定义类型
	//********************************************************************
	std::vector<std::string> GetDefinitionSupportedTypes();

	//********************************************************************
	/// 获得 是否支持定义类型
	/// @author	Gan Shu Long
	/// @date	2026-10-14
	/// @param[in]	eFmDefinitionType  定义类型
	/// @return	bool 是否支持定义类型	
	//********************************************************************
	bool IsDefinitionTypeSupported(EFmDefinitionType eFmDefinitionType);

	//********************************************************************
	/// 设置 定义类型
	/// @author	Gan Shu Long
	/// @date	2026-10-14
	/// @param[in]	eFmDefinitionType  定义类型
	//********************************************************************
	void SetDefinitionType(EFmDefinitionType eFmDefinitionType);

	//********************************************************************
	/// 获得  定义类型
	/// @author	Gan Shu Long
	/// @date	2026-10-14
	/// @return	 定义类型
	//********************************************************************
	EFmDefinitionType GetDefinitionType();

	//********************************************************************
	/// 获得  定义
	/// @author	Gan Shu Long
	/// @date	2026-10-14
	/// @return	 定义
	//*******************************************************
	IFmDefinition* GetDefinition() { return m_Definition; }

private:
	AsCvFmDefn*						m_pAsCvFmDefn;

	IFmDefinition*					m_Definition;			//定义
};
