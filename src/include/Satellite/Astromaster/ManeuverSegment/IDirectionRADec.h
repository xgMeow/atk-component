#pragma once
#include "IDirection.h"
class CMCSManeuver;
class IVAMCSManeuver;

///
/// 机动段球坐标
///
class IATKOBJECT_API IDirectionRADec : public IDirection
{
public:
    IDirectionRADec(const IDirectionRADec&) = delete;
    IDirectionRADec& operator=(const IDirectionRADec&) = delete;

	IDirectionRADec(CMCSManeuver* pManeuver, IVAMCSManeuver* pIVAMCSManeuver);
	~IDirectionRADec();

	//********************************************************************
	/// 设置球坐标仰角
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dDec 仰角，默认单位deg
	/// @Return	
	//********************************************************************
	void SetDec(double dDec);
	//********************************************************************
	/// 获得球坐标仰角
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	仰角，默认单位deg
	//********************************************************************
	double GetDec();

	//********************************************************************
	/// 设置球坐标方位角
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dRA 方位角，默认单位deg
	/// @Return	
	//********************************************************************
	void SetRA(double dRA);
	//********************************************************************
	/// 获得球坐标方位角
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	方位角，默认单位deg
	//********************************************************************
	double GetRA();

private:
	CMCSManeuver*     m_pcManeuver;

};
