#pragma once
#include "../../ICEnum.h"
#include "IClassicalSizeShape.h"
class CSatellite;

///
/// 轨道根数远拱点半径和近拱点半径
///
class IATKOBJECT_API IClassicalSizeShapeRadius : public IClassicalSizeShape
{
public:
    IClassicalSizeShapeRadius(const IClassicalSizeShapeRadius&) = delete;
    IClassicalSizeShapeRadius& operator=(const IClassicalSizeShapeRadius&) = delete;

	IClassicalSizeShapeRadius(CSatellite* pSate);
	~IClassicalSizeShapeRadius();

	//********************************************************************
	/// 设置轨道根数方式半径属性值
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dApogeeRadius    远拱点半径
	/// @param[in]	dPerigeeRadius   近拱点半径
	//********************************************************************
	void SetSizeShapeRadius(double dApogeeRadius, double dPerigeeRadius);

	//********************************************************************
	/// 设置远拱点半径
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dApoRad 远拱点半径
	//********************************************************************
	void SetApogeeRadius(double dApoRad);
	//********************************************************************
	/// 获得远拱点半径
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	远拱点半径
	//********************************************************************
	double GetApogeeRadius();

	//********************************************************************
	/// 设置近拱点半径
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dPeriRad 近拱点半径
	//********************************************************************
	void SetPerigeeRadius(double dPeriRad);
	//********************************************************************
	/// 获得近拱点半径
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	近拱点半径
	//********************************************************************
	double GetPerigeeRadius();

private:
	CSatellite* m_pSate;

};
