#pragma once
#include "../IAtkObject.h"
#include "../Aircraft/IGreatArcVehicle.h"
class CObjManage;
struct CObjData;
class IShGraphics;
class IShVO;

///
/// 舰船
///
class IATKOBJECT_API IShip :public IAtkObject
{
public:
    IShip(const IShip&) = delete;
    IShip& operator=(const IShip&) = delete;

	IShip(CObjData* pObjData, CObjManage* IAsGObjManage, IAtkObjectRoot* Root);
	~IShip();

	//********************************************************************
	/// 获得基类成员
	/// @author	Gan Shu Long
	/// @date	2026-01-17
	/// @return	基类成员指针	
	//********************************************************************
	IGreatArcVehicle* GetGreatArcVehicle() { return m_GreatArcVehicle; }

	//********************************************************************
	/// 获得二维属性
	/// @author	Gan Shu Long
	/// @date	2024-06-11
	/// @return	二维属性指针	
	//********************************************************************
	IShGraphics* GetGraphics() { return m_Graphics; }

	//********************************************************************
	/// 获得三维属性
	/// @author	Gan Shu Long
	/// @date	2024-06-11
	/// @return	三维属性指针	
	//********************************************************************
	IShVO* GetVO() { return m_VO; }

private:
	IGreatArcVehicle*	m_GreatArcVehicle;	//本来是基类，java不支持多继承，就改成了类成员

	IShGraphics*			m_Graphics;				//二维
	IShVO*					m_VO;							//三维
};
