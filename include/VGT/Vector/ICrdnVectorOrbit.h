#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
#include "ICrdnVector.h"


///
/// VGT元素 轨道向量
///
class IATKOBJECT_API ICrdnVectorOrbit :public ICrdnVector
{
public:
    ICrdnVectorOrbit(const ICrdnVectorOrbit&) = delete;
    ICrdnVectorOrbit& operator=(const ICrdnVectorOrbit&) = delete;

	ICrdnVectorOrbit(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnVectorOrbit();


	IATKOBJECT_VGT_SETGET_DECL(UseCBI, bool);
	IATKOBJECT_VGT_SETGET_CENTRALBODY_DECL(CentralBody);
	IATKOBJECT_VGT_SETGET_VGT_DECL(Point);
	IATKOBJECT_VGT_SETGET_DECL(MeanOscType, EMeanOscType);
	IATKOBJECT_VGT_SETGET_DECL(VectorType, EOrbitVectorType);
	IATKOBJECT_VGT_SETGET_VGT_DECL(RefSystem);
};
