#pragma once
#include "../IAtkObj.h" 
#include "../IClassInfo.h" 
struct AsCvFmDefn;

///
/// 品质因子定义数据
///
class IATKOBJECT_API IFmDefinitionData :public IClassInfo
{
public:
    IFmDefinitionData(const IFmDefinitionData&) = delete;
    IFmDefinitionData& operator=(const IFmDefinitionData&) = delete;

	IFmDefinitionData(AsCvFmDefn* pAsCvFmDefn);
	~IFmDefinitionData();

protected:
	AsCvFmDefn*			m_pAsCvFmDefn;
};
