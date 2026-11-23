#pragma once
#include "IOrientationAscNode.h"
class CSatellite;

///
/// 轨道根数升交点赤经
///
class IATKOBJECT_API IOrientationAscNodeRAAN : public IOrientationAscNode
{ 
public:
    IOrientationAscNodeRAAN(const IOrientationAscNodeRAAN&) = delete;
    IOrientationAscNodeRAAN& operator=(const IOrientationAscNodeRAAN&) = delete;

	IOrientationAscNodeRAAN(CSatellite* pSate);
	~IOrientationAscNodeRAAN();

	//********************************************************************
	/// 设置升交点赤经
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dRAAN 升交点赤经
	//********************************************************************
	void SetValue(double dRAAN);
	//********************************************************************
	/// 获得升交点赤经
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	升交点赤经
	//********************************************************************
	double GetValue();

private:
	CSatellite* m_pSate;

};
