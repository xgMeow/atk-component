#pragma once
#include "../../IAtkObj.h"
#include "ICrdnVector.h"


///
/// VGT元素 反射向量
///
class IATKOBJECT_API ICrdnVectorReflection :public ICrdnVector
{
public:
    ICrdnVectorReflection(const ICrdnVectorReflection&) = delete;
    ICrdnVectorReflection& operator=(const ICrdnVectorReflection&) = delete;

	ICrdnVectorReflection(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnVectorReflection();

	IATKOBJECT_VGT_SETGET_VGT_DECL(VectorIn);
	IATKOBJECT_VGT_SETGET_DECL(UseOppo, bool);
	IATKOBJECT_VGT_SETGET_VGT_DECL(VectorNormal);
	IATKOBJECT_VGT_SETGET_DECL(ReflectOnBack, bool);
	IATKOBJECT_VGT_SETGET_DECL(ScaleFactor, double);
};
