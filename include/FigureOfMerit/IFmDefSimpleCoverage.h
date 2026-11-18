#pragma once
#include "../IAtkObj.h"
#include "IFmDefinition.h" 

///
/// 品质因子定义：简单覆盖
///
class IATKOBJECT_API IFmDefSimpleCoverage :public IFmDefinition
{
public:
    IFmDefSimpleCoverage(const IFmDefSimpleCoverage&) = delete;
    IFmDefSimpleCoverage& operator=(const IFmDefSimpleCoverage&) = delete;

	IFmDefSimpleCoverage(AsCvFmDefn* pAsCvFmDefn);
	~IFmDefSimpleCoverage();
};
