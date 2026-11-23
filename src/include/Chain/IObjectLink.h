#pragma once
#include "../IAtkObj.h"
#include <string>
#include "../ICEnum.h"
class IAtkObject;

///
/// 链接对象
///
class IATKOBJECT_API IObjectLink
{
public:
    IObjectLink(const IObjectLink&) = delete;
    IObjectLink& operator=(const IObjectLink&) = delete;

	IObjectLink(IAtkObject* pIAtkObject);
	~IObjectLink();

	//********************************************************************
	/// 获得链接对象接口指针
	/// @author	Gan Shu Long
	/// @date	2026-01-12
	/// @return	链接对象接口指针
	//********************************************************************
	IAtkObject* GetLinkedObject();

	//********************************************************************
	/// 获得链接对象名称
	/// @author	Gan Shu Long
	/// @date	2026-01-12
	/// @return	链接对象名称
	//********************************************************************
	std::string GetName();

	//********************************************************************
	/// 获得链接对象路径
	/// @author	Gan Shu Long
	/// @date	2026-01-12
	/// @return	链接对象路径
	//********************************************************************
	std::string GetPath();

	//********************************************************************
	/// 获得链接对象类型
	/// @author	Gan Shu Long
	/// @date	2026-01-12
	/// @return	链接对象类型
	//********************************************************************
	EATKObjectType GetType();

private:
	IAtkObject*		m_pIAtkObject;
};
