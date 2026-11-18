#pragma once
#include "../../IAtkObj.h"
#include "ICrdnPlane.h"


///
/// VGT元素 三轴组平面
///
class IATKOBJECT_API ICrdnPlaneTriad :public ICrdnPlane
{
public:
    ICrdnPlaneTriad(const ICrdnPlaneTriad&) = delete;
    ICrdnPlaneTriad& operator=(const ICrdnPlaneTriad&) = delete;

	ICrdnPlaneTriad(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnPlaneTriad();

	IATKOBJECT_VGT_SETGET_VGT_DECL(PointA);
	IATKOBJECT_VGT_SETGET_VGT_DECL(PointB);
	IATKOBJECT_VGT_SETGET_VGT_DECL(ReferencePoint);
	IATKOBJECT_VGT_SETGET_DEG_DECL(RotationOffset, double);
};
