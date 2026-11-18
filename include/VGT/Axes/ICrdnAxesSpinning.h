#pragma once
#include "../../IAtkObj.h"
#include "ICrdnAxes.h"


///
/// VGT元素 旋转坐标轴
///
class IATKOBJECT_API ICrdnAxesSpinning :public ICrdnAxes
{
public:
    ICrdnAxesSpinning(const ICrdnAxesSpinning&) = delete;
    ICrdnAxesSpinning& operator=(const ICrdnAxesSpinning&) = delete;

	ICrdnAxesSpinning(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnAxesSpinning();

	IATKOBJECT_VGT_SETGET_CTIMEABS_DECL(RotationEpoch);
	IATKOBJECT_VGT_SETGET_VGT_DECL(SpinVector);
	IATKOBJECT_VGT_SETGET_DECL(RotationRate, double);
	IATKOBJECT_VGT_SETGET_DECL(RotationOffset, double);
	IATKOBJECT_VGT_SETGET_VGT_DECL(ReferenceAxes);
};
