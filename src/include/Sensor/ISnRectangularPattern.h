#pragma once
#include "ISnPattern.h"
class CSensor;

///
/// 模式类型：矩形
///
class IATKOBJECT_API ISnRectangularPattern : public ISnPattern
{
public:
    ISnRectangularPattern(const ISnRectangularPattern&) = delete;
    ISnRectangularPattern& operator=(const ISnRectangularPattern&) = delete;

	ISnRectangularPattern(CSensor* pCSensor);
	~ISnRectangularPattern();

	//********************************************************************
	/// 设置 水平半推角
	/// @author	Gan Shu Long
	/// @date	2025-07-10
	/// @param[in]	dHorizontalHalfAngle  水平半推角
	//********************************************************************
	void SetHorizontalHalfAngle(double dHorizontalHalfAngle);

	//********************************************************************
	/// 获得 水平半推角
	/// @author	Gan Shu Long
	/// @date	2025-07-10
	/// @return	double 水平半推角	
	//********************************************************************
	double GetHorizontalHalfAngle();

	//********************************************************************
	/// 设置 垂直半推角
	/// @author	Gan Shu Long
	/// @date	2025-07-10
	/// @param[in]	dVerticalHalfAngle  垂直半推角
	//********************************************************************
	void SetVerticalHalfAngle(double dVerticalHalfAngle);

	//********************************************************************
	/// 获得 垂直半推角
	/// @author	Gan Shu Long
	/// @date	2025-07-10
	/// @return	double 垂直半推角	
	//********************************************************************
	double GetVerticalHalfAngle();

private:
	CSensor*			m_pCSensor;
};

