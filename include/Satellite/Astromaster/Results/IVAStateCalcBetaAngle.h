#pragma once
#include <string>
#include "../IComponentInfo.h"
class CMCSSegment;
class CAsStateCalc;

///
/// 计算量BetaAngle
///
class IATKOBJECT_API IVAStateCalcBetaAngle : public IComponentInfo
{
public:
    IVAStateCalcBetaAngle(const IVAStateCalcBetaAngle&) = delete;
    IVAStateCalcBetaAngle& operator=(const IVAStateCalcBetaAngle&) = delete;

	IVAStateCalcBetaAngle(CMCSSegment* pcSegment, CAsStateCalc* pcAsStateCalc);
	~IVAStateCalcBetaAngle();

};
