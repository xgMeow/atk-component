#pragma once
#include "../IAtkObj.h"
class CAntenna;

///
/// 天线指向偏移
///
class IATKOBJECT_API ICartesian3Vector
{
public:
    ICartesian3Vector(const ICartesian3Vector&) = delete;
    ICartesian3Vector& operator=(const ICartesian3Vector&) = delete;

	ICartesian3Vector(CAntenna* pCAntenna);
	~ICartesian3Vector();

	//********************************************************************
	/// 设置  X
	/// @author	Gan Shu Long
	/// @date	2026-03-19
	/// @param[in]	dX X
	//********************************************************************
	void SetX(double dX);

	//********************************************************************
	/// 获得 X
	/// @author	Gan Shu Long
	/// @date	2026-03-19
	/// @return	X
	//********************************************************************
	double GetX();

	//********************************************************************
	/// 设置  Y
	/// @author	Gan Shu Long
	/// @date	2026-03-19
	/// @param[in]	dY Y
	//********************************************************************
	void SetY(double dY);

	//********************************************************************
	/// 获得 Y
	/// @author	Gan Shu Long
	/// @date	2026-03-19
	/// @return	Y
	//********************************************************************
	double GetY();

	//********************************************************************
	/// 设置  Z
	/// @author	Gan Shu Long
	/// @date	2026-03-19
	/// @param[in]	dZ Z
	//********************************************************************
	void SetZ(double dZ);

	//********************************************************************
	/// 获得 Z
	/// @author	Gan Shu Long
	/// @date	2026-03-19
	/// @return	Z
	//********************************************************************
	double GetZ();

private:
	CAntenna*			m_pCAntenna;		//天线对象指针
};

