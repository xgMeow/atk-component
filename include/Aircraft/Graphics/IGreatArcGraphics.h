#pragma once
#include <string>
#include <vector>
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
#include "../../IClassInfo.h"
class IVeGfxOrbitPassData;
class IVeGfxAttributes;
class IGfxRangeContours;
class IVeGfxGroundEllipsesCollection;
struct CObjData;
struct CGfxVeh2D;
struct CVehEllipseSet;

///
/// 交通工具基类二维属性
///
class IATKOBJECT_API IGreatArcGraphics :public IClassInfo
{
public:
    IGreatArcGraphics(const IGreatArcGraphics&) = delete;
    IGreatArcGraphics& operator=(const IGreatArcGraphics&) = delete;

	IGreatArcGraphics(CObjData* pObjData);
	virtual ~IGreatArcGraphics();

	//********************************************************************
	/// 判断二维显示是否支持此类型
	/// @author	Gan Shu Long
	/// @date	2024-06-05
	/// @param[in]	eAttributes  二维显示类型
	/// @return	true-支持此类型
	//********************************************************************
	bool IsAttributesTypeSupported(EVeGfxAttributes eAttributes);

	//********************************************************************
	/// 设置二维显示类型
	/// @author	Gan Shu Long
	/// @date	2024-06-05
	/// @param[in]	eAttributes  二维显示类型
	/// 支持类型：
	/// eAttributesBasic 1 基础类型
	//********************************************************************
	void SetAttributesType(EVeGfxAttributes eAttributes);

	//********************************************************************
	/// 获得二维显示类型属性
	/// @author	Gan Shu Long
	/// @date	2024-06-05
	/// @return 二维显示类型指针
	//********************************************************************
	IVeGfxAttributes* GetAttributes() { return m_Attributes; }

	//********************************************************************
	/// 获得二维显示支持类型
	/// @author	Gan Shu Long
	/// @date	2024-06-05
	/// @return 二维显示支持类型
	//********************************************************************
	std::vector<std::string> GetAttributesSupportedTypes() { return m_AttributesSupportedTypes; }

	//********************************************************************
	/// 获得二维显示类型
	/// @author	Gan Shu Long
	/// @date	2024-06-05
	/// @return 二维显示类型
	//********************************************************************
	EVeGfxAttributes GetAttributesType();

	//********************************************************************
	/// 获得二维轨迹属性
	/// @author	Gan Shu Long
	/// @date	2024-06-05
	/// @return	二维属性指针	
	//********************************************************************
	IVeGfxOrbitPassData* GetPassData() { return m_PassData; }

	//********************************************************************
	/// 获得二维范围属性
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	/// @return	二维范围指针	
	//********************************************************************
	IGfxRangeContours* GetRangeContours() { return m_RangeContours; }

	//********************************************************************
	/// 获得地面椭圆设置集合
	/// @author	Gan Shu Long
	/// @date	2026-01-09
	/// @return	地面椭圆设置集合指针
	//********************************************************************
	IVeGfxGroundEllipsesCollection* GetGroundEllipses();

private:
	int*													m_pGfx2DType;							//C对象二维显示类型
	CGfxVeh2D*									m_pCGfxVeh2D;							//C对象二维显示指针
	std::vector<CVehEllipseSet>*		m_pVectorCVehEllipseSet;			//C对象地面椭圆设置列表指针

	std::vector<std::string>					m_AttributesSupportedTypes;	//二维显示支持类型
	IVeGfxAttributes*								m_Attributes;								//二维显示类型指针
	IVeGfxOrbitPassData*					m_PassData;								//二维轨迹指针
	IGfxRangeContours*						m_RangeContours;					//二维范围
	IVeGfxGroundEllipsesCollection*	m_GroundEllipses;						//二维地面椭圆
};



