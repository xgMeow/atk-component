#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
class CSatellite;
class IOrientationAscNode;

///
/// 轨道根数方向参数
///
class IATKOBJECT_API IClassicalOrientation
{
public:
    IClassicalOrientation(const IClassicalOrientation&) = delete;
    IClassicalOrientation& operator=(const IClassicalOrientation&) = delete;

	IClassicalOrientation(CSatellite* pSate);
	~IClassicalOrientation();

	//********************************************************************
	/// 获得升交点赤经或升交点经度属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	升交点赤经或升交点经度属性
	//********************************************************************
	IOrientationAscNode* GetAscNode();

	//********************************************************************
	/// 设置升交点类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eOAN 升交点类型
	//********************************************************************
	void SetAscNodeType(EOrientationAscNode eOAN);
	//********************************************************************
	/// 获得升交点类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	升交点类型
	//********************************************************************
	EOrientationAscNode GetAscNodeType();

	//********************************************************************
	/// 设置轨道倾角
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dInclination 轨道倾角
	//********************************************************************
	void SetInclination(double dInclination);
	//********************************************************************
	/// 获得轨道倾角
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	轨道倾角
	//********************************************************************
	double GetInclination();

	//********************************************************************
	/// 设置近拱点角距
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dArgOfPerigee 近拱点角距
	//********************************************************************
	void SetArgOfPerigee(double dArgOfPerigee);
	//********************************************************************
	/// 获得近拱点角距
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	近拱点角距
	//********************************************************************
	double GetArgOfPerigee();


private:
	CSatellite*              m_pSate;

	IOrientationAscNode*     m_AscNode;        ///<升交点赤经或升交点经度属性
	
};
