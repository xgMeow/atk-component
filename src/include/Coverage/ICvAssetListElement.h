#pragma once
#include "../IAtkObj.h"
#include "../ICEnum.h"
#include <string>

///
/// 覆盖性对象元素
///
class IATKOBJECT_API ICvAssetListElement
{
public:
	ICvAssetListElement(const ICvAssetListElement&) = delete;
	ICvAssetListElement& operator=(const ICvAssetListElement&) = delete;

	ICvAssetListElement(std::string strObjPath);
	~ICvAssetListElement();

	//********************************************************************
	/// 设置覆盖性计算对象是否是计算状态
	/// @author	Gan Shu Long
	/// @date	2026-10-01
	/// @param[in]	eCvAssetStatus  计算对象计算状态
	//********************************************************************
	void SetAssetStatus(ECvAssetStatus eCvAssetStatus);

	//********************************************************************
	/// 获得覆盖性计算对象是否是计算状态
	/// @author	Gan Shu Long
	/// @date	2026-10-01
	/// @return	计算对象计算状态，eActive-可计算
	//********************************************************************
	ECvAssetStatus GetAssetStatus();

	//********************************************************************
	/// 获得覆盖性计算对象路径
	/// @author	Gan Shu Long
	/// @date	2026-10-01
	/// @return	对象路径名称
	//********************************************************************
	std::string GetObjectName();

private:
	ECvAssetStatus     m_AssetStatus;   //是否参与计算
	std::string        m_ObjectName;    //对象路径名称


};
