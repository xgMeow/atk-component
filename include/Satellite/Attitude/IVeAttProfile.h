#pragma once
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"
#include <string>
struct CObjData;

///
/// 姿态属性
///
class IATKOBJECT_API IVeAttProfile : public IClassInfo
{
public:
    IVeAttProfile(const IVeAttProfile&) = delete;
    IVeAttProfile& operator=(const IVeAttProfile&) = delete;

	IVeAttProfile(CObjData* pObjData);
	~IVeAttProfile();

	//********************************************************************
	/// 获得姿态生成方式
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	姿态生成方式
	//********************************************************************
	std::string GetType();

private:
	CObjData*                m_pObjData; 

};
