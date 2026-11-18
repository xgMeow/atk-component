#pragma once
#include "../../IAtkObj.h"
#include "../../Aircraft/VO/IGreatArcVO.h"
struct CObjData;
class IVeVORouteProximity;

///
/// 潜艇三维属性
///
class IATKOBJECT_API ISuVO :public IGreatArcVO
{
public:
    ISuVO(const ISuVO&) = delete;
    ISuVO& operator=(const ISuVO&) = delete;

	ISuVO(CObjData* pObjData);
	~ISuVO();

	//********************************************************************
	/// 获得三维抵近属性
	/// @author	Gan Shu Long
	/// @date	2026-01-05
	/// @return	三维抵近属性指针		
	//********************************************************************
	IVeVORouteProximity* GetProximity() { return m_Proximity; }

private:
	//屏蔽没有的基类属性
	using  IGreatArcVO::GetRangeContours;

private:
	IVeVORouteProximity*		m_Proximity;			 //三维抵近属性
};
