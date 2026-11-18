#pragma once
#include "../../IAtkObj.h"
#include "ICrdnAngle.h"


///
/// VGT元素 两面角
///
class IATKOBJECT_API ICrdnAngleDihedral :public ICrdnAngle
{
public:
    ICrdnAngleDihedral(const ICrdnAngleDihedral&) = delete;
    ICrdnAngleDihedral& operator=(const ICrdnAngleDihedral&) = delete;

	ICrdnAngleDihedral(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnAngleDihedral();

	IATKOBJECT_VGT_SETGET_VGT_DECL(VectorFrom);
	IATKOBJECT_VGT_SETGET_VGT_DECL(VectorTo);
	IATKOBJECT_VGT_SETGET_VGT_DECL(VectorAbout);
	IATKOBJECT_VGT_SETGET_DECL(RightHanded, bool);          //false:Postive; true:Negative
	IATKOBJECT_VGT_SETGET_DECL(Signed, bool);               //false:-180to 180 deg; true:0tp 360 deg
};
