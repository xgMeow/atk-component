#pragma once
#include "../IAtkObj.h"
#include "IAntennaModel.h" 
#include "../ICEnum.h"
struct CCRAntenna;

///
/// 天线模型 Isotropic
///
class IATKOBJECT_API IAntennaModelIsotropic :public IAntennaModel
{
public:
    IAntennaModelIsotropic(const IAntennaModelIsotropic&) = delete;
    IAntennaModelIsotropic& operator=(const IAntennaModelIsotropic&) = delete;

	IAntennaModelIsotropic(CCRAntenna* pCCRAntenna);
	virtual ~IAntennaModelIsotropic();

	//********************************************************************
	/// 获得 天线模型名称
	/// @author	Gan Shu Long
	/// @date	2026-03-16
	/// @return	天线模型名称
	//********************************************************************
	std::string GetName() { return "Isotropic"; }

	//********************************************************************
	/// 获得 天线模型类型
	/// @author	Gan Shu Long
	/// @date	2026-03-16
	/// @return	天线模型类型
	//********************************************************************
	EAntennaModelType GetType() { return eAntennaModelTypeIsotropic; }

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

private:
	CCRAntenna*					m_pCCRAntenna;					//天线结构体
};
