#pragma once
#include "../../IAtkObj.h"
#include "ICrdnAngle.h"


///
/// VGT元素 常量角
///
class IATKOBJECT_API ICrdnAngleConstant :public ICrdnAngle
{
public:
    ICrdnAngleConstant(const ICrdnAngleConstant&) = delete;
    ICrdnAngleConstant& operator=(const ICrdnAngleConstant&) = delete;

	ICrdnAngleConstant(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnAngleConstant();

	IATKOBJECT_VGT_SETGET_DEG_DECL(ConstantAngle, double);
};
