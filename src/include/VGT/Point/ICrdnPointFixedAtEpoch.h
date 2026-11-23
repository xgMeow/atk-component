#pragma once
#include "../../IAtkObj.h"
#include "ICrdnPoint.h"


///
/// VGT元素 历元点
///
class IATKOBJECT_API ICrdnPointFixedAtEpoch :public ICrdnPoint
{
public:
    ICrdnPointFixedAtEpoch(const ICrdnPointFixedAtEpoch&) = delete;
    ICrdnPointFixedAtEpoch& operator=(const ICrdnPointFixedAtEpoch&) = delete;

	ICrdnPointFixedAtEpoch(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnPointFixedAtEpoch();

	IATKOBJECT_VGT_SETGET_VGT_DECL(Point);
	IATKOBJECT_VGT_SETGET_VGT_DECL(ReferenceSystem);
	IATKOBJECT_VGT_SETGET_CTIMEABS_DECL(PointEpoch);
};
