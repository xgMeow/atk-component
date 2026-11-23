#pragma once
#include "../IAtkObj.h"
#include "IFmDefinition.h" 

///
/// 品质因子定义：时间平均间隔
///
class IATKOBJECT_API IFmDefTimeAverageGap :public IFmDefinition
{
public:
    IFmDefTimeAverageGap(const IFmDefTimeAverageGap&) = delete;
    IFmDefTimeAverageGap& operator=(const IFmDefTimeAverageGap&) = delete;

	IFmDefTimeAverageGap(AsCvFmDefn* pAsCvFmDefn);
	~IFmDefTimeAverageGap();
};
