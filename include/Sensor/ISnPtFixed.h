#pragma once
#include "../IAtkObj.h"
#include "ISnPointing.h"
struct CObjData;
class IOrientation;

///
/// 指向：固定
///
class IATKOBJECT_API ISnPtFixed : public ISnPointing
{
public:
    ISnPtFixed(const ISnPtFixed&) = delete;
    ISnPtFixed& operator=(const ISnPtFixed&) = delete;

	ISnPtFixed(CObjData* pCObjData);
	~ISnPtFixed();
	
	//********************************************************************
	/// 获得 指向固定属性指针
	/// @author	Gan Shu Long
	/// @date	2026-03-23
	/// @return	指向固定属性指针
	//********************************************************************
	IOrientation* GetOrientation() { return m_Orientation; }

private:
	IOrientation*			m_Orientation;
};

