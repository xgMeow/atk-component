#pragma once
#include "../IAtkObj.h"
#include <string> 
#include "../IClassInfo.h"
#include "../ICEnum.h"

///
/// 解调器模型
///
class IATKOBJECT_API IDemodulatorModel :public IClassInfo
{
public:
    IDemodulatorModel(const IDemodulatorModel&) = delete;
    IDemodulatorModel& operator=(const IDemodulatorModel&) = delete;

	IDemodulatorModel();
	virtual ~IDemodulatorModel();
	
	//********************************************************************
	/// 获得 解调器模型名称
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	解调器模型名称
	//********************************************************************
	std::string GetName() { return ""; }
	
	//********************************************************************
	/// 获得 解调器模型类型
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	解调器模型类型
	//********************************************************************
	EDemodulatorModelType GetType() { return eDemodulatorModelTypeUnknown; }
};
