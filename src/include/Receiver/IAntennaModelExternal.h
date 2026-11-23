#pragma once
#include "../IAtkObj.h"
#include "IAntennaModel.h" 
#include "../ICEnum.h"
struct CCRAntenna;

///
/// 天线模型 External
///
class IATKOBJECT_API IAntennaModelExternal :public IAntennaModel
{
public:
    IAntennaModelExternal(const IAntennaModelExternal&) = delete;
    IAntennaModelExternal& operator=(const IAntennaModelExternal&) = delete;

	IAntennaModelExternal(CCRAntenna* pCCRAntenna);
	virtual ~IAntennaModelExternal();

	//********************************************************************
	/// 获得 天线模型名称
	/// @author	Gan Shu Long
	/// @date	2026-03-16
	/// @return	天线模型名称
	//********************************************************************
	std::string GetName() { return "External Antenna Pattern"; }

	//********************************************************************
	/// 获得 天线模型类型
	/// @author	Gan Shu Long
	/// @date	2026-03-16
	/// @return	天线模型类型
	//********************************************************************
	EAntennaModelType GetType() { return eAntennaModelTypeExternal; }

	//********************************************************************
	/// 设置 文件路径
	/// @author	Gan Shu Long
	/// @date	2026-03-16
	/// @param[in]	strFilename 文件路径
	//********************************************************************
	void SetFilename(std::string  strFilename);

	//********************************************************************
	/// 获得 文件路径
	/// @author	Gan Shu Long
	/// @date	2026-03-16
	/// @return	文件路径
	//********************************************************************
	std::string  GetFilename();

private:
	CCRAntenna*					m_pCCRAntenna;					//天线结构体
};
