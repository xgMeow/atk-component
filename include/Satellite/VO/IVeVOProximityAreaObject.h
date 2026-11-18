#pragma once
#include <string>
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"
#include "../../ICEnum.h"
struct CObjData;
struct CGfxControlBox;

///
/// 三维抵近
///
class IATKOBJECT_API IVeVOProximityAreaObject :public IClassInfo
{
public:
    IVeVOProximityAreaObject(const IVeVOProximityAreaObject&) = delete;
    IVeVOProximityAreaObject& operator=(const IVeVOProximityAreaObject&) = delete;

	IVeVOProximityAreaObject(CGfxControlBox* pCGfxControlBox);
	virtual ~IVeVOProximityAreaObject();

	//********************************************************************
	/// 设置三维抵近颜色
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	nColor  颜色
	//********************************************************************
	void SetColor(int nColor);
	//********************************************************************
	/// 获得三维抵近颜色
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	颜色
	//********************************************************************
	int GetColor();

	//********************************************************************
	/// 设置三维抵近是否显示文字
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	bIsTextVisible  是否显示文字
	//********************************************************************
	void SetIsTextVisible(bool bIsTextVisible);
	//********************************************************************
	/// 获得三维抵近是否显示文字
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	是否显示文字	
	//********************************************************************
	bool GetIsTextVisible();

	//********************************************************************
	/// 设置三维抵近是否显示
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	bIsVisible  是否显示
	//********************************************************************
	void SetIsVisible(bool bIsVisible);
	//********************************************************************
	/// 获得三维抵近是否显示
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	是否显示	
	//********************************************************************
	bool GetIsVisible();

	//********************************************************************
	/// 设置三维抵近线型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eLineStyle  线型
	//********************************************************************
	void SetLineStyle(ELineStyle eLineStyle);
	//********************************************************************
	/// 获得三维抵近线型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	线型	
	//********************************************************************
	ELineStyle GetLineStyle();

	//********************************************************************
	/// 设置三维抵近线宽
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eLineWidth  线宽
	//********************************************************************
	void SetLineWidth(ELineWidth eLineWidth);
	//********************************************************************
	/// 获得三维抵近线宽
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	线宽	
	//********************************************************************
	ELineWidth GetLineWidth();

	//********************************************************************
	/// 设置三维抵近文字
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	strText  文字
	//********************************************************************
	void SetText(std::string strText);
	//********************************************************************
	/// 获得三维抵近文字
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	文字	
	//********************************************************************
	std::string GetText();

private:
	CGfxControlBox*              m_pCGfxControlBox;			//C对象控制盒指针
};

