#pragma once
#include "../../IAtkObj.h"
#include "ICrdnAngle.h"


///
/// VGT元素 矢量与平面角
///
class IATKOBJECT_API ICrdnAngleToPlane :public ICrdnAngle
{
public:
    ICrdnAngleToPlane(const ICrdnAngleToPlane&) = delete;
    ICrdnAngleToPlane& operator=(const ICrdnAngleToPlane&) = delete;

	ICrdnAngleToPlane(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnAngleToPlane();

	IATKOBJECT_VGT_SETGET_VGT_DECL(VectorFrom);
	IATKOBJECT_VGT_SETGET_VGT_DECL(PlaneTo);
	IATKOBJECT_VGT_SETGET_DECL(Signed, bool);
	IATKOBJECT_VGT_SETGET_DECL(SignedAngle, int);         //false:Postive; true:Negative
};
