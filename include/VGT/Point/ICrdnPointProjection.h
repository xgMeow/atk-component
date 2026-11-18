#pragma once
#include "../../IAtkObj.h"
#include "ICrdnPoint.h"


///
/// VGT元素 投射点
///
class IATKOBJECT_API ICrdnPointProjection :public ICrdnPoint
{
public:
    ICrdnPointProjection(const ICrdnPointProjection&) = delete;
    ICrdnPointProjection& operator=(const ICrdnPointProjection&) = delete;

	ICrdnPointProjection(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnPointProjection();

	IATKOBJECT_VGT_SETGET_VGT_DECL(Point);
	IATKOBJECT_VGT_SETGET_VGT_DECL(ReferencePlane);
};
