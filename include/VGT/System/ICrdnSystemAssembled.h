#pragma once
#include "../../IAtkObj.h"
#include "ICrdnSystem.h"


///
/// VGT元素 组装系统
///
class IATKOBJECT_API ICrdnSystemAssembled :public ICrdnSystem
{
public:
    ICrdnSystemAssembled(const ICrdnSystemAssembled&) = delete;
    ICrdnSystemAssembled& operator=(const ICrdnSystemAssembled&) = delete;

	ICrdnSystemAssembled(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnSystemAssembled();
};
