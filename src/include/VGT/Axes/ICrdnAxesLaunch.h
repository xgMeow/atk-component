#pragma once
#include "../../IAtkObj.h"
#include "ICrdnAxes.h"


///
/// VGT元素 发射系坐标轴
///
class IATKOBJECT_API ICrdnAxesLaunch :public ICrdnAxes
{
public:
    ICrdnAxesLaunch(const ICrdnAxesLaunch&) = delete;
    ICrdnAxesLaunch& operator=(const ICrdnAxesLaunch&) = delete;

	ICrdnAxesLaunch(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnAxesLaunch();

	IATKOBJECT_VGT_SETGET_CENTRALBODY_DECL(CentralBody);
	IATKOBJECT_VGT_SETGET_VGT_DECL(Point);
	IATKOBJECT_VGT_SETGET_DEG_DECL(ClockAngle, double);
};
