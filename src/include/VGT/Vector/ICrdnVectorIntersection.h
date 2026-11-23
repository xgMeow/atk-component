#pragma once
#include "../../IAtkObj.h"
#include "ICrdnVector.h"


///
/// VGT元素 交线向量
///
class IATKOBJECT_API ICrdnVectorIntersection :public ICrdnVector
{
public:
    ICrdnVectorIntersection(const ICrdnVectorIntersection&) = delete;
    ICrdnVectorIntersection& operator=(const ICrdnVectorIntersection&) = delete;

	ICrdnVectorIntersection(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnVectorIntersection();

	IATKOBJECT_VGT_SETGET_VGT_DECL(PlaneA);
	IATKOBJECT_VGT_SETGET_VGT_DECL(PlaneB);
};
