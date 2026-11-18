#pragma once
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"
class CSatellite;
class CObjManage;
struct CObjData;
class IVOOffset;
class IVOVector;
class IVOAttitudeSphere;
class IVeVOSystemsCollection;
class IVeVOOrbitProximity;
class IVeVOElevContours;
class IVORangeContours;
class IVODataDisplayCollection;

///
/// 三维
///
class IATKOBJECT_API ISaVO :public IClassInfo
{
public:
    ISaVO(const ISaVO&) = delete;
    ISaVO& operator=(const ISaVO&) = delete;

	ISaVO(CObjData* pObjData, CObjManage* IAsGObjManage);
	~ISaVO();

	//********************************************************************
	/// 获得三维模型属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	三维模型属性指针		
	//********************************************************************
	IVOOffset* GetOffsets() { return m_Offsets; }

	//********************************************************************
	/// 获得三维向量属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	三维向量属性指针		
	//********************************************************************
	IVOVector* GetVector() { return m_Vector; }

	//********************************************************************
	/// 获得三维姿态球属性
	/// @author	Gan Shu Long
	/// @date	2026-10-19
	/// @return	三维姿态球属性指针		
	//********************************************************************
	IVOAttitudeSphere* GetAttitudeSpherer() { return m_AttitudeSpherer; }

	//********************************************************************
	/// 获得相对轨迹属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	相对轨迹属性指针		
	//********************************************************************
	IVeVOSystemsCollection* GetOrbitSystems() { return m_OrbitSystems; }

	//********************************************************************
	/// 获得三维抵近属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	三维抵近属性指针		
	//********************************************************************
	IVeVOOrbitProximity* GetProximity() { return m_Proximity; }

	//********************************************************************
	/// 获得三维等高线属性
	/// @author	Gan Shu Long
	/// @date	2026-10-19
	/// @return	二维等高线指针		
	//********************************************************************
	IVeVOElevContours* GetElevContours() { return m_ElevContours; }

	//********************************************************************
	/// 获得三维范围属性
	/// @author	Gan Shu Long
	/// @date	2026-10-19
	/// @return	三维范围指针
	//********************************************************************
	IVORangeContours* GetRangeContours() { return m_RangeContours; }
	
	//********************************************************************
	/// 获得三维数据显示属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	三维数据显示属性指针		
	//********************************************************************
	IVODataDisplayCollection* GetDataDisplay() { return m_DataDisplay; }

private:
	CSatellite*						m_pCSatellite;
	CObjData*						m_pObjData;
	CObjManage*						m_IAsGObjManage;

	IVOOffset*						m_Offsets;				//三维模型属性
	IVOVector*						m_Vector;				//三维向量属性
	IVOAttitudeSphere*				m_AttitudeSpherer;		//三维姿态球属性
	IVeVOSystemsCollection*			m_OrbitSystems;			//相对轨迹属性
	IVeVOOrbitProximity*			m_Proximity;			//三维抵近属性
	IVeVOElevContours*				m_ElevContours;			//三维等高线
	IVORangeContours*				m_RangeContours;		//三维范围属性
	IVODataDisplayCollection*		m_DataDisplay;			//三维数据显示属性

};
