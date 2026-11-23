#pragma once
#include "IClassicalSizeShape.h"
class CSatellite;

///
/// 轨道根数远拱点高度和近拱点高度
///
class IATKOBJECT_API IClassicalSizeShapeAltitude : public IClassicalSizeShape
{
public:
    IClassicalSizeShapeAltitude(const IClassicalSizeShapeAltitude&) = delete;
    IClassicalSizeShapeAltitude& operator=(const IClassicalSizeShapeAltitude&) = delete;

	IClassicalSizeShapeAltitude(CSatellite* pSate);
	~IClassicalSizeShapeAltitude();

	//********************************************************************
	/// 设置远拱点高度
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dApoAlt 远拱点高度
	//********************************************************************
	void SetApogeeAltitude(double dApoAlt);
	//********************************************************************
	/// 获得远拱点高度
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	远拱点高度
	//********************************************************************
	double GetApogeeAltitude();

	//********************************************************************
	/// 设置近拱点高度
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dPerAlt 近拱点高度
	//********************************************************************
	void SetPerigeeAltitude(double dPerAlt);
	//********************************************************************
	/// 获得近拱点高度
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	近拱点高度
	//********************************************************************
	double GetPerigeeAltitude();

private:
	CSatellite*     m_pSate;

};
