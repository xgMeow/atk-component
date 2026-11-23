#pragma once
#include "../../IAtkObj.h"
#include "ICrdnPoint.h"


///
/// VGT元素 B平面点
///
class IATKOBJECT_API ICrdnPointBPlane :public ICrdnPoint
{
public:
    ICrdnPointBPlane(const ICrdnPointBPlane&) = delete;
    ICrdnPointBPlane& operator=(const ICrdnPointBPlane&) = delete;

	ICrdnPointBPlane(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnPointBPlane();

	IATKOBJECT_VGT_SETGET_VGT_DECL(TrajectortPoint);
	IATKOBJECT_VGT_SETGET_CENTRALBODY_DECL(CentrialBody);
	IATKOBJECT_VGT_SETGET_DECL(Type, int);
	IATKOBJECT_VGT_SETGET_DECL(InComing, int);
};
