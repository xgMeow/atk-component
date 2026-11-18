#pragma once
#include "../../IAtkObj.h"
#include "ICrdnAngle.h"


///
/// VGT元素 旋转角
///
class IATKOBJECT_API ICrdnAngleRotation :public ICrdnAngle
{
public:
    ICrdnAngleRotation(const ICrdnAngleRotation&) = delete;
    ICrdnAngleRotation& operator=(const ICrdnAngleRotation&) = delete;

	ICrdnAngleRotation(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnAngleRotation();

	IATKOBJECT_VGT_SETGET_VGT_DECL(AxesFrom);
	IATKOBJECT_VGT_SETGET_VGT_DECL(AxesTo);
	IATKOBJECT_VGT_SETGET_DECL(RefAxesIndex, int);      //0:x; 1:Y, 2:Z
};
