#pragma once
#include "../IAtkObj.h"
#include "../IClassInfo.h"
#include "../ICEnum.h"
#include <string>

///
/// 发射器模型：基类
///
class IATKOBJECT_API ITransmitterModel :public IClassInfo
{
public:
    ITransmitterModel(const ITransmitterModel&) = delete;
    ITransmitterModel& operator=(const ITransmitterModel&) = delete;

	ITransmitterModel();
	virtual ~ITransmitterModel();
	
	//********************************************************************
	/// 获得 发射器模型名称
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	发射器模型名称
	//********************************************************************
	std::string GetName() { return m_Name; }

	//********************************************************************
	/// 获得 发射器模型类型
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	发射器模型类型
	//********************************************************************
	ETransmitterModelType GetType() { return m_Type; }

protected:
	std::string							m_Name;			//模型名称
	ETransmitterModelType		m_Type;				//模型类型
};
