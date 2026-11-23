#pragma once
#include "../../IAtkObj.h"
#include "ICrdnVector.h"


///
/// VGT元素 固定向量
///
class IATKOBJECT_API ICrdnVectorFixed :public ICrdnVector
{
public:
    ICrdnVectorFixed(const ICrdnVectorFixed&) = delete;
    ICrdnVectorFixed& operator=(const ICrdnVectorFixed&) = delete;

	ICrdnVectorFixed(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnVectorFixed();

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

	IATKOBJECT_VGT_SETGET_VGT_DECL(ReferenceAxes);
};
