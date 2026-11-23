#pragma once
#include "../../IAtkObj.h"
#include "../ICrdn.h"


///
/// VGT元素基类 角
///
class IATKOBJECT_API ICrdnAngle :public ICrdn
{
public:
    ICrdnAngle(const ICrdnAngle&) = delete;
    ICrdnAngle& operator=(const ICrdnAngle&) = delete;

	ICrdnAngle(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnAngle();
	
	//********************************************************************
	/// 获得 VGT元素类型
	/// @author	Gan Shu Long
	/// @date	2026-06-03
	/// @return	VGT元素类型
	//********************************************************************
	ECrdnAngleType GetCrdnType();

	static ECrdnAngleType GetVGTTypeFromStr(std::string strType);
};
