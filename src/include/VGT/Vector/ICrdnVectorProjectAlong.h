#pragma once
#include "../../IAtkObj.h"
#include "ICrdnVector.h"


///
/// VGT元素 方向投影向量
///
class IATKOBJECT_API ICrdnVectorProjectAlong :public ICrdnVector
{
public:
    ICrdnVectorProjectAlong(const ICrdnVectorProjectAlong&) = delete;
    ICrdnVectorProjectAlong& operator=(const ICrdnVectorProjectAlong&) = delete;

	ICrdnVectorProjectAlong(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnVectorProjectAlong();

	IATKOBJECT_VGT_SETGET_VGT_DECL(VectorFrom);
	IATKOBJECT_VGT_SETGET_VGT_DECL(VectorTo);
};
