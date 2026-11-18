#pragma once
#include "../../IAtkObj.h"
#include "ICrdnPoint.h"
#include "../../ICEnum.h"


///
/// VGT元素 固定点
///
class IATKOBJECT_API ICrdnPointFixed :public ICrdnPoint
{
public:
    ICrdnPointFixed(const ICrdnPointFixed&) = delete;
    ICrdnPointFixed& operator=(const ICrdnPointFixed&) = delete;

	ICrdnPointFixed(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnPointFixed();

	//********************************************************************
	/// 设置 坐标类型
	/// @author	Gan Shu Long
	/// @date	2026-06-08
	/// @param[in]	eCrdnPointCoordType  坐标类型
	//********************************************************************
	void SetCoordType(ECrdnPointCoordType eCrdnPointCoordType);
	
	//********************************************************************
	/// 获得 坐标类型
	/// @author	Gan Shu Long
	/// @date	2026-06-08
	/// @return	坐标类型
	//********************************************************************
	ECrdnPointCoordType GetCoordType();

	//********************************************************************
	/// 设置 坐标类型
	/// @author	Gan Shu Long
	/// @date	2026-06-08
	/// @param[in]	dX X(m)/Lat(deg)
	/// @param[in]	dY Y(m)/Lon(deg)
	/// @param[in]	dZ Z(m)/Rad(m)
	//********************************************************************
	void SetCoordValue(double dX, double dY, double dZ);

	//********************************************************************
	/// 获得 坐标类型
	/// @author	Gan Shu Long
	/// @date	2026-06-08
	/// @param[in]	dX X(m)/Lat(deg)
	/// @param[in]	dY Y(m)/Lon(deg)
	/// @param[in]	dZ Z(m)/Rad(m)
	//********************************************************************
	void GetCoordValue(double& dX, double& dY, double& dZ);

	IATKOBJECT_VGT_SETGET_VGT_DECL(ReferenceSystem);
};
