#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
class CSatellite;
class IVeBreakAngle;

///
/// 轨道圈数定义经纬度
///
class IATKOBJECT_API IVeDefinition
{
public:
    IVeDefinition(const IVeDefinition&) = delete;
    IVeDefinition& operator=(const IVeDefinition&) = delete;

	IVeDefinition(CSatellite* pSate);
	~IVeDefinition();

	//********************************************************************
	/// 设置二维轨道圈数经纬度类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eBreakAngleType   轨道圈数经纬度类型
	//********************************************************************
	void SetBreakAngleType(EVeBreakAngleType eBreakAngleType);

	//********************************************************************
	/// 获得经纬度类型指针
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	经纬度类型指针
	//********************************************************************
	IVeBreakAngle* GetBreakAngle();

	//********************************************************************
	/// 获得经纬度类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	经纬度类型
	//********************************************************************
	EVeBreakAngleType GetBreakAngleType();

	//********************************************************************
	/// 设置方向
	/// @author	Gan Shu Long
	/// @date	2026-10-20
	/// @param[in]	eVeDirection 方向
	//********************************************************************
	void SetDirection(EVeDirection eVeDirection);

	//********************************************************************
	/// 获得方向
	/// @author	Gan Shu Long
	/// @date	2026-10-20
	/// @return	方向
	//********************************************************************
	EVeDirection GetDirection();

private:
	CSatellite*           m_pSate;

	IVeBreakAngle*        m_BreakAngle;       //经纬度类型指针
};

