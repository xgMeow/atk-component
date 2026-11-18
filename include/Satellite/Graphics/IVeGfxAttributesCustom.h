#pragma once
#include "IVeGfxAttributesDisplayState.h"
struct CGfxVeh2D;
struct CGfxVeh2DCustom;
class IVeGfxAttributesBasic;
class IVeGfxIntervalsCollection;

///
/// 二维显示属性
///
class IATKOBJECT_API IVeGfxAttributesCustom : public IVeGfxAttributesDisplayState
{
public:
    IVeGfxAttributesCustom(const IVeGfxAttributesCustom&) = delete;
    IVeGfxAttributesCustom& operator=(const IVeGfxAttributesCustom&) = delete;

	IVeGfxAttributesCustom(CGfxVeh2D* pCGfxVeh2D, std::vector<CGfxVeh2DCustom>* pCGfxVeh2DCustoms);
	~IVeGfxAttributesCustom();

	//********************************************************************
	/// 获得二维显示属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	二维显示属性指针
	//********************************************************************
	IVeGfxAttributesBasic* GetDefault();

	//********************************************************************
	/// 获得二维自定义显示属性集合
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	二维自定义显示属性集合指针
	//********************************************************************
	IVeGfxIntervalsCollection* GetIntervals();

private:
	CGfxVeh2D*                     m_pCGfxVeh2D; 
	std::vector<CGfxVeh2DCustom>*   m_pCGfxVeh2DCustoms;

	IVeGfxAttributesBasic*         m_Default;     //二维显示属性
	IVeGfxIntervalsCollection*     m_Intervals;   //二维自定义显示属性集合

};
