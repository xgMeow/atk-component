#pragma once
#include "../../IAtkObj.h"
#include "ICrdnVector.h"


///
/// VGT元素 导数向量
///
class IATKOBJECT_API ICrdnVectorDerivative :public ICrdnVector
{
public:
    ICrdnVectorDerivative(const ICrdnVectorDerivative&) = delete;
    ICrdnVectorDerivative& operator=(const ICrdnVectorDerivative&) = delete;

	ICrdnVectorDerivative(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnVectorDerivative();

	IATKOBJECT_VGT_SETGET_VGT_DECL(CurrentAxes);
	IATKOBJECT_VGT_SETGET_VGT_DECL(Vector);
	IATKOBJECT_VGT_SETGET_DECL(DiffTimeStep, double);
};
