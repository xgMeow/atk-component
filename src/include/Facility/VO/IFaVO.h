#pragma once
#include "../../IAtkObj.h"
class CObjManage;
struct CObjData;
class IVOOffset;
class IVOVector; 
class IVOAttitudeSphere;
class IVORangeContours;
class IVODataDisplayCollection;

///
/// 三维
///
class IATKOBJECT_API IFaVO
{
public:
    IFaVO(const IFaVO&) = delete;
    IFaVO& operator=(const IFaVO&) = delete;

	IFaVO(CObjData* pObjData, CObjManage* IAsGObjManage);
	~IFaVO();

	//********************************************************************
	/// 获得三维模型属性
	/// @author	Gan Shu Long
	/// @date	2024-06-06
	/// @return	三维模型属性指针		
	//********************************************************************
	IVOOffset* GetOffsets() { return m_Offsets; }

	//********************************************************************
	/// 获得三维向量属性
	/// @author	Gan Shu Long
	/// @date	2024-06-06
	/// @return	三维向量属性指针		
	//********************************************************************
	IVOVector* GetVector() { return m_Vector; }

	//********************************************************************
	/// 获得三维姿态球属性
	/// @author	Gan Shu Long
	/// @date	2026-01-21
	/// @return	三维姿态球属性指针		
	//********************************************************************
	IVOAttitudeSphere* GetAttitudeSpherer() { return m_AttitudeSpherer; }

	//********************************************************************
	/// 获得三维范围属性
	/// @author	Gan Shu Long
	/// @date	2026-01-20
	/// @return	三维范围属性指针
	//********************************************************************
	IVORangeContours* GetRangeContours() { return m_RangeContours; }

	//********************************************************************
	/// 获得三维数据显示属性
	/// @author	Gan Shu Long
	/// @date	2026-01-20
	/// @return	三维数据显示属性指针		
	//********************************************************************
	IVODataDisplayCollection* GetDataDisplay() { return m_DataDisplay; }

private:
	IVOOffset*								m_Offsets;					//三维模型属性
	IVOVector*								m_Vector;					//三维向量属性
	IVOAttitudeSphere*					m_AttitudeSpherer;		//三维姿态球属性
	IVORangeContours*				m_RangeContours;	//三维范围属性
	IVODataDisplayCollection*     m_DataDisplay;			//三维数据显示属性
};
