#pragma once
#include <vector>
#include <string>
#include "IOrbitState.h"
class CObjManage;
class CSatellite;
class CPreOrbitParam;

///
/// 预报器位置速度设置
///
class IATKOBJECT_API IOrbitStateCartesian : public IOrbitState
{
public:
    IOrbitStateCartesian(const IOrbitStateCartesian&) = delete;
    IOrbitStateCartesian& operator=(const IOrbitStateCartesian&) = delete;

	IOrbitStateCartesian(CSatellite* pSate, CObjManage* IAsGObjManage, CPreOrbitParam* pPreOrbitParam);
	~IOrbitStateCartesian();

	//********************************************************************
	/// 设置位置X
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dXPos 位置X
	//********************************************************************
	void SetXPosition(double dXPos);
	//********************************************************************
	/// 获得位置X
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	位置X
	//********************************************************************
	double GetXPosition();

	//********************************************************************
	/// 设置速度X
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dXVel 速度X
	//********************************************************************
	void SetXVelocity(double dXVel);
	//********************************************************************
	/// 获得速度X
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	速度X
	//********************************************************************
	double GetXVelocity();

	//********************************************************************
	/// 设置位置Y
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dYPos 位置Y
	//********************************************************************
	void SetYPosition(double dYPos);
	//********************************************************************
	/// 获得位置Y
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	位置Y
	//********************************************************************
	double GetYPosition();

	//********************************************************************
	/// 设置速度Y
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dYVel 速度Y
	//********************************************************************
	void SetYVelocity(double dYVel);
	//********************************************************************
	/// 获得速度Y
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	速度Y
	//********************************************************************
	double GetYVelocity();

	//********************************************************************
	/// 设置位置Z
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dZPos 位置Z
	//********************************************************************
	void SetZPosition(double dZPos);
	//********************************************************************
	/// 获得位置Z
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	位置Z
	//********************************************************************
	double GetZPosition();

	//********************************************************************
	/// 设置速度Z
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dZVel 速度Z
	//********************************************************************
	void SetZVelocity(double dZVel);
	//********************************************************************
	/// 获得速度Z
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	速度Z
	//********************************************************************
	double GetZVelocity();

private:
	CSatellite*                     m_pSate;
	CPreOrbitParam*                 m_pPreOrbitParam;

};
