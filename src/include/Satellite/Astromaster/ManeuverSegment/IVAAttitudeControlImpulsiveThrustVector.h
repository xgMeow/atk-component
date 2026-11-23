#pragma once 
#include "IVAAttitudeControlImpulsive.h"
#include "../../../ICEnum.h"
class CMCSManeuver;
class IVAMCSManeuver;

///
/// 机动段姿态控制脉冲矢量
///
class IATKOBJECT_API IVAAttitudeControlImpulsiveThrustVector : public IVAAttitudeControlImpulsive
{
public:
    IVAAttitudeControlImpulsiveThrustVector(const IVAAttitudeControlImpulsiveThrustVector&) = delete;
    IVAAttitudeControlImpulsiveThrustVector& operator=(const IVAAttitudeControlImpulsiveThrustVector&) = delete;

	IVAAttitudeControlImpulsiveThrustVector(CMCSManeuver* pManeuver, IVAMCSManeuver* pIVAMCSManeuver);
	~IVAAttitudeControlImpulsiveThrustVector();

	//********************************************************************
	/// 设置直角坐标
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dXVal  速度增量Vx
	/// @Param	dYVal  速度增量Vy
	/// @Param	dZVal  速度增量Vz 
	/// @Return	
	//********************************************************************
	void AssignCartesian(double dXVal,double dYVal,double dZVal);

	//********************************************************************
	/// 设置球坐标
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dAzVal   方位角 
	/// @Param	dElVal   仰角 
	/// @Param	dMagVal  大小
	/// @Return	
	//********************************************************************
	void AssignSpherical(double dAzVal, double dElVal, double dMagVal);

	//********************************************************************
	/// 获得直角坐标值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	 
	/// @Return	[速度增量Vx、速度增量Vy、速度增量Vy]
	//********************************************************************
	std::vector<double> QueryCartesian();

	//********************************************************************
	/// 获得球坐标值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	  
	/// @Return	[方位角、仰角、大小]
	//********************************************************************
	std::vector<double> QuerySpherical();

	//********************************************************************
	/// 设置推力坐标轴
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strThrustAxesName 推理坐标轴名称，例:"Satellite/Satellite1 J2000","CentralBody/Earth J2000"
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

	//********************************************************************
	/// 设置坐标类型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eCoordType 坐标类型
	/// @Return	
	//********************************************************************
	void SetCoordType(EVAImpDeltaVRep eCoordType);
	//********************************************************************
	/// 获得坐标类型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	坐标类型
	//********************************************************************
	EVAImpDeltaVRep GetCoordType();

	//********************************************************************
	/// 设置方位角
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dAzi 方位角
	/// @Return	
	//********************************************************************
	void SetAzimuth(double dAzi);
	//********************************************************************
	/// 获得方位角
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	方位角
	//********************************************************************
	double GetAzimuth();

	//********************************************************************
	/// 设置仰角
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dElev 仰角
	/// @Return	
	//********************************************************************
	void SetElevation(double dElev);
	//********************************************************************
	/// 获得仰角
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	仰角
	//********************************************************************
	double GetElevation();

	//********************************************************************
	/// 设置球坐标大小
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dMagnitude 球坐标大小
	/// @Return	
	//********************************************************************
	void SetMagnitude(double dMagnitude);
	//********************************************************************
	/// 获得球坐标大小
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	球坐标大小
	//********************************************************************
	double GetMagnitude();

	//********************************************************************
	/// 设置速度增量Vx
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dX 速度增量Vx
	/// @Return	
	//********************************************************************
	void SetX(double dX);
	//********************************************************************
	/// 获得速度增量Vx
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	速度增量Vx
	//********************************************************************
	double GetX();

	//********************************************************************
	/// 设置速度增量Vy
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dY 速度增量Vy
	/// @Return	
	//********************************************************************
	void SetY(double dY);
	//********************************************************************
	/// 获得速度增量Vy
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	速度增量Vy
	//********************************************************************
	double GetY();

	//********************************************************************
	/// 设置速度增量Vz
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dZ 速度增量Vz
	/// @Return	
	//********************************************************************
	void SetZ(double dZ);
	//********************************************************************
	/// 获得速度增量Vz
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	速度增量Vz
	//********************************************************************
	double GetZ();

private:
	CMCSManeuver*         m_pcManeuver;
	IVAMCSManeuver*       m_pIVAMCSManeuver;

};

