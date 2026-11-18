#pragma once
#include <iostream>
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"
#include "../../ICEnum.h"
class CObjManage;
class CPreOrbitParam;
class CCoord3;
class CSatellite;
class CCoordAxes;
class IOrbitStateCartesian;
class IOrbitStateClassical;
class IOrbitStateSpherical;
class IOrbitStateCoordinateSystem;

#define CCoord	CCoord3

///
/// 预报器坐标设置
///
class IATKOBJECT_API IOrbitState :public IClassInfo
{
public:
    IOrbitState(const IOrbitState&) = delete;
    IOrbitState& operator=(const IOrbitState&) = delete;

	IOrbitState(CSatellite* pSate, bool bIsSubClass, CObjManage* IAsGObjManage, CPreOrbitParam* pPreOrbitParam);
	virtual ~IOrbitState();

	//********************************************************************
	/// 将新的轨道状态设置到计算库
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	pOrbitState    设置好的轨道状态
	//********************************************************************
	void Assign(IOrbitState* pOrbitState);

	//********************************************************************
	/// 使用位置速度方式设置一个新的轨道状态
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eCoordinateSystem    坐标系
	/// @param[in]	dXPosition           位置X
	/// @param[in]	dYPosition           位置Y
	/// @param[in]	dZPosition           位置Z
	/// @param[in]	dXVelocity           速度X
	/// @param[in]	dYVelocity           速度Y
	/// @param[in]	dZVelocity           速度Z
	//********************************************************************
	void AssignCartesian(ECoordinateSystem eCoordinateSystem, double dXPosition, double dYPosition, double dZPosition,
		double dXVelocity, double dYVelocity, double dZVelocity);

	//********************************************************************
	/// 使用轨道根数方式设置一个新的轨道状态
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eCoordinateSystem    坐标系
	/// @param[in]	dSemiMajorAxis       半长轴
	/// @param[in]	dEccentricity        偏心率
	/// @param[in]	dInclination         轨道倾角
	/// @param[in]	dArgOfPerigee        近拱点角距
	/// @param[in]	dRAAN                升交点赤经
	/// @param[in]	dMeanAnomaly         平近点角
	//********************************************************************
	void AssignClassical(ECoordinateSystem eCoordinateSystem, double dSemiMajorAxis, double dEccentricity, double dInclination,
		double dArgOfPerigee, double dRAAN, double dMeanAnomaly);

	//********************************************************************
	/// 使用球坐标方式设置一个新的轨道状态
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eCoordinateSystem    坐标系
	/// @param[in]	dRightAscension      赤经
	/// @param[in]	dDeclination         赤纬
	/// @param[in]	dRadius              半径
	/// @param[in]	dHorFlightPathAngle  水平航迹角
	/// @param[in]	dFlightPathAzimuth   方位角
	/// @param[in]	dVelocity            速度
	//********************************************************************
	void AssignSpherical(ECoordinateSystem eCoordinateSystem, double dRightAscension, double dDeclination, double dRadius,
		double dHorFlightPathAngle, double dFlightPathAzimuth, double dVelocity);

	//********************************************************************
	/// 修改坐标类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eConvertType    坐标类型
	/// @return	坐标属性
	//********************************************************************
	IOrbitState* ConvertTo(EOrbitStateType eConvertType);

	//********************************************************************
	/// 获得坐标类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	坐标类型
	//********************************************************************
	EOrbitStateType GetOrbitStateType();

	//********************************************************************
	/// 设置轨道历元
	/// @author	Dong Min
	/// @date	2026-01-26
	/// @param[in]	strEpoch    轨道历元(UTCG格式)
	//********************************************************************
	void SetEpoch(std::string strEpoch);

	//********************************************************************
	/// 获取轨道历元
	/// @author	Dong Min
	/// @date	2026-01-26
	/// @return	轨道历元(UTCG格式)
	//********************************************************************
	std::string GetEpoch();
	
	//********************************************************************
	/// 获得支持的坐标类型
	/// @author	Gan Shu Long
	/// @date	2026-04-23
	/// @return	支持的坐标类型
	//********************************************************************
	std::vector<std::string> GetSupportedCoordinateSystemTypes();

	//********************************************************************
	/// 判断是否支持坐标类型
	/// @author	Gan Shu Long
	/// @date	2026-04-23
	/// @return 是否支持坐标类型
	//********************************************************************
	bool IsCoordinateSystemTypeSupported(ECoordinateSystem eCSType);

	//********************************************************************
	/// 设置坐标类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eCSType 坐标类型
	//********************************************************************
	void SetCoordinateSystemType(ECoordinateSystem eCSType);

	//********************************************************************
	/// 获得坐标类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	坐标类型
	//********************************************************************
	ECoordinateSystem GetCoordinateSystemType();

	//********************************************************************
	/// 获取 中心天体名称
	/// @author	Gan Shu Long
	/// @date	2026-10-22
	/// @return	中心天体名称
	//********************************************************************
	std::string	GetCentralBodyName();

	//********************************************************************
	/// 获取 轨道坐标系统
	/// @author	Gan Shu Long
	/// @date	2026-10-21
	/// @return	轨道坐标系统
	//********************************************************************
	IOrbitStateCoordinateSystem* GetCoordinateSystem() { return m_CoordinateSystem; }

protected:
	IOrbitStateCartesian*     m_pIOrbitStateCartesian;
	IOrbitStateClassical*     m_pIOrbitStateClassical;
	IOrbitStateSpherical*     m_pIOrbitStateSpherical;
	EOrbitStateType           m_eOrbitStateType;

	void GetAxesByName(std::vector<CCoordAxes*> axesList, std::string strAxesName, CCoordAxes* &pAxes);

private:
	CObjManage*                     m_IAsGObjManage;
	CSatellite*                     m_pSate;
	CPreOrbitParam*                 m_pPreOrbitParam;
	IOrbitStateCoordinateSystem*	m_CoordinateSystem;		//轨道坐标系统

	bool SetCoord(EOrbitStateType eToType, double dValue[6]);
	int GetIntValueByCoordinateSystemType(ECoordinateSystem eCSType);
};
