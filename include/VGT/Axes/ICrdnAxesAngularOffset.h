#pragma once
#include "../../IAtkObj.h"
#include "ICrdnAxes.h"


///
/// VGT元素 角度偏移坐标轴
///
class IATKOBJECT_API ICrdnAxesAngularOffset :public ICrdnAxes
{
public:
    ICrdnAxesAngularOffset(const ICrdnAxesAngularOffset&) = delete;
    ICrdnAxesAngularOffset& operator=(const ICrdnAxesAngularOffset&) = delete;

	ICrdnAxesAngularOffset(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnAxesAngularOffset();

	IATKOBJECT_VGT_SETGET_VGT_DECL(ReferenceAxes);
	IATKOBJECT_VGT_SETGET_VGT_DECL(SpinVector);
	IATKOBJECT_VGT_SETGET_VGT_DECL(RotationAngle);
	IATKOBJECT_VGT_SETGET_DEG_DECL(RotationOffset, double);
};
