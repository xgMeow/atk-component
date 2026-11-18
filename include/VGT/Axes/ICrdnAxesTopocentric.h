#pragma once
#include "../../IAtkObj.h"
#include "ICrdnAxes.h"


///
/// VGT元素 站心坐标轴
///
class IATKOBJECT_API ICrdnAxesTopocentric :public ICrdnAxes
{
public:
    ICrdnAxesTopocentric(const ICrdnAxesTopocentric&) = delete;
    ICrdnAxesTopocentric& operator=(const ICrdnAxesTopocentric&) = delete;

	ICrdnAxesTopocentric(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnAxesTopocentric();

	IATKOBJECT_VGT_SETGET_VGT_DECL(Point);
	IATKOBJECT_VGT_SETGET_CENTRALBODY_DECL(CentralBody);
};
