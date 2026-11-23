#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
#include "ICrdnVector.h"


///
/// VGT元素 位移向量
///
class IATKOBJECT_API ICrdnVectorDisplacement :public ICrdnVector
{
public:
    ICrdnVectorDisplacement(const ICrdnVectorDisplacement&) = delete;
    ICrdnVectorDisplacement& operator=(const ICrdnVectorDisplacement&) = delete;

	ICrdnVectorDisplacement(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnVectorDisplacement();

	IATKOBJECT_VGT_SETGET_VGT_DECL(StartPoint);
	IATKOBJECT_VGT_SETGET_VGT_DECL(EndPoint);
	IATKOBJECT_VGT_SETGET_VGT_DECL(ReferenceSystem);
	IATKOBJECT_VGT_SETGET_DECL(IsApparent, bool);
	IATKOBJECT_VGT_SETGET_DECL(IgnoreAberration, bool);
	IATKOBJECT_VGT_SETGET_DECL(SignalSense, ESignalSense);
};
