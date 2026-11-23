#pragma once
#include "IVAAttitudeControlFinite.h"
class CMCSManeuver;
class IVAMCSManeuver;
class IDirection;

///
/// 机动段姿态控制有限推力矢量
///
class IATKOBJECT_API IVAAttitudeControlFiniteThrustVector : public IVAAttitudeControlFinite
{
public:
    IVAAttitudeControlFiniteThrustVector(const IVAAttitudeControlFiniteThrustVector&) = delete;
    IVAAttitudeControlFiniteThrustVector& operator=(const IVAAttitudeControlFiniteThrustVector&) = delete;

	IVAAttitudeControlFiniteThrustVector(CMCSManeuver* pManeuver, IVAMCSManeuver* pIVAMCSManeuve);
	~IVAAttitudeControlFiniteThrustVector();

	IDirection* GetThrustVector();

	//********************************************************************
	/// 设置推力坐标轴
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strThrustAxesName 推理坐标轴名称，例:"Satellite/Satellite1 J2000"
	/// @Return	
	//********************************************************************
	void SetThrustAxesName(std::string strThrustAxesName);
	//********************************************************************
	/// 获得推力坐标轴
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	推理坐标轴名称
	//********************************************************************
	std::string GetThrustAxesName();

private:
	CMCSManeuver*                 m_pcManeuver;
	IVAMCSManeuver*               m_pIVAMCSManeuve;

	IDirection*                   m_ThrustVector;        //坐标类型

};
