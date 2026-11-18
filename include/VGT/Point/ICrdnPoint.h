#pragma once
#include "../../IAtkObj.h"
#include "../ICrdn.h"


///
/// VGT元素基类 点
///
class IATKOBJECT_API ICrdnPoint :public ICrdn
{
public:
    ICrdnPoint(const ICrdnPoint&) = delete;
    ICrdnPoint& operator=(const ICrdnPoint&) = delete;

	ICrdnPoint(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnPoint();
	
	//********************************************************************
	/// 获得 VGT元素类型
	/// @author	Gan Shu Long
	/// @date	2026-06-03
	/// @return	VGT元素类型
	//********************************************************************
	ECrdnPointType GetCrdnType();

	static ECrdnPointType GetVGTTypeFromStr(std::string strType);
};
