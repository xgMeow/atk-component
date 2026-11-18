#pragma once
#include "../../IAtkObj.h"
#include "ICrdnAngle.h"


///
/// VGT元素 平面间夹角
///
class IATKOBJECT_API ICrdnAngleBetweenPlane :public ICrdnAngle
{
public:
    ICrdnAngleBetweenPlane(const ICrdnAngleBetweenPlane&) = delete;
    ICrdnAngleBetweenPlane& operator=(const ICrdnAngleBetweenPlane&) = delete;

	ICrdnAngleBetweenPlane(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnAngleBetweenPlane();

	IATKOBJECT_VGT_SETGET_VGT_DECL(PlaneFrom);
	IATKOBJECT_VGT_SETGET_VGT_DECL(PlaneTo);
};
