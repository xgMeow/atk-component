#pragma once
#include "../../IAtkObj.h"
struct CObjData;
struct CGfxControlBox;
class IVeVOControlBox;

///
/// 三维抵近控制盒属性
///
class IATKOBJECT_API IVeVOOrbitProximity
{
public:
    IVeVOOrbitProximity(const IVeVOOrbitProximity&) = delete;
    IVeVOOrbitProximity& operator=(const IVeVOOrbitProximity&) = delete;

	IVeVOOrbitProximity(CGfxControlBox* pCGfxControlBox);
	~IVeVOOrbitProximity();

	//********************************************************************
	/// 获得三维抵近控制盒属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	三维抵近控制盒属性指针		
	//********************************************************************
	IVeVOControlBox* GetControlBox();

private:
	CGfxControlBox*			m_pCGfxControlBox;
	IVeVOControlBox*		m_ControlBox;   //控制盒

};

