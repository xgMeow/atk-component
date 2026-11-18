#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
class CChain;
class IChGfxStatic;
class IChGfxAnimation;

///
/// 二维
///
class IATKOBJECT_API IChGraphics
{
public:
    IChGraphics(const IChGraphics&) = delete;
    IChGraphics& operator=(const IChGraphics&) = delete;

	IChGraphics(CChain* pCChain);
	~IChGraphics();

	//********************************************************************
	/// 设置对象是否在二维显示
	/// @author	Gan Shu Long
	/// @date	2024-06-12
	/// @param[in]	bIsObjectGraphicsVisible  是否显示
	//********************************************************************
	void SetIsObjectGraphicsVisible(bool bIsObjectGraphicsVisible);

	//********************************************************************
	/// 获得对象是否在二维显示
	/// @author	Gan Shu Long
	/// @date	2024-06-12
	/// @return	true-显示
	//********************************************************************
	bool GetIsObjectGraphicsVisible();

	//********************************************************************
	/// 获得静态可视化属性
	/// @author	Gan Shu Long
	/// @date	2026-01-12
	/// @return	静态可视化属性指针	
	//********************************************************************
	IChGfxStatic* GetStatic() { return m_Static; }

	//********************************************************************
	/// 获得动态可视化属性
	/// @author	Gan Shu Long
	/// @date	2026-01-12
	/// @return	动态可视化属性指针	
	//********************************************************************
	IChGfxAnimation* GetAnimation() { return m_Animation; }

private:
	CChain*						m_pCChain;		//C对象指针

	IChGfxStatic*				m_Static;				//静态可视化属性指针
	IChGfxAnimation*		m_Animation;		//动态可视化属性指针
};

