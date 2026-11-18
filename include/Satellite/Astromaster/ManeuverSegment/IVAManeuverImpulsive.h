#pragma once
#include "IVAManeuver.h"
class CObjManage;
class CMCSManeuver;
class IVAMCSManeuver;

///
/// 机动段脉冲
///
class IATKOBJECT_API IVAManeuverImpulsive : public IVAManeuver
{
public:
    IVAManeuverImpulsive(const IVAManeuverImpulsive&) = delete;
    IVAManeuverImpulsive& operator=(const IVAManeuverImpulsive&) = delete;

	IVAManeuverImpulsive(CMCSManeuver* pManeuver, IVAMCSManeuver* pIVAMCSManeuve, CObjManage* IAsGObjManage);
	~IVAManeuverImpulsive();

	//********************************************************************
	/// 设置是否根据推进剂消耗更新质量
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	bUpdateMass true-根据推进剂消耗更新质量
	/// @Return	
	//********************************************************************
	void SetUpdateMass(bool bUpdateMass);
	//********************************************************************
	/// 获得是否根据推进剂消耗更新质量
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	
	//********************************************************************
	bool GetUpdateMass();

private:
	CMCSManeuver*     m_pcManeuver;

};
