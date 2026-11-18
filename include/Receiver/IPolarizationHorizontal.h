#pragma once
#include "../IAtkObj.h"
#include "IPolarization.h"
struct CCRAntenna;

///
/// 水平极化基类
///
class IATKOBJECT_API IPolarizationHorizontal :public IPolarization
{
public:
    IPolarizationHorizontal(const IPolarizationHorizontal&) = delete;
    IPolarizationHorizontal& operator=(const IPolarizationHorizontal&) = delete;

	IPolarizationHorizontal(CCRAntenna* pCCRAntenna);
	~IPolarizationHorizontal();

	//********************************************************************
	/// 获得 天线极化类型
	/// @author	Gan Shu Long
	/// @date	2026-03-10
	/// @return	天线极化类型
	//********************************************************************
	EPolarizationType GetType() { return ePolarizationTypeHorizontal; }

	//********************************************************************
	/// 设置  天线极化参考轴
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @param[in]	referenceAxis 新值
	//********************************************************************
	void SetReferenceAxis(EPolarizationReferenceAxis referenceAxis);
	
	//********************************************************************
	/// 获得 天线极化参考轴
	/// @author	Gan Shu Long
	/// @date	2026-03-10
	/// @return	天线极化参考轴
	//********************************************************************
	EPolarizationReferenceAxis GetReferenceAxis();

	//********************************************************************
	/// 设置  极化角度
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @param[in]	tiltAngle 新值
	//********************************************************************
	void SetTiltAngle(double tiltAngle);
	
	//********************************************************************
	/// 获得 极化角度
	/// @author	Gan Shu Long
	/// @date	2026-03-10
	/// @return	极化角度
	//********************************************************************
	double GetTiltAngle();

private:
	CCRAntenna*			 m_pCCRAntenna;		//天线结构体
};
