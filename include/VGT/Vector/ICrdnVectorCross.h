#pragma once
#include "../../IAtkObj.h"
#include "ICrdnVector.h"


///
/// VGT元素 叉积向量
///
class IATKOBJECT_API ICrdnVectorCross :public ICrdnVector
{
public:
    ICrdnVectorCross(const ICrdnVectorCross&) = delete;
    ICrdnVectorCross& operator=(const ICrdnVectorCross&) = delete;

	ICrdnVectorCross(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnVectorCross();

	IATKOBJECT_VGT_SETGET_VGT_DECL(VectorFrom);
	IATKOBJECT_VGT_SETGET_VGT_DECL(VectorTo);
};
