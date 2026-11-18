#pragma once
#include <string>
#include <vector>
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
class CMissile;
class IVeGfxAttributes;
class IVeGfxTrajectoryPassData;
class IVeGfxElevContours;
class IGfxRangeContours;
class IVeGfxSwath;
class IVeGfxGroundEllipsesCollection;

///
/// 导弹二维属性
///
class IATKOBJECT_API IMsGraphics
{
public:
    IMsGraphics(const IMsGraphics&) = delete;
    IMsGraphics& operator=(const IMsGraphics&) = delete;

	IMsGraphics(CMissile* pCMissile);
	~IMsGraphics();

	//********************************************************************
	/// 判断二维显示是否支持此类型
	/// @author	Gan Shu Long
	/// @date	2024-09-25
	/// @param[in]	eAttributes  二维显示类型
	/// @return	true-支持此类型
	//********************************************************************
	bool IsAttributesTypeSupported(EVeGfxAttributes eAttributes);

	//********************************************************************
	/// 设置二维显示类型
	/// @author	Gan Shu Long
	/// @date	2024-09-25
	/// @param[in]	eAttributes  二维显示类型
	/// 支持类型：
	/// eAttributesBasic 1 基础类型
	//********************************************************************
	void SetAttributesType(EVeGfxAttributes eAttributes);

	//********************************************************************
	/// 获得二维显示类型属性
	/// @author	Gan Shu Long
	/// @date	2024-09-25
	/// @return 二维显示类型指针
	//********************************************************************
	IVeGfxAttributes* GetAttributes() { return m_Attributes; }

	//********************************************************************
	/// 获得二维显示支持类型
	/// @author	Gan Shu Long
	/// @date	2024-09-25
	/// @return 二维显示支持类型
	//********************************************************************
	std::vector<std::string> GetAttributesSupportedTypes();

	//********************************************************************
	/// 获得二维显示类型
	/// @author	Gan Shu Long
	/// @date	2024-09-25
	/// @return 二维显示类型
	//********************************************************************
	EVeGfxAttributes GetAttributesType();

	//********************************************************************
	/// 获得二维轨迹属性
	/// @author	Gan Shu Long
	/// @date	2024-09-25
	/// @return	二维属性指针	
	//********************************************************************
	IVeGfxTrajectoryPassData* GetPassData() { return m_PassData; }

	//********************************************************************
	/// 获得二维等高线属性
	/// @author	Gan Shu Long
	/// @date	2026-01-28
	/// @return	二维等高线指针		
	//********************************************************************
	IVeGfxElevContours* GetElevContours() { return m_ElevContours; }
	
	//********************************************************************
	/// 获得二维范围属性
	/// @author	Gan Shu Long
	/// @date	2026-01-28
	/// @return	二维范围指针	
	//********************************************************************
	IGfxRangeContours* GetRangeContours() { return m_RangeContours; }
	
	//********************************************************************
	/// 获得二维刈幅
	/// @author	Gan Shu Long
	/// @date	2026-01-28
	/// @return	二维刈幅
	//********************************************************************
	IVeGfxSwath* GetSwath() { return m_Swath; }
	
	//********************************************************************
	/// 获得地面椭圆设置集合
	/// @author	Gan Shu Long
	/// @date	2026-01-28
	/// @return	地面椭圆设置集合指针
	//********************************************************************
	IVeGfxGroundEllipsesCollection* GetGroundEllipses();

private:
	CMissile*											m_pCMissile;					//C对象

	IVeGfxAttributes*								m_Attributes;								//二维显示类型指针
	IVeGfxTrajectoryPassData*			m_PassData;								//二维轨迹指针
	IVeGfxElevContours*						m_ElevContours;						//二维等高线
	IGfxRangeContours*						m_RangeContours;					//二维范围
	IVeGfxSwath*									m_Swath;									//二维刈幅
	IVeGfxGroundEllipsesCollection*	m_GroundEllipses;						//二维地面椭圆
};
