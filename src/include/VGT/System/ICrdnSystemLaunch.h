#pragma once
#include "../../IAtkObj.h"
#include "ICrdnSystem.h"


///
/// VGT元素 发射坐标系
///
class IATKOBJECT_API ICrdnSystemLaunch :public ICrdnSystem
{
public:
    ICrdnSystemLaunch(const ICrdnSystemLaunch&) = delete;
    ICrdnSystemLaunch& operator=(const ICrdnSystemLaunch&) = delete;

	ICrdnSystemLaunch(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnSystemLaunch();

	IATKOBJECT_VGT_SETGET_VGT_DECL(Point);
	IATKOBJECT_VGT_SETGET_CENTRALBODY_DECL(CentralBody);
	IATKOBJECT_VGT_SETGET_DEG_DECL(ClockAngle, double);
};
