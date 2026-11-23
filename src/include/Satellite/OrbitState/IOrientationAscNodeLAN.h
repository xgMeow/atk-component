#pragma once
#include "IOrientationAscNode.h"
class CSatellite;

///
/// 轨道根数LAN
///
class IATKOBJECT_API IOrientationAscNodeLAN : public IOrientationAscNode
{
public:
    IOrientationAscNodeLAN(const IOrientationAscNodeLAN&) = delete;
    IOrientationAscNodeLAN& operator=(const IOrientationAscNodeLAN&) = delete;

	IOrientationAscNodeLAN(CSatellite* pSate);
	~IOrientationAscNodeLAN();

	//********************************************************************
	/// 设置LAN
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dLAN 
	//********************************************************************
	void SetValue(double dLAN);
	//********************************************************************
	/// 获得LAN
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	LAN
	//********************************************************************
	double GetValue();

private:
	CSatellite* m_pSate;

};

