#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
class CSensor;
//class IDisplayDistance;

///
/// 传感器二维投影
///
class IATKOBJECT_API ISnProjection
{
public:
    ISnProjection(const ISnProjection&) = delete;
    ISnProjection& operator=(const ISnProjection&) = delete;

	ISnProjection(CSensor* pCSensor);
	~ISnProjection();


	//********************************************************************
	/// 设置 显示相交类型
	/// @author	Gan Shu Long
	/// @date	2026-03-24
	/// @param[in]	eIntersectionType  显示相交类型
	//********************************************************************
	void SetIntersectionType(EIntersectionType eIntersectionType);

	//********************************************************************
	/// 获得 显示相交类型
	/// @author	Gan Shu Long
	/// @date	2026-03-24
	/// @return	显示相交类型
	//********************************************************************
	EIntersectionType GetIntersectionType();


	////********************************************************************
	///// 设置 投影距离类型
	///// @Author	Gan Shu Long
	///// @Date	2023-12-8
	///// @Input 
	///// @Param	ESnProjectionDistanceType type 投影距离类型
	///// @Return	
	////********************************************************************
	//void SetDistanceType(ESnProjectionDistanceType type);
	////读写类型
	//ESnProjectionDistanceType GetDistanceType();
	//IDisplayDistance* GetDistanceData() { return m_DistanceData; }

private:
	//IDisplayDistance*			m_DistanceData;

	CSensor* m_pCSensor;
};

