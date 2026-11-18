#pragma once
#include "../../IAtkObj.h"
#include "ICrdnVector.h"


///
/// VGT元素 速度向量
///
class IATKOBJECT_API ICrdnVectorVel :public ICrdnVector
{
public:
    ICrdnVectorVel(const ICrdnVectorVel&) = delete;
    ICrdnVectorVel& operator=(const ICrdnVectorVel&) = delete;

	ICrdnVectorVel(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnVectorVel();

	IATKOBJECT_VGT_SETGET_DECL(DiffTimeStep, double);
	IATKOBJECT_VGT_SETGET_VGT_DECL(Point);
	IATKOBJECT_VGT_SETGET_VGT_DECL(ReferenceSystem);
};
