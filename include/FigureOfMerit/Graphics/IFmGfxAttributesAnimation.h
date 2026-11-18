#pragma once
#include "../../IAtkObj.h"
#include "IFmGfxAttributes.h"
struct GfxFOMGraphics;

///
/// 二维视图 动态
///
class IATKOBJECT_API IFmGfxAttributesAnimation :public IFmGfxAttributes
{
public:
    IFmGfxAttributesAnimation(const IFmGfxAttributesAnimation&) = delete;
    IFmGfxAttributesAnimation& operator=(const IFmGfxAttributesAnimation&) = delete;

	IFmGfxAttributesAnimation(GfxFOMGraphics* pGfxFOMGraphics);
	~IFmGfxAttributesAnimation();
	
private:
	GfxFOMGraphics*							m_pGfxFOMGraphics;
};

