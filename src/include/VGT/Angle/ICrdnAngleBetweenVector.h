#pragma once
#include "../../IAtkObj.h"
#include "ICrdnAngle.h"


///
/// VGT元素 矢量间夹角
///
class IATKOBJECT_API ICrdnAngleBetweenVector :public ICrdnAngle
{
public:
    ICrdnAngleBetweenVector(const ICrdnAngleBetweenVector&) = delete;
    ICrdnAngleBetweenVector& operator=(const ICrdnAngleBetweenVector&) = delete;

	ICrdnAngleBetweenVector(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnAngleBetweenVector();

	IATKOBJECT_VGT_SETGET_VGT_DECL(VectorFrom);
	IATKOBJECT_VGT_SETGET_VGT_DECL(VectorTo);
};
