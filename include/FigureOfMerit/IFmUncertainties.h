#pragma once
#include "../IAtkObj.h" 
struct AsCvFmDefn;

///
/// 不确定度
///
class IATKOBJECT_API IFmUncertainties
{
public:
    IFmUncertainties(const IFmUncertainties&) = delete;
    IFmUncertainties& operator=(const IFmUncertainties&) = delete;

	IFmUncertainties(AsCvFmDefn* pAsCvFmDefn);
	~IFmUncertainties();

	//todo 功能未完成，等鲁轩通知

protected:
	AsCvFmDefn*			m_pAsCvFmDefn;
};
