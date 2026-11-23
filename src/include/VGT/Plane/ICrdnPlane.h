#pragma once
#include "../../IAtkObj.h"
#include "../ICrdn.h"


///
/// VGT元素基类 平面
///
class IATKOBJECT_API ICrdnPlane :public ICrdn
{
public:
    ICrdnPlane(const ICrdnPlane&) = delete;
    ICrdnPlane& operator=(const ICrdnPlane&) = delete;

	ICrdnPlane(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnPlane();
	
	//********************************************************************
	/// 获得 VGT元素类型
	/// @author	Gan Shu Long
	/// @date	2026-06-03
	/// @return	VGT元素类型
	//********************************************************************
	ECrdnPlaneType GetCrdnType();

	static ECrdnPlaneType GetVGTTypeFromStr(std::string strType);
};
