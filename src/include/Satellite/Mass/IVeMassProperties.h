#pragma once
#include "../../IAtkObj.h"
class CSatellite;
class IVeInertia;

///
/// 质量
///
class IATKOBJECT_API IVeMassProperties
{
public:
    IVeMassProperties(const IVeMassProperties&) = delete;
    IVeMassProperties& operator=(const IVeMassProperties&) = delete;

	IVeMassProperties(CSatellite* pSate);
	~IVeMassProperties();

	//********************************************************************
	/// 获得转动惯量属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	转动惯量属性指针	
	//********************************************************************
	IVeInertia* GetInertia();

	//********************************************************************
	/// 设置质量参数
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dMass  质量参数(kg)
	//********************************************************************
	void SetMass(double dMass);
	//********************************************************************
	/// 获得质量参数
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	质量参数(kg)
	//********************************************************************
	double GetMass();
	//********************************************************************
	/// 获得当前时刻质量参数
	/// @author	Dong Min
	/// @date	2025-06-16
	/// @param[in]	strTime  UTCG格式时间
	/// @return	质量参数(kg)
	//********************************************************************
	double GetMass(std::string strTime);

	//********************************************************************
	/// 设置质心位置X
	/// @author	Gan Shu Long
	/// @date	2026-10-20
	/// @param[in]	dX 质心位置X(m)
	//********************************************************************
	void SetCenterMassPositionX(double dX);

	//********************************************************************
	/// 获得质心位置X
	/// @author	Gan Shu Long
	/// @date	2026-10-20
	/// @return	质心位置X(m)
	//********************************************************************
	double GetCenterMassPositionX();

	//********************************************************************
	/// 设置质心位置Y
	/// @author	Gan Shu Long
	/// @date	2026-10-20
	/// @param[in]	dY 质心位置Y(m)
	//********************************************************************
	void SetCenterMassPositionY(double dY);

	//********************************************************************
	/// 获得质心位置Y
	/// @author	Gan Shu Long
	/// @date	2026-10-20
	/// @return	质心位置Y(m)
	//********************************************************************
	double GetCenterMassPositionY();

	//********************************************************************
	/// 设置质心位置Z
	/// @author	Gan Shu Long
	/// @date	2026-10-20
	/// @param[in]	dZ 质心位置Z(m)
	//********************************************************************
	void SetCenterMassPositionZ(double dZ);

	//********************************************************************
	/// 获得质心位置Z
	/// @author	Gan Shu Long
	/// @date	2026-10-20
	/// @return	质心位置Z(m)
	//********************************************************************
	double GetCenterMassPositionZ();

private:
	CSatellite*     m_pSate;

	IVeInertia*     m_Inertia;   //转动惯量属性

};
