#pragma once
#include "../IAtkObj.h"
#include "IPolarization.h"
struct CCRAntenna;

///
/// 右旋圆极化基类
///
class IATKOBJECT_API IPolarizationRHC :public IPolarization
{
public:
    IPolarizationRHC(const IPolarizationRHC&) = delete;
    IPolarizationRHC& operator=(const IPolarizationRHC&) = delete;

	IPolarizationRHC(CCRAntenna* pCCRAntenna);
	~IPolarizationRHC();

	//********************************************************************
	/// 获得 天线极化类型
	/// @author	Gan Shu Long
	/// @date	2026-03-10
	/// @return	天线极化类型
	//********************************************************************
	EPolarizationType GetType() { return ePolarizationTypeRHC; }

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
