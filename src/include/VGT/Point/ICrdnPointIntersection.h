#pragma once
#include "../../IAtkObj.h"
#include "ICrdnPoint.h"


///
/// VGT元素 交点
///
class IATKOBJECT_API ICrdnPointIntersection :public ICrdnPoint
{
public:
    ICrdnPointIntersection(const ICrdnPointIntersection&) = delete;
    ICrdnPointIntersection& operator=(const ICrdnPointIntersection&) = delete;

	ICrdnPointIntersection(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnPointIntersection();

	IATKOBJECT_VGT_SETGET_VGT_DECL(AlongVector);
	IATKOBJECT_VGT_SETGET_VGT_DECL(ReferencePlane);
	IATKOBJECT_VGT_SETGET_VGT_DECL(Point);
};
