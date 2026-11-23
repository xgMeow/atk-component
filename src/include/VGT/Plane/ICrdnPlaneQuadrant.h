#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
#include "ICrdnPlane.h"


///
/// VGT元素 象限平面
///
class IATKOBJECT_API ICrdnPlaneQuadrant :public ICrdnPlane
{
public:
    ICrdnPlaneQuadrant(const ICrdnPlaneQuadrant&) = delete;
    ICrdnPlaneQuadrant& operator=(const ICrdnPlaneQuadrant&) = delete;

	ICrdnPlaneQuadrant(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnPlaneQuadrant();

	IATKOBJECT_VGT_SETGET_DECL(Quadrant, EPlaneQuadrant);
	IATKOBJECT_VGT_SETGET_VGT_DECL(ReferenceSystem);
};
