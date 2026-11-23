#pragma once
#include "IVeGfxAttributes.h"
struct CGfxVeh2D;
struct CGfxVeh2DCustom;
class IVeGfxIntervalsCollection;

///
/// 二维显示自定义类型
///
class IATKOBJECT_API IVeGfxAttributesDisplayState : public IVeGfxAttributes
{
public:
    IVeGfxAttributesDisplayState(const IVeGfxAttributesDisplayState&) = delete;
    IVeGfxAttributesDisplayState& operator=(const IVeGfxAttributesDisplayState&) = delete;

	IVeGfxAttributesDisplayState(CGfxVeh2D* pCGfxVeh2D, std::vector<CGfxVeh2DCustom>* pCGfxVeh2DCustoms);
	virtual ~IVeGfxAttributesDisplayState();

	//********************************************************************
	/// 获得二维显示自定义类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	二维显示自定义类型
	//********************************************************************
	IVeGfxIntervalsCollection* GetDisplayIntervals();

private:
	std::vector<CGfxVeh2DCustom>*    m_pCGfxVeh2DCustoms;

	IVeGfxIntervalsCollection*		m_DisplayIntervals;		//二维显示自定义类型
};

