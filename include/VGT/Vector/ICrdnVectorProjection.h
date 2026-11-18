#pragma once
#include "../../IAtkObj.h"
#include "ICrdnVector.h"


///
/// VGT元素 投影向量
///
class IATKOBJECT_API ICrdnVectorProjection :public ICrdnVector
{
public:
    ICrdnVectorProjection(const ICrdnVectorProjection&) = delete;
    ICrdnVectorProjection& operator=(const ICrdnVectorProjection&) = delete;

	ICrdnVectorProjection(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnVectorProjection();

	IATKOBJECT_VGT_SETGET_VGT_DECL(ReferencePlane);
	IATKOBJECT_VGT_SETGET_VGT_DECL(Vector);
};
