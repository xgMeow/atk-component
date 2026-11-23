#pragma once
#include <string>
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
struct CObjData;
class CGfxVectorDef;
class CGfxPoint;
struct CGfxVectorAttr;

///
/// 三维向量属性
///
class IATKOBJECT_API IVORefCrdn
{
public:
    IVORefCrdn(const IVORefCrdn&) = delete;
    IVORefCrdn& operator=(const IVORefCrdn&) = delete;

	IVORefCrdn(CGfxVectorDef* pGfxVector);
	IVORefCrdn(CGfxPoint* pGfxpoint);
	~IVORefCrdn();

	//********************************************************************
	/// 设置三维向量属性颜色
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	nColor  颜色，例绿色-65280
	//********************************************************************
	void SetColor(int nColor);
	//********************************************************************
	/// 获得三维向量属性颜色
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	颜色属性值	
	//********************************************************************
	int GetColor();

	//********************************************************************
	/// 设置三维向量属性是否显示标签
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	bLabelVisible  是否显示标签
	//********************************************************************
	void SetLabelVisible(bool bLabelVisible);
	//********************************************************************
	/// 获得三维向量属性是否显示标签
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	是否显示标签	
	//********************************************************************
	bool GetLabelVisible();

	//********************************************************************
	/// 获得三维向量属性名称
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	三维向量属性名称，例"Satellite/Satellite1 J2000 Axes"	
	//********************************************************************
	std::string GetName();

	//********************************************************************
	/// 获得三维向量属性类型ID
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	类型ID
	//********************************************************************
	EGeometricElemType GetTypeID();

	//********************************************************************
	/// 设置三维向量属性是否显示
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	bVisible  是否显示
	//********************************************************************
	void SetVisible(bool bVisible);
	//********************************************************************
	/// 获得三维向量属性是否显示
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	是否显示	
	//********************************************************************
	bool GetVisible();

	//********************************************************************
	/// 设置三维向量属性粗细
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dThickness  粗细
	//********************************************************************
	void SetThickness(double dThickness);
	//********************************************************************
	/// 获得三维向量属性粗细
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	粗细	
	//********************************************************************
	double GetThickness();

private:
	CGfxVectorDef*			            m_pCGfxVector;
	CGfxPoint*                          m_pCGfxpoint;

};
