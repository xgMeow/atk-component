#pragma once
#include "../IAtkObj.h"
#include "../IClassInfo.h" 
#include "../ICEnum.h"

///
/// 天线极化
///
class IATKOBJECT_API IPolarization :public IClassInfo
{
public:
    IPolarization(const IPolarization&) = delete;
    IPolarization& operator=(const IPolarization&) = delete;

	IPolarization();
	virtual ~IPolarization();
	
	//********************************************************************
	/// 获得 天线极化类型
	/// @author	Gan Shu Long
	/// @date	2026-03-10
	/// @return	天线极化类型
	//********************************************************************
	EPolarizationType GetType() { return ePolarizationTypeUnknown; }
};
