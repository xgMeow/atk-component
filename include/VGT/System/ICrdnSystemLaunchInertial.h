#pragma once
#include "../../IAtkObj.h"
#include "ICrdnSystem.h"


///
/// VGT元素 发射惯性系
///
class IATKOBJECT_API ICrdnSystemLaunchInertial :public ICrdnSystem
{
public:
    ICrdnSystemLaunchInertial(const ICrdnSystemLaunchInertial&) = delete;
    ICrdnSystemLaunchInertial& operator=(const ICrdnSystemLaunchInertial&) = delete;

	ICrdnSystemLaunchInertial(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnSystemLaunchInertial();

	IATKOBJECT_VGT_SETGET_VGT_DECL(Point);
	IATKOBJECT_VGT_SETGET_CENTRALBODY_DECL(CentralBody);
	IATKOBJECT_VGT_SETGET_DEG_DECL(ClockAngle, double);
	IATKOBJECT_VGT_SETGET_CTIMEABS_DECL(LaunchTime);
};
