#pragma once
#include "../../IAtkObj.h"
#include "ICrdnVector.h"


///
/// VGT元素 角速度向量
///
class IATKOBJECT_API ICrdnVectorAngVelocity :public ICrdnVector
{
public:
    ICrdnVectorAngVelocity(const ICrdnVectorAngVelocity&) = delete;
    ICrdnVectorAngVelocity& operator=(const ICrdnVectorAngVelocity&) = delete;

	ICrdnVectorAngVelocity(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnVectorAngVelocity();

	IATKOBJECT_VGT_SETGET_VGT_DECL(Axes);
	IATKOBJECT_VGT_SETGET_VGT_DECL(ReferenceAxes);
	IATKOBJECT_VGT_SETGET_DECL(DiffStep, double);
};
