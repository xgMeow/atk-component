#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
#include "ICrdnVector.h"


///
/// VGT元素 线性组合向量
///
class IATKOBJECT_API ICrdnVectorLinearComb :public ICrdnVector
{
public:
    ICrdnVectorLinearComb(const ICrdnVectorLinearComb&) = delete;
    ICrdnVectorLinearComb& operator=(const ICrdnVectorLinearComb&) = delete;

	ICrdnVectorLinearComb(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnVectorLinearComb();


	IATKOBJECT_VGT_SETGET_VGT_DECL(VectorA);
	IATKOBJECT_VGT_SETGET_DECL(ScaleFactorA, double);
	IATKOBJECT_VGT_SETGET_DECL(NormalizeA, bool);
	IATKOBJECT_VGT_SETGET_VGT_DECL(VectorB);
	IATKOBJECT_VGT_SETGET_DECL(ScaleFactorB, double);
	IATKOBJECT_VGT_SETGET_DECL(NormalizeB, bool);
	IATKOBJECT_VGT_SETGET_DECL(InheritDimension, EInheritDimensionType);
	IATKOBJECT_VGT_SETGET_DECL(Dimension, EDimension);
};
