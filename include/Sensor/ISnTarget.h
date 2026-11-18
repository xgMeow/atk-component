#pragma once
#include "../IAtkObj.h"
#include <string>

///
/// 目标定向已选对象
///
class IATKOBJECT_API ISnTarget
{
public:
    ISnTarget(const ISnTarget&) = delete;
    ISnTarget& operator=(const ISnTarget&) = delete;

	ISnTarget(std::string strObjPathName);
	~ISnTarget();

	//********************************************************************
	/// 获得目标对象名称
	/// @author	Gan Shu Long
	/// @date	2026-03-24
	/// @return	目标对象名称
	//********************************************************************
	std::string GetName() { return m_Name; }

private:
	std::string		m_Name;
};
