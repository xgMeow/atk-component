#pragma once
#include "IVAAttitudeControl.h"

///
/// 机动段姿态控制脉冲
///
class IATKOBJECT_API IVAAttitudeControlImpulsive : public IVAAttitudeControl
{
public:
    IVAAttitudeControlImpulsive(const IVAAttitudeControlImpulsive&) = delete;
    IVAAttitudeControlImpulsive& operator=(const IVAAttitudeControlImpulsive&) = delete;

	IVAAttitudeControlImpulsive();
	~IVAAttitudeControlImpulsive();

};
