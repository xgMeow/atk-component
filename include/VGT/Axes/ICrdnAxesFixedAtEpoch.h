#pragma once
#include "../../IAtkObj.h"
#include "ICrdnAxes.h"


///
/// VGT元素 历元坐标轴
///
class IATKOBJECT_API ICrdnAxesFixedAtEpoch :public ICrdnAxes
{
public:
    ICrdnAxesFixedAtEpoch(const ICrdnAxesFixedAtEpoch&) = delete;
    ICrdnAxesFixedAtEpoch& operator=(const ICrdnAxesFixedAtEpoch&) = delete;

	ICrdnAxesFixedAtEpoch(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnAxesFixedAtEpoch();

	IATKOBJECT_VGT_SETGET_VGT_DECL(SourceAxes);
	IATKOBJECT_VGT_SETGET_CTIMEABS_DECL(AxesEpoch);
	IATKOBJECT_VGT_SETGET_VGT_DECL(ReferenceAxes);
};
