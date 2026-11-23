#pragma once
#include "../../IAtkObj.h"
#include "ICrdnAxes.h"


///
/// VGT元素 发惯系坐标轴
///
class IATKOBJECT_API ICrdnAxesLaunchInertial :public ICrdnAxes
{
public:
    ICrdnAxesLaunchInertial(const ICrdnAxesLaunchInertial&) = delete;
    ICrdnAxesLaunchInertial& operator=(const ICrdnAxesLaunchInertial&) = delete;

	ICrdnAxesLaunchInertial(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnAxesLaunchInertial();

	IATKOBJECT_VGT_SETGET_CENTRALBODY_DECL(CentralBody);
	IATKOBJECT_VGT_SETGET_VGT_DECL(Point);
	IATKOBJECT_VGT_SETGET_DEG_DECL(ClockAngle, double);
	IATKOBJECT_VGT_SETGET_CTIMEABS_DECL(LaunchTime);
};
