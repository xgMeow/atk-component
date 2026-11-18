#pragma once
#include "../IAtkObj.h"
#include "ICvBounds.h"
class CCoverageDefinition;

///
/// 全球范围
///
class IATKOBJECT_API ICvBoundsGlobal :public ICvBounds
{
public:
    ICvBoundsGlobal(const ICvBoundsGlobal&) = delete;
    ICvBoundsGlobal& operator=(const ICvBoundsGlobal&) = delete;

	ICvBoundsGlobal(CCoverageDefinition* pCCoverageDefinition);
	~ICvBoundsGlobal();
};
