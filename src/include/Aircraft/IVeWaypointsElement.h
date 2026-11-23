#pragma once
#include "../IAtkObj.h"
struct CWayPt;

///
/// 路径点
///
class IATKOBJECT_API IVeWaypointsElement
{
public:
    IVeWaypointsElement(const IVeWaypointsElement&) = delete;
    IVeWaypointsElement& operator=(const IVeWaypointsElement&) = delete;

	IVeWaypointsElement(CWayPt* pCWayPt);
	~IVeWaypointsElement();

	//********************************************************************
	/// 设置 加速度
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @param[in]	acceleration 新值
	//********************************************************************
	void SetAcceleration(double acceleration);

	//********************************************************************
	/// 设置 高度
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @param[in]	altitude 新值
	//********************************************************************
	void SetAltitude(double altitude);

	//********************************************************************
	/// 设置 纬度
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @param[in]	latitude 新值
	//********************************************************************
	void SetLatitude(double latitude);

	//********************************************************************
	/// 设置 经度
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @param[in]	longitude 新值
	//********************************************************************
	void SetLongitude(double longitude);

	//********************************************************************
	/// 设置 速度
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @param[in]	speed 新值
	//********************************************************************
	void SetSpeed(double speed);

	//********************************************************************
	/// 设置 时间
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @param[in]	time 新值
	//********************************************************************
	void SetTime(double time);

	//********************************************************************
	/// 设置 曲率
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @param[in]	turnRadius 新值
	//********************************************************************
	void SetTurnRadius(double turnRadius);

	double GetAcceleration();		//加速度
	double GetAltitude();				//高度
	double GetLatitude();			//纬度
	double GetLongitude();			//经度
	double GetSpeed();				//速度
	double GetTime();					//时间 以秒为单位，表示和想定开始时间的间隔
	double GetTurnRadius();		//转角弧的曲率

private:
	CWayPt*			m_CWayPt;	
};
