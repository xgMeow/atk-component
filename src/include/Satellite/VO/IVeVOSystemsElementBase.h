#pragma once
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"
struct CGfxOrbitSystem;

///
/// 相对轨迹基类
///
class IATKOBJECT_API IVeVOSystemsElementBase :public IClassInfo
{
public:
    IVeVOSystemsElementBase(const IVeVOSystemsElementBase&) = delete;
    IVeVOSystemsElementBase& operator=(const IVeVOSystemsElementBase&) = delete;

	IVeVOSystemsElementBase(CGfxOrbitSystem* vvlh);
	virtual ~IVeVOSystemsElementBase();

	//********************************************************************
	/// 设置相对轨迹颜色
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	nColor  颜色
	//********************************************************************
	void SetColor(int nColor);
	//********************************************************************
	/// 获得相对轨迹颜色
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	相对轨迹颜色	
	//********************************************************************
	int GetColor();

	//********************************************************************
	/// 设置相对轨迹是否使用默认颜色
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	bInherit  是否使用默认颜色
	//********************************************************************
	void SetInherit(bool bInherit);
	//********************************************************************
	/// 获得相对轨迹是否使用默认颜色
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	是否使用默认颜色，true-使用默认颜色，此时自定义颜色为false
	//********************************************************************
	bool GetInherit();


private:
	CGfxOrbitSystem*     m_vvlh;

};


