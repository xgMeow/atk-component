#pragma once
#include "../IAtkObj.h"
#include "IAntennaModel.h" 
#include "../ICEnum.h"
struct CCRAntenna;

///
/// 天线模型 Parabolic
///
class IATKOBJECT_API IAntennaModelParabolic :public IAntennaModel
{
public:
    IAntennaModelParabolic(const IAntennaModelParabolic&) = delete;
    IAntennaModelParabolic& operator=(const IAntennaModelParabolic&) = delete;

	IAntennaModelParabolic(CCRAntenna* pCCRAntenna);
	virtual ~IAntennaModelParabolic();

	//********************************************************************
	/// 获得 天线模型名称
	/// @author	Gan Shu Long
	/// @date	2026-03-16
	/// @return	天线模型名称
	//********************************************************************
	std::string GetName() { return "Parabolic"; }

	//********************************************************************
	/// 获得 天线模型类型
	/// @author	Gan Shu Long
	/// @date	2026-03-16
	/// @return	天线模型类型
	//********************************************************************
	EAntennaModelType GetType() { return eAntennaModelTypeParabolic; }

	//********************************************************************
	/// 设置  天线效率%
	/// @author	Gan Shu Long
	/// @date	2026-03-16
	/// @param[in]	dEfficiency 天线效率%
	//********************************************************************
	void SetEfficiency(double dEfficiency);

	//********************************************************************
	/// 获得 天线效率%
	/// @author	Gan Shu Long
	/// @date	2026-03-16
	/// @return	天线效率%
	//********************************************************************
	double GetEfficiency();

	//********************************************************************
	/// 设置  后波瓣增益
	/// @author	Gan Shu Long
	/// @date	2026-03-16
	/// @param[in]	dBacklobeGain 后波瓣增益
	//********************************************************************
	void SetBacklobeGain(double dBacklobeGain);

	//********************************************************************
	/// 获得 后波瓣增益
	/// @author	Gan Shu Long
	/// @date	2026-03-16
	/// @return	后波瓣增益
	//********************************************************************
	double GetBacklobeGain();

	//********************************************************************
	/// 设置  天线直径单位m
	/// @author	Gan Shu Long
	/// @date	2026-03-16
	/// @param[in]	dDiameter 天线直径单位m
	//********************************************************************
	void SetDiameter(double dDiameter);

	//********************************************************************
	/// 获得 天线直径单位m
	/// @author	Gan Shu Long
	/// @date	2026-03-16
	/// @return	天线直径单位m
	//********************************************************************
	double GetDiameter();

private:
	CCRAntenna*					m_pCCRAntenna;					//天线结构体
};
