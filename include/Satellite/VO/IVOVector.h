#pragma once
#include "../../IAtkObj.h"
struct CObjData;
class CVehicleGfx3D;
class CFacilityGfx3D;
class CSensorGfx3D;
class IVORefCrdnCollection;

///
/// 三维向量
///
class IATKOBJECT_API IVOVector
{
public:
    IVOVector(const IVOVector&) = delete;
    IVOVector& operator=(const IVOVector&) = delete;

	IVOVector(CObjData* pObjData, CVehicleGfx3D* pCVehGfx3D);
	IVOVector(CObjData* pObjData, CFacilityGfx3D* pCFacGfx3D);
	IVOVector(CObjData* pObjData, CSensorGfx3D* pCSenGfx3D);
	~IVOVector();

	//********************************************************************
	/// 设置三维向量对应比例
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dVecScale  比例
	//********************************************************************
	void SetVectorSizeScale(double dVecScale);
	//********************************************************************
	/// 获得三维向量对应比例
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	比例		
	//********************************************************************
	double GetVectorSizeScale();

	//********************************************************************
	/// 获得向量元素集合
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	元素集合指针	
	//********************************************************************
	IVORefCrdnCollection* GetRefCrdns();

private:
	CObjData*                   m_pObjData;

	CVehicleGfx3D*              m_pCVehGfx3D;		//Vehicle三维向量指针
	CFacilityGfx3D*             m_pCFacGfx3D;		//Facility三维向量指针
	CSensorGfx3D*               m_pCSenGfx3D;		//Sensor三维向量指针

	IVORefCrdnCollection*		m_RefCrdns;				//元素集合

};
