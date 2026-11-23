#pragma once
#include "../../../IAtkObj.h"
#include "../../../IClassInfo.h"
class CObjManage;
class CMCSSegment;
class CMCSManeuver;
class IVAMCSSegment;
class IVAMCSManeuver;
class IVAAttitudeControl;

///
/// 机动段机动类型
///
class IATKOBJECT_API IVAManeuver :public IClassInfo
{
public:
    IVAManeuver(const IVAManeuver&) = delete;
    IVAManeuver& operator=(const IVAManeuver&) = delete;

	IVAManeuver(CMCSSegment* pcSegment, IVAMCSSegment* pIVAMCSSegment, CObjManage* IAsGObjManage);
	virtual ~IVAManeuver();

	IVAAttitudeControl* GetAttitudeControl();

	//********************************************************************
	/// 设置比冲
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dIsp 比冲
	/// @Return	
	//********************************************************************
	void SetIsp(double dIsp);

	//********************************************************************
	/// 获得比冲
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	比冲
	//********************************************************************
	double GetIsp();

	//********************************************************************
	/// 设置是否根据推进剂消耗更新质量
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	bIsUpdateMass true-根据推进剂消耗更新质量
	/// @Return	
	//********************************************************************
	void SetIsUpdateMass(bool bIsUpdateMass);
	//********************************************************************
	/// 获得是否根据推进剂消耗更新质量
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	true-根据推进剂消耗更新质量
	//********************************************************************
	bool GetIsUpdateMass();

private:
	CObjManage*					m_IAsGObjManage;
	CMCSManeuver*				m_pcManeuver;
	IVAMCSManeuver*				m_pIVAMCSManeuver;
	IVAAttitudeControl*			m_AttitudeControl;
};
