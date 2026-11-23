#pragma once
#include <string>
#include "IVeVOSystemsElementBase.h"
struct CGfxOrbitSystem;

///
/// 相对轨迹属性
///
class IATKOBJECT_API IVeVOSystemsElement : public IVeVOSystemsElementBase
{
public:
    IVeVOSystemsElement(const IVeVOSystemsElement&) = delete;
    IVeVOSystemsElement& operator=(const IVeVOSystemsElement&) = delete;

	IVeVOSystemsElement(CGfxOrbitSystem* vvlh, std::string strName);
	~IVeVOSystemsElement();

	//********************************************************************
	/// 相对轨迹是否显示
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	bVisible  是否显示
	//********************************************************************
	void SetIsVisible(bool bVisible);
	//********************************************************************
	/// 获得相对轨迹是否显示
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	相对轨迹是否显示，true-显示
	//********************************************************************
	bool GetIsVisible();

	//********************************************************************
	/// 相对轨迹名称
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	相对轨迹名称
	//********************************************************************
	std::string GetName();

private:
	CGfxOrbitSystem*     m_vvlh;
	std::string          m_Name;
};

