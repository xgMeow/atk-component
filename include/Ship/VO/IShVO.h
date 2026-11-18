#pragma once
#include "../../IAtkObj.h"
#include "../../Aircraft/VO/IGreatArcVO.h"
struct CObjData;
class IVeVORouteProximity;

///
/// 舰船三维属性
///
class IATKOBJECT_API IShVO :public IGreatArcVO
{
public:
    IShVO(const IShVO&) = delete;
    IShVO& operator=(const IShVO&) = delete;

	IShVO(CObjData* pObjData);
	~IShVO();

	//********************************************************************
	/// 获得三维抵近属性
	/// @author	Gan Shu Long
	/// @date	2026-01-05
	/// @return	三维抵近属性指针		
	//********************************************************************
	IVeVORouteProximity* GetProximity() { return m_Proximity; }

private:
	IVeVORouteProximity*		m_Proximity;			 //三维抵近属性
};
