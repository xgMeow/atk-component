#pragma once
#include "../../IAtkObj.h"
#include "ICrdnVector.h"


///
/// VGT元素 加速度向量
///
class IATKOBJECT_API ICrdnVectorAcc :public ICrdnVector
{
public:
    ICrdnVectorAcc(const ICrdnVectorAcc&) = delete;
    ICrdnVectorAcc& operator=(const ICrdnVectorAcc&) = delete;

	ICrdnVectorAcc(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnVectorAcc();

	IATKOBJECT_VGT_SETGET_DECL(DiffTimeStep, double);
	IATKOBJECT_VGT_SETGET_VGT_DECL(Point);
	IATKOBJECT_VGT_SETGET_VGT_DECL(ReferenceSystem);
};
