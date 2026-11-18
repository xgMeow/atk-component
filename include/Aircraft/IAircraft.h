#pragma once
#include "../IAtkObject.h"
#include "IGreatArcVehicle.h"
class CObjManage;
struct CObjData;
class IAcGraphics;
class IAcVO;

///
/// 飞机
///
class IATKOBJECT_API IAircraft :public IAtkObject
{
public:
    IAircraft(const IAircraft&) = delete;
    IAircraft& operator=(const IAircraft&) = delete;

	IAircraft(CObjData* pObjData, CObjManage* IAsGObjManage, IAtkObjectRoot* Root);
	~IAircraft();

	//********************************************************************
	/// 获得基类成员
	/// @author	Gan Shu Long
	/// @date	2024-06-06
	/// @return	基类成员指针	
	//********************************************************************
	IGreatArcVehicle* GetGreatArcVehicle() { return m_GreatArcVehicle; }

	//********************************************************************
	/// 获得二维属性
	/// @author	Gan Shu Long
	/// @date	2024-06-06
	/// @return	二维属性指针	
	//********************************************************************
	IAcGraphics* GetGraphics() { return m_Graphics; }

	//********************************************************************
	/// 获得三维属性
	/// @author	Gan Shu Long
	/// @date	2024-06-06
	/// @return	三维属性指针	
	//********************************************************************
	IAcVO* GetVO() { return m_VO; }

private:
	IGreatArcVehicle*	m_GreatArcVehicle;	//本来是基类，java不支持多继承，就改成了类成员

	IAcGraphics*		m_Graphics;			//二维
	IAcVO*				m_VO;				//三维
};
