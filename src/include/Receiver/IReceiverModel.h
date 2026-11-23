#pragma once
#include "../IAtkObj.h"
#include "../IClassInfo.h" 
#include "../ICEnum.h"
#include <string>

///
/// 接收模型基类
///
class IATKOBJECT_API IReceiverModel :public IClassInfo
{
public:
    IReceiverModel(const IReceiverModel&) = delete;
    IReceiverModel& operator=(const IReceiverModel&) = delete;

	IReceiverModel();
	virtual ~IReceiverModel();

	//********************************************************************
	/// 获得 接收模型名称
	/// @author	Gan Shu Long
	/// @date	2026-03-10
	/// @return	接收模型名称
	//********************************************************************
	std::string GetName() { return "Receiver Model"; }

	//********************************************************************
	/// 获得 接收模型类型
	/// @author	Gan Shu Long
	/// @date	2026-03-10
	/// @return	接收模型类型
	//********************************************************************
	EReceiverModelType GetType() { return eReceiverModelTypeUnknown; }
};
