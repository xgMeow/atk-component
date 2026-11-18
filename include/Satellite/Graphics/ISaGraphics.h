#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
class CSatellite;
class IVeGfxAttributes;
class IVeGfxOrbitPassData;
class IVeGfxElevContours;
class IGfxRangeContours;
class IVeGfxSwath;
class IVeGfxGroundEllipsesCollection;
struct CGfxVeh2D;
struct CGfxVeh2DCustom;
struct CGfxVehPass;

///
/// 二维
///
class IATKOBJECT_API ISaGraphics
{
public:
    ISaGraphics(const ISaGraphics&) = delete;
    ISaGraphics& operator=(const ISaGraphics&) = delete;

	ISaGraphics(CSatellite* pSate);
	~ISaGraphics();

	//********************************************************************
	/// 判断二维显示是否支持此类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eAttributes  二维显示类型
	/// @return	true-支持此类型
	//********************************************************************
	bool IsAttributesTypeSupported(EVeGfxAttributes eAttributes);

	//********************************************************************
	/// 设置二维显示类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eAttributes  二维显示类型
	/// 支持类型：
	/// eAttributesBasic 1 基础类型
	/// eAttributesCustom 2 自定义类型
	//********************************************************************
	void SetAttributesType(EVeGfxAttributes eAttributes);

	//********************************************************************
	/// 获得二维显示类型属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return 二维显示类型指针
	//********************************************************************
	IVeGfxAttributes* GetAttributes();

	//********************************************************************
	/// 获得二维显示支持类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return 二维显示支持类型
	//********************************************************************
	std::vector<std::string> GetAttributesSupportedTypes();

	//********************************************************************
	/// 获得二维显示类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return 二维显示类型
	//********************************************************************
	EVeGfxAttributes GetAttributesType();

	//********************************************************************
	/// 获得二维轨迹属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	二维属性指针	
	//********************************************************************
	IVeGfxOrbitPassData* GetPassData() { return m_PassData; }

	//********************************************************************
	/// 获得二维等高线属性
	/// @author	Gan Shu Long
	/// @date	2026-10-19
	/// @return	二维等高线指针		
	//********************************************************************
	IVeGfxElevContours* GetElevContours() { return m_ElevContours; }

	//********************************************************************
	/// 获得二维范围属性
	/// @author	Gan Shu Long
	/// @date	2026-10-19
	/// @return	二维范围指针		
	//********************************************************************
	IGfxRangeContours* GetRangeContours() { return m_RangeContours; }

	//********************************************************************
	/// 获得二维刈幅
	/// @author	Gan Shu Long
	/// @date	2026-10-19
	/// @return	二维刈幅指针	
	//********************************************************************
	IVeGfxSwath* GetSwath() { return m_Swath; }

	//********************************************************************
	/// 获得地面椭圆设置集合
	/// @author	Gan Shu Long
	/// @date	2026-10-19
	/// @return	地面椭圆设置集合指针
	//********************************************************************
	IVeGfxGroundEllipsesCollection* GetGroundEllipses();

private:
	CSatellite*								m_pSate;                        
	IVeGfxAttributes*						m_Attributes;                   //二维显示类型指针
	IVeGfxOrbitPassData*					m_PassData;                     //二维轨迹指针	
	IVeGfxElevContours*						m_ElevContours;                 //二维等高线	
	IGfxRangeContours*						m_RangeContours;				//二维范围
	IVeGfxSwath*							m_Swath;						//二维刈幅	
	IVeGfxGroundEllipsesCollection*			m_GroundEllipses;               //二维地面椭圆	

};

