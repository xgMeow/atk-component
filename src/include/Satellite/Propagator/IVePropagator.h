#pragma once
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"

///
/// 预报器
///
class IATKOBJECT_API IVePropagator :public IClassInfo
{
public:
    IVePropagator(const IVePropagator&) = delete;
    IVePropagator& operator=(const IVePropagator&) = delete;

	IVePropagator();
	virtual ~IVePropagator();

};
