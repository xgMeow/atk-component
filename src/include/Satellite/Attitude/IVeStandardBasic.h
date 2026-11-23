#pragma once
#include <string>
#include <vector>
#include "../../ICEnum.h"
#include "../../IAtkObj.h"
struct CObjData;
struct CVehAttSegment;
class IVeAttProfile;

///
/// 标准姿态类型属性
///
class IATKOBJECT_API IVeStandardBasic
{
public:
    IVeStandardBasic(const IVeStandardBasic&) = delete;
    IVeStandardBasic& operator=(const IVeStandardBasic&) = delete;

	IVeStandardBasic(CObjData* pObjData);
	~IVeStandardBasic();

	//********************************************************************
	/// 判断是否支持输入类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eProfile   姿态类型
	/// @return	true-对象支持此姿态类型	
	//********************************************************************
	bool IsProfileTypeSupported(EVeProfile eProfile);

	//********************************************************************
	/// 设置姿态类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eProfile   姿态类型
	//********************************************************************
	void SetProfileType(EVeProfile eProfile);

	//********************************************************************
	/// 获得姿态类型属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	姿态类型属性
	//********************************************************************
	IVeAttProfile* GetProfile() { return m_Profile; }

	//********************************************************************
	/// 获得支持的姿态类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	支持的姿态类型
	//********************************************************************
	std::vector<std::string> GetProfileSupportedTypes();

	//********************************************************************
	/// 获得姿态类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	姿态类型
	//********************************************************************
	EVeProfile GetProfileType();

private:
	CObjData*					m_pObjData;
	CVehAttSegment*		m_pCVehAttSegment;

	IVeAttProfile*               m_Profile;                 //姿态类型属性

	std::string ProTypeToString(EVeProfile eProfileType);   //姿态类型转字符串

};



