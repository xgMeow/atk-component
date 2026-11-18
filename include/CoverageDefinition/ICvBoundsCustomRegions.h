#pragma once
#include "../IAtkObj.h"
#include "ICvBounds.h"
class CCoverageDefinition;
class ICvAreaTargetsCollection;
class CObjManage;

///
/// 自定义区域
///
class IATKOBJECT_API ICvBoundsCustomRegions :public ICvBounds
{
public:
    ICvBoundsCustomRegions(const ICvBoundsCustomRegions&) = delete;
    ICvBoundsCustomRegions& operator=(const ICvBoundsCustomRegions&) = delete;

	ICvBoundsCustomRegions(CCoverageDefinition* pCCoverageDefinition,  CObjManage* IAsGObjManage);
	~ICvBoundsCustomRegions();

	//********************************************************************
	/// 获得区域目标列表
	/// @author	Gan Shu Long
	/// @date	2026-01-14
	/// @return	区域目标列表
	//********************************************************************
	ICvAreaTargetsCollection* GetAreaTargets() { return m_AreaTargets; }

private:
	ICvAreaTargetsCollection*				m_AreaTargets;						//区域目标列表
};
