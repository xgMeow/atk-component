#pragma once
#include "../IAtkObj.h"
#include "../IClassInfo.h"

///
/// 网格区域
///
class IATKOBJECT_API ICvBounds :public IClassInfo
{
public:
    ICvBounds(const ICvBounds&) = delete;
    ICvBounds& operator=(const ICvBounds&) = delete;

	ICvBounds();
	virtual ~ICvBounds();
};
