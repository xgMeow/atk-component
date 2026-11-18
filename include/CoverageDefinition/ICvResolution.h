#pragma once
#include "../IAtkObj.h"
#include "../ICObjectFunction.h"
#include "../IClassInfo.h"
#include "../ICEnum.h"

///
/// 网格定义
///
class IATKOBJECT_API ICvResolution :public IClassInfo
{
public:
    ICvResolution(const ICvResolution&) = delete;
    ICvResolution& operator=(const ICvResolution&) = delete;

	ICvResolution();
	virtual ~ICvResolution();

protected:
	//网络分辨率类型值转换
	double GridResolutionTypeValueConvert(ECvResolution oldResolutionType, const double oldValue, ECvResolution newResolutionType);
};
