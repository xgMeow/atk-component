#pragma once
#include "../../IAtkObj.h"
#include "../ICrdn.h"


///
/// VGT元素基类 系统
///
class IATKOBJECT_API ICrdnSystem :public ICrdn
{
public:
    ICrdnSystem(const ICrdnSystem&) = delete;
    ICrdnSystem& operator=(const ICrdnSystem&) = delete;

	ICrdnSystem(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnSystem();
	
	//********************************************************************
	/// 获得 VGT元素类型
	/// @author	Gan Shu Long
	/// @date	2026-06-03
	/// @return	VGT元素类型
	//********************************************************************
	ECrdnSystemType GetCrdnType();

	static ECrdnSystemType GetVGTTypeFromStr(std::string strType);
};
