#pragma once
#include "../../IAtkObj.h"
#include "ICrdnSystem.h"


///
/// VGT元素 站心坐标系
///
class IATKOBJECT_API ICrdnSystemTopocentric :public ICrdnSystem
{
public:
    ICrdnSystemTopocentric(const ICrdnSystemTopocentric&) = delete;
    ICrdnSystemTopocentric& operator=(const ICrdnSystemTopocentric&) = delete;

	ICrdnSystemTopocentric(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnSystemTopocentric();

	IATKOBJECT_VGT_SETGET_VGT_DECL(Point);
	IATKOBJECT_VGT_SETGET_CENTRALBODY_DECL(CentralBody);
};
