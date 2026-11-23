#pragma once
#include "../../IAtkObj.h"
#include "ICrdnPlane.h"


///
/// VGT元素 两向量平面
///
class IATKOBJECT_API ICrdnPlaneTwoVectors :public ICrdnPlane
{
public:
    ICrdnPlaneTwoVectors(const ICrdnPlaneTwoVectors&) = delete;
    ICrdnPlaneTwoVectors& operator=(const ICrdnPlaneTwoVectors&) = delete;

	ICrdnPlaneTwoVectors(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnPlaneTwoVectors();

	IATKOBJECT_VGT_SETGET_VGT_DECL(Vector1);
	IATKOBJECT_VGT_SETGET_VGT_DECL(Vector2);
	IATKOBJECT_VGT_SETGET_VGT_DECL(Point);
};
