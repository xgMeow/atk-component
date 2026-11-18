#pragma once
#include "../../IAtkObj.h"

class CObjManage;
struct CObjData;
class CLaunchVehicle;
class IVOOffset;
class IVOVector;
class IVOAttitudeSphere;
class IVeVOSystemsCollection;
class IVeVORouteProximity;
class IVeVOElevContours;
class IVORangeContours;
class IVODataDisplayCollection;

///
/// 导弹三维属性
///
class IATKOBJECT_API IMsVO
{
public:
    IMsVO(const IMsVO&) = delete;
    IMsVO& operator=(const IMsVO&) = delete;

	IMsVO(CObjData* pObjData, CObjManage* IAsGObjManage);
	~IMsVO();

	//********************************************************************
	/// 获得三维模型属性
	/// @author	Gan Shu Long
	/// @date	2024-06-11
	/// @return	三维模型指针		
	//********************************************************************
	IVOOffset* GetOffsets() { return m_Offsets; }

	//********************************************************************
	/// 获得三维向量属性
	/// @author	Gan Shu Long
	/// @date	2024-06-11
	/// @return	三维向量指针		
	//********************************************************************
	IVOVector* GetVector() { return m_Vector; }

	//********************************************************************
	/// 获得三维姿态球属性
	/// @author	Gan Shu Long
	/// @date	2026-01-29
	/// @return	三维姿态球指针		
	//********************************************************************
	IVOAttitudeSphere* GetAttitudeSpherer() { return m_AttitudeSpherer; }

	//********************************************************************
	/// 获得三维轨道系统
	/// @author	Gan Shu Long
	/// @date	2024-06-11
	/// @return	三维轨道系统指针		
	//********************************************************************
	IVeVOSystemsCollection* GetTrajectorySystems() { return m_TrajectorySystems; }
	
	//********************************************************************
	/// 获得三维抵近属性
	/// @author	Gan Shu Long
	/// @date	2026-01-29
	/// @return	三维抵近指针		
	//********************************************************************
	IVeVORouteProximity* GetProximity() { return m_Proximity; }

	//********************************************************************
	/// 获得三维等高线属性
	/// @author	Gan Shu Long
	/// @date	2026-01-29
	/// @return	二维等高线指针		
	//********************************************************************
	IVeVOElevContours* GetElevContours() { return m_ElevContours; }

	//********************************************************************
	/// 获得三维范围属性
	/// @author	Gan Shu Long
	/// @date	2026-01-29
	/// @return	三维范围指针
	//********************************************************************
	IVORangeContours* GetRangeContours() { return m_RangeContours; }

	//********************************************************************
	/// 获得三维数据显示属性
	/// @author	Gan Shu Long
	/// @date	2026-01-29
	/// @return	三维数据显示指针		
	//********************************************************************
	IVODataDisplayCollection* GetDataDisplay() { return m_DataDisplay; }

private:
	IVOOffset*								m_Offsets;						//三维模型指针
	IVOVector*								m_Vector;						//三维向量指针
	IVOAttitudeSphere*					m_AttitudeSpherer;			//三维姿态球指针
	IVeVOSystemsCollection*		m_TrajectorySystems;	//三维轨道系统指针
	IVeVORouteProximity*			m_Proximity;					//三维抵近指针
	IVeVOElevContours*				m_ElevContours;			//二维等高线指针
	IVORangeContours*				m_RangeContours;		//三维范围指针
	IVODataDisplayCollection*		m_DataDisplay;				//三维数据显示指针
};
