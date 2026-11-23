#pragma once
#include "IVAAttitudeControl.h"

///
/// 机动段姿态控制有限推力
///
class IATKOBJECT_API IVAAttitudeControlFinite : public IVAAttitudeControl
{
public:
    IVAAttitudeControlFinite(const IVAAttitudeControlFinite&) = delete;
    IVAAttitudeControlFinite& operator=(const IVAAttitudeControlFinite&) = delete;

	IVAAttitudeControlFinite();
	~IVAAttitudeControlFinite();

};
