#pragma once
#include "../../ICEnum.h"
#include "IVeAttitude.h"
struct CObjData;

///
/// 标准姿态
///
class IATKOBJECT_API IVeAttitudeStandard : public IVeAttitude
{
public:
    IVeAttitudeStandard(const IVeAttitudeStandard&) = delete;
    IVeAttitudeStandard& operator=(const IVeAttitudeStandard&) = delete;

	IVeAttitudeStandard(CObjData* pObjData);
	~IVeAttitudeStandard();

private:
	CObjData*           m_pObjData;

};

