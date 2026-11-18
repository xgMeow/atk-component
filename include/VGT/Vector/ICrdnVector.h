#pragma once
#include "../../IAtkObj.h"
#include "../ICrdn.h"


///
/// VGT元素基类 向量
///
class IATKOBJECT_API ICrdnVector :public ICrdn
{
public:
    ICrdnVector(const ICrdnVector&) = delete;
    ICrdnVector& operator=(const ICrdnVector&) = delete;

	ICrdnVector(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnVector();
	
	//********************************************************************
	/// 获得 VGT元素类型
	/// @author	Gan Shu Long
	/// @date	2026-06-03
	/// @return	VGT元素类型
	//********************************************************************
	ECrdnVectorType GetCrdnType();

	static ECrdnVectorType GetVGTTypeFromStr(std::string strType);
};
