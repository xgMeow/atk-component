#pragma once
#include "../../IAtkObj.h"
#include "ICrdnPlane.h"


///
/// VGT元素 垂直平面
///
class IATKOBJECT_API ICrdnPlaneNormal :public ICrdnPlane
{
public:
    ICrdnPlaneNormal(const ICrdnPlaneNormal&) = delete;
    ICrdnPlaneNormal& operator=(const ICrdnPlaneNormal&) = delete;

	ICrdnPlaneNormal(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnPlaneNormal();

	IATKOBJECT_VGT_SETGET_VGT_DECL(NormalVector);
	IATKOBJECT_VGT_SETGET_VGT_DECL(ReferenceVector);
	IATKOBJECT_VGT_SETGET_VGT_DECL(ReferencePoint);
};
