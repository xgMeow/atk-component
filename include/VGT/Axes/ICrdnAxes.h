#pragma once
#include "../../IAtkObj.h"
#include "../ICrdn.h"


///
/// VGT元素基类 轴
///
class IATKOBJECT_API ICrdnAxes :public ICrdn
{
public:
    ICrdnAxes(const ICrdnAxes&) = delete;
    ICrdnAxes& operator=(const ICrdnAxes&) = delete;

	ICrdnAxes(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnAxes();
	
	//********************************************************************
	/// 获得 VGT元素类型
	/// @author	Gan Shu Long
	/// @date	2026-06-03
	/// @return	VGT元素类型
	//********************************************************************
	ECrdnAxesType GetCrdnType();

	static ECrdnAxesType GetVGTTypeFromStr(std::string strType);
};
