#pragma once
#include "../IAtkObj.h" 
#include "../IClassInfo.h" 
struct AsCvFmDefn;
class IFmSatisfaction;

///
/// 品质因子定义
///
class IATKOBJECT_API IFmDefinition :public IClassInfo
{
public:
    IFmDefinition(const IFmDefinition&) = delete;
    IFmDefinition& operator=(const IFmDefinition&) = delete;

	IFmDefinition(AsCvFmDefn* pAsCvFmDefn);
	~IFmDefinition();

	//********************************************************************
	/// 获得  有效条件
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @return	 定义
	//*******************************************************
	IFmSatisfaction* GetSatisfaction() { return m_Satisfaction; }

protected:
	AsCvFmDefn*			m_pAsCvFmDefn;

private:
	IFmSatisfaction*		m_Satisfaction;
};
