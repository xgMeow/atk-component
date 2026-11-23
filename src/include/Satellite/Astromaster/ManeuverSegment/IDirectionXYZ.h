#pragma once
#include "IDirection.h"
class CMCSManeuver;
class IVAMCSManeuver;

///
/// 机动段球坐标
///
class IATKOBJECT_API IDirectionXYZ : public IDirection
{
public:
    IDirectionXYZ(const IDirectionXYZ&) = delete;
    IDirectionXYZ& operator=(const IDirectionXYZ&) = delete;

	IDirectionXYZ(CMCSManeuver* pManeuver, IVAMCSManeuver* pIVAMCSManeuver);
	~IDirectionXYZ();

	//********************************************************************
	/// 设置速度增量Vx
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dX 速度增量Vx，默认单位m/sec
	/// @Return	
	//********************************************************************
	void SetX(double dX);
	//********************************************************************
	/// 获得速度增量Vx
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	速度增量Vx，默认单位m/sec
	//********************************************************************
	double GetX();

	//********************************************************************
	/// 设置速度增量Vy
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dY 速度增量Vy，默认单位m/sec
	/// @Return	
	//********************************************************************
	void SetY(double dY);
	//********************************************************************
	/// 获得速度增量Vy
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	速度增量Vy，默认单位m/sec
	//********************************************************************
	double GetY();

	//********************************************************************
	/// 设置速度增量Vz
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dZ 速度增量Vz，默认单位m/sec
	/// @Return	
	//********************************************************************
	void SetZ(double dZ);
	//********************************************************************
	/// 获得速度增量Vz
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	速度增量Vz，默认单位m/sec
	//********************************************************************
	double GetZ();

private:
	CMCSManeuver*     m_pcManeuver;

};
