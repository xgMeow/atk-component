#pragma once
#include "../../IAtkObj.h"
#include "ICrdnPlane.h"


///
/// VGT元素 轨迹平面
///
class IATKOBJECT_API ICrdnPlaneTrajectory :public ICrdnPlane
{
public:
    ICrdnPlaneTrajectory(const ICrdnPlaneTrajectory&) = delete;
    ICrdnPlaneTrajectory& operator=(const ICrdnPlaneTrajectory&) = delete;

	ICrdnPlaneTrajectory(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnPlaneTrajectory();

	IATKOBJECT_VGT_SETGET_VGT_DECL(Point);
	IATKOBJECT_VGT_SETGET_VGT_DECL(ReferenceSystem);
	IATKOBJECT_VGT_SETGET_DEG_DECL(RotationOffset, double);
};
