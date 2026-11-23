#pragma once
#include "../IAtkObj.h"
#include "IFmDefinition.h" 
class IFmDefDataMinMax;

///
/// 品质因子定义：访问间隔
///
class IATKOBJECT_API IFmDefAccessSeparation :public IFmDefinition
{
public:
    IFmDefAccessSeparation(const IFmDefAccessSeparation&) = delete;
    IFmDefAccessSeparation& operator=(const IFmDefAccessSeparation&) = delete;

	IFmDefAccessSeparation(AsCvFmDefn* pAsCvFmDefn);
	~IFmDefAccessSeparation();

	//********************************************************************
	/// 获得  最大值最小值
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @return	 最大值最小值
	//*******************************************************
	IFmDefDataMinMax* GetCompute() { return m_MinMaxData; }

private:
	IFmDefDataMinMax*					m_MinMaxData;
};
