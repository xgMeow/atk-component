#pragma once
#include "../../IAtkObj.h"
#include "ICrdnAxes.h"


///
/// VGT元素 轴向对齐与方向约束坐标轴
///
class IATKOBJECT_API ICrdnAxesAlignedConstrained :public ICrdnAxes
{
public:
    ICrdnAxesAlignedConstrained(const ICrdnAxesAlignedConstrained&) = delete;
    ICrdnAxesAlignedConstrained& operator=(const ICrdnAxesAlignedConstrained&) = delete;

	ICrdnAxesAlignedConstrained(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnAxesAlignedConstrained();

	IATKOBJECT_VGT_SETGET_DECL(AlignedAxis, int);             //0-5:X/Y/Z/-X/-Y/-Z
	IATKOBJECT_VGT_SETGET_VGT_DECL(AlignedVector);
	IATKOBJECT_VGT_SETGET_DECL(ConstrainedAxis, int);         //0-5:X/Y/Z/-X/-Y/-Z
	IATKOBJECT_VGT_SETGET_VGT_DECL(ConstrainedVector);
};
