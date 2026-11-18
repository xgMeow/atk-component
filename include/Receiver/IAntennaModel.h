#pragma once
#include "../IAtkObj.h"
#include "../IClassInfo.h" 
#include "../ICEnum.h"
struct CCRAntenna;

///
/// 天线模型
///
class IATKOBJECT_API IAntennaModel :public IClassInfo
{
public:
    IAntennaModel(const IAntennaModel&) = delete;
    IAntennaModel& operator=(const IAntennaModel&) = delete;

	IAntennaModel(CCRAntenna* pCCRAntenna);
	virtual ~IAntennaModel();

	//********************************************************************
	/// 获得 天线模型名称
	/// @author	Gan Shu Long
	/// @date	2026-03-16
	/// @return	天线模型名称
	//********************************************************************
	std::string GetName() { return ""; }

	//********************************************************************
	/// 获得 天线模型类型
	/// @author	Gan Shu Long
	/// @date	2026-03-16
	/// @return	天线模型类型
	//********************************************************************
	EAntennaModelType GetType() { return eAntennaModelTypeUnknown; }

	//********************************************************************
	/// 设置  设计频率
	/// @author	Gan Shu Long
	/// @date	2026-03-16
	/// @param[in]	dDesignFrequency 设计频率
	//********************************************************************
	void SetDesignFrequency(double dDesignFrequency);

	//********************************************************************
	/// 获得 设计频率
	/// @author	Gan Shu Long
	/// @date	2026-03-16
	/// @return	设计频率
	//********************************************************************
	double GetDesignFrequency();

private:
	CCRAntenna*					m_pCCRAntenna;					//天线结构体
};
