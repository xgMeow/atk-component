#pragma once
#include <string>
#include "IAtkObj.h"
class CObjectBase;

///
/// 基本属性
///
#pragma warning(disable : 4251)
class IATKOBJECT_API  IClassInfo
{
public:
    IClassInfo(const IClassInfo&) = delete;
    IClassInfo& operator=(const IClassInfo&) = delete;

	IClassInfo(CObjectBase* pObjBase);
	virtual ~IClassInfo();

	 std::string			GetClassInfoName() { return m_ClassName; };			///<对象类名

	//********************************************************************
	/// 设置对象属性值
	/// @author	Dong Min
	/// @date	2025-06-24
	/// @param[in]	strObjPath   属性设置路径
	/// @param[in]	strValue   属性值
	/// @return	
	//********************************************************************
	 bool	SetAttribute(std::string strObjPath, std::string strValue);
	 
	//********************************************************************
	/// 获取对象属性值
	/// @author	Dong Min
	/// @date	2025-06-24
	/// @param[in]	strObjPath   属性设置路径 
	/// @return	 属性值
	//********************************************************************
	 std::string GetAttribute(std::string strObjPath);

	 //********************************************************************
	 /// 对象参数设置界面
	 /// @author	Dong Min
	 /// @date	2025-12-01
	 /// @note 参数 strObjPath：属性设置路径
	 /// @note 参数 strValue：属性值
	 /// @return	
	 //********************************************************************
	 virtual bool	SetUiParameter();


protected:
	CObjectBase*        m_pObjBase;
	std::string			m_ClassName;

};
