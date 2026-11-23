#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
#include "ICrdnAxes.h"
#include <string>
#include <vector>


///
/// VGT元素 天体平动点坐标轴
///
class IATKOBJECT_API ICrdnAxesLibration :public ICrdnAxes
{
public:
    ICrdnAxesLibration(const ICrdnAxesLibration&) = delete;
    ICrdnAxesLibration& operator=(const ICrdnAxesLibration&) = delete;

	ICrdnAxesLibration(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnAxesLibration();

	IATKOBJECT_VGT_SETGET_CENTRALBODY_DECL(CelestialBody);
	IATKOBJECT_VGT_SETGET_DECL(Point, ELibrationPoint);

	//********************************************************************
	/// 设置 次要天体列表
	/// @author	Gan Shu Long
	/// @date	2026-06-05
	/// @param[in]	strCentralBodyPaths  次要天体列表
	/// @return
	//********************************************************************
	err_t SetSecondaryBodies(std::vector<std::string> strCentralBodyPaths);

	//********************************************************************
	/// 获得 次要天体列表
	/// @author	Gan Shu Long
	/// @date	2026-06-05
	/// @return	次要天体列表
	//********************************************************************
	std::vector<std::string> GetSecondaryBodies();
};
