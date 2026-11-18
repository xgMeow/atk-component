#pragma once
#include "IVeAttitudeStandard.h"
struct CObjData;
class IVeStandardBasic;

///
/// 标准姿态类型
///
class IATKOBJECT_API IVeOrbitAttitudeStandard : public IVeAttitudeStandard
{
public:
    IVeOrbitAttitudeStandard(const IVeOrbitAttitudeStandard&) = delete;
    IVeOrbitAttitudeStandard& operator=(const IVeOrbitAttitudeStandard&) = delete;

	IVeOrbitAttitudeStandard(CObjData* pObjData);
	~IVeOrbitAttitudeStandard();

	//********************************************************************
	/// 获得姿态类型属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	姿态类型指针
	//********************************************************************
	 IVeStandardBasic* GetBasic();

private:
	CObjData*					m_pObjData;
	IVeStandardBasic*		m_Basic;   //得到姿态类型属性
};


