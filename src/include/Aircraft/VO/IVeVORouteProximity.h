#pragma once
#include "../../IAtkObj.h"
struct CObjData;
struct CGfxControlBox;
class IVeVOControlBox;

///
/// 三维抵近控制盒属性
///
class IATKOBJECT_API IVeVORouteProximity
{
public:
    IVeVORouteProximity(const IVeVORouteProximity&) = delete;
    IVeVORouteProximity& operator=(const IVeVORouteProximity&) = delete;

	IVeVORouteProximity(CGfxControlBox* pCGfxControlBox);
	~IVeVORouteProximity();

	//********************************************************************
	/// 获得三维抵近控制盒属性
	/// @author	Gan Shu Long
	/// @date	2026-01-05
	/// @return	三维抵近控制盒属性指针		
	//********************************************************************
	IVeVOControlBox* GetControlBox();

private:
	CGfxControlBox*			m_pCGfxControlBox;
	IVeVOControlBox*		m_ControlBox;   //控制盒
};

