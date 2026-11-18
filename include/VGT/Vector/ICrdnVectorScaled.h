#pragma once
#include "../../IAtkObj.h"
#include "ICrdnVector.h"


///
/// VGT元素 缩放向量
///
class IATKOBJECT_API ICrdnVectorScaled :public ICrdnVector
{
public:
    ICrdnVectorScaled(const ICrdnVectorScaled&) = delete;
    ICrdnVectorScaled& operator=(const ICrdnVectorScaled&) = delete;

	ICrdnVectorScaled(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnVectorScaled();

	IATKOBJECT_VGT_SETGET_VGT_DECL(Vector);
	IATKOBJECT_VGT_SETGET_DECL(ScaleFac, double);
	IATKOBJECT_VGT_SETGET_DECL(Norm, bool);
};
