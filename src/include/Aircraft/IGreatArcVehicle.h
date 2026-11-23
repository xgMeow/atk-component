#pragma once
#include "../IAtkObj.h"
#include "../AccessConstraints/IAccessConstraintCollection.h"
#include "../Satellite/Propagator/IVePropagator.h"
#include "../ICEnum.h"
#include "../IClassInfo.h"
struct CObjData;
class IVeGroundEllipsesCollection;

///
/// 交通工具基类
///
class IATKOBJECT_API IGreatArcVehicle :public IClassInfo
{
public:
    IGreatArcVehicle(const IGreatArcVehicle&) = delete;
    IGreatArcVehicle& operator=(const IGreatArcVehicle&) = delete;

	IGreatArcVehicle(CObjData* pObjData);
	virtual ~IGreatArcVehicle();

	bool IsRouteTypeSupported(EVePropagatorType routeType);

	//********************************************************************
	/// 获得航线支持类型
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	/// @return	航线支持类型
	//********************************************************************
	std::vector<std::string> GetRouteSupportedTypes();

	//********************************************************************
	/// 设置航线类型
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	/// @param[in]	routeType  航线类型
	//********************************************************************
	void SetRouteType(EVePropagatorType routeType);

	//********************************************************************
	/// 获得航线类型
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	/// @return	航线类型
	//********************************************************************
	EVePropagatorType GetRouteType();

	//********************************************************************
	/// 获得航线
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	/// @return	航线指针
	//********************************************************************
	IVePropagator* GetRoute() { return m_Route; }

	//********************************************************************
	/// 获得地面椭圆设置集合
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	/// @return	地面椭圆设置集合指针
	//********************************************************************
	IVeGroundEllipsesCollection* GetGroundEllipses() { return m_GroundEllipses; }

private:
	int*															m_pPropType;								//C对象类型
	CObjData*												m_pObjData;

	IVePropagator*										m_Route;							//航线
	IVeGroundEllipsesCollection*					m_GroundEllipses;				//地面椭圆设置集合
};



