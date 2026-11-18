#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
#include "ICrdnPoint.h"
#include <string>
#include <vector>


///
/// VGT元素 天平动点
///
class IATKOBJECT_API ICrdnPointLibration :public ICrdnPoint
{
public:
    ICrdnPointLibration(const ICrdnPointLibration&) = delete;
    ICrdnPointLibration& operator=(const ICrdnPointLibration&) = delete;

	ICrdnPointLibration(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnPointLibration();

	IATKOBJECT_VGT_SETGET_CENTRALBODY_DECL(PrimaryBody);
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
