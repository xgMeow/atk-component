#pragma once
#include "../../ICEnum.h"
#include <vector>
#include <string>
#include "IOrbitState.h"
class CObjManage;
class CSatellite;
class CSphElem;
class CPreOrbitParam;
class IFlightPathAngle;

///
/// 预报器球坐标设置
///
class IATKOBJECT_API IOrbitStateSpherical : public IOrbitState
{
public:
    IOrbitStateSpherical(const IOrbitStateSpherical&) = delete;
    IOrbitStateSpherical& operator=(const IOrbitStateSpherical&) = delete;

	IOrbitStateSpherical(CSatellite* pSate, CObjManage* IAsGObjManage, CPreOrbitParam* pPreOrbitParam);
	~IOrbitStateSpherical();

	//********************************************************************
	/// 设置方位角
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dAzi 方位角
	//********************************************************************
	void SetAzimuth(double dAzi);
	//********************************************************************
	/// 获得方位角
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	方位角
	//********************************************************************
	double GetAzimuth();

	//********************************************************************
	/// 设置赤纬
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dDec 赤纬
	//********************************************************************
	void SetDeclination(double dDec);
	//********************************************************************
	/// 获得赤纬
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	赤纬
	//********************************************************************
	double GetDeclination();

	//********************************************************************
	/// 获得航迹角属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	航迹角属性指针
	//********************************************************************
	IFlightPathAngle* GetFPA();

	//********************************************************************
	/// 设置航迹角类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eFPAType 航迹角类型
	//********************************************************************
	void SetFPAType(ESphericalFPA eFPAType);
	//********************************************************************
	/// 获得航迹角类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	航迹角类型
	//********************************************************************
	ESphericalFPA GetFPAType();

	//********************************************************************
	/// 设置半径
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dRadius 半径
	//********************************************************************
	void SetRadius(double dRadius);
	//********************************************************************
	/// 获得半径
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	半径
	//********************************************************************
	double GetRadius();

	//********************************************************************
	/// 设置赤经
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dRA 赤经
	//********************************************************************
	void SetRightAscension(double dRA);
	//********************************************************************
	/// 获得赤经
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	赤经
	//********************************************************************
	double GetRightAscension();

	//********************************************************************
	/// 设置速度
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dVel 速度
	//********************************************************************
	void SetVelocity(double dVel);
	//********************************************************************
	/// 获得速度
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	速度
	//********************************************************************
	double GetVelocity();

private:
	CObjManage*                  m_IAsGObjManage;
	CSatellite*                  m_pSate;
	CPreOrbitParam*              m_pPreOrbitParam;

	IFlightPathAngle*            m_FPA;                              //航迹角属性

	void SetSphElem(CSphElem cSE);

};
