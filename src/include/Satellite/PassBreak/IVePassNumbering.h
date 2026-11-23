#pragma once
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"

///
/// 圈数基类
///
class IATKOBJECT_API IVePassNumbering :public IClassInfo
{
public:
	IVePassNumbering(const IVePassNumbering&) = delete;
	IVePassNumbering& operator=(const IVePassNumbering&) = delete;

	IVePassNumbering();
	virtual ~IVePassNumbering();

};

