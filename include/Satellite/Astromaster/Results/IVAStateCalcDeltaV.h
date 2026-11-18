#pragma once
#include <string>
#include "../IComponentInfo.h"
class CMCSSegment;
class CAsStateCalc;

///
/// 计算量DeltaV
///
class IATKOBJECT_API IVAStateCalcDeltaV : public IComponentInfo
{
public:
    IVAStateCalcDeltaV(const IVAStateCalcDeltaV&) = delete;
    IVAStateCalcDeltaV& operator=(const IVAStateCalcDeltaV&) = delete;

	IVAStateCalcDeltaV(CMCSSegment* pcSegment, CAsStateCalc* pcAsStateCalc);
	~IVAStateCalcDeltaV();

};
