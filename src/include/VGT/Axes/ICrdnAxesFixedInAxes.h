#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
#include "ICrdnAxes.h"


///
/// VGT元素 固定坐标轴
///
class IATKOBJECT_API ICrdnAxesFixedInAxes :public ICrdnAxes
{
public:
    ICrdnAxesFixedInAxes(const ICrdnAxesFixedInAxes&) = delete;
    ICrdnAxesFixedInAxes& operator=(const ICrdnAxesFixedInAxes&) = delete;

	ICrdnAxesFixedInAxes(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnAxesFixedInAxes();

	IATKOBJECT_VGT_SETGET_VGT_DECL(ReferenceAxes);
	IATKOBJECT_VGT_SETGET_DECL(AttitudeType, EAttitudeType);  //0-2:eAsQuaternion/eAsEuler/eAsYPR
	IATKOBJECT_VGT_SETGET_DECL(Qx, double);
	IATKOBJECT_VGT_SETGET_DECL(Qy, double);
	IATKOBJECT_VGT_SETGET_DECL(Qz, double);
	IATKOBJECT_VGT_SETGET_DECL(Qs, double);
	IATKOBJECT_VGT_SETGET_DEG_DECL(EulerAngle1, double);
	IATKOBJECT_VGT_SETGET_DEG_DECL(EulerAngle2, double);
	IATKOBJECT_VGT_SETGET_DEG_DECL(EulerAngle3, double);
	IATKOBJECT_VGT_SETGET_DEG_DECL(Yaw, double);
	IATKOBJECT_VGT_SETGET_DEG_DECL(Pitch, double);
	IATKOBJECT_VGT_SETGET_DEG_DECL(Roll, double);
	IATKOBJECT_VGT_SETGET_DECL(Sequence, int);                  //"rpy"(123);"ryp"(132);"pry"(213);"pyr"(231);"yrp"(312);"ypr"(321);
};
