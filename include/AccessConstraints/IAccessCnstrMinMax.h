#pragma once
#include "IAccessConstraint.h"
struct CObjData;

///
/// 设置大小值的约束
///
class IATKOBJECT_API IAccessCnstrMinMax : public IAccessConstraint
{
public:
    IAccessCnstrMinMax(const IAccessCnstrMinMax&) = delete;
    IAccessCnstrMinMax& operator=(const IAccessCnstrMinMax&) = delete;

	IAccessCnstrMinMax(CObjData* pcObjData, EAccessConstraints eConstraint);
	~IAccessCnstrMinMax();

	//********************************************************************
	/// 设置是否使用最大值
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	bEnableMax  是否使用最大值
	//********************************************************************
	void SetEnableMax(bool bEnableMax);
	//********************************************************************
	/// 获取是否使用最大值
	/// @author	Dong Min
	/// @date	2023-11-3 
	/// @return	是否使用最大值
	//********************************************************************
	bool GetEnableMax() { return m_EnableMax; };

	//********************************************************************
	/// 设置是否使用最小值
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	bEnableMin  是否使用最小值
	//********************************************************************
	void SetEnableMin(bool bEnableMin);
	//********************************************************************
	/// 获取是否使用最小值
	/// @author	Dong Min
	/// @date	2023-11-3 
	/// @return	是否使用最小值
	//********************************************************************
	bool GetEnableMin() { return m_EnableMin; };

	//********************************************************************
	/// 设置最大值
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dMax  最大值
	//********************************************************************
	void SetMax(double dMax);
	//********************************************************************
	/// 获取最大值
	/// @author	Dong Min
	/// @date	2023-11-3 
	/// @return	最大值
	//********************************************************************
	double GetMax() { return m_Max; };

	//********************************************************************
	/// 设置最小值
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dMin  最小值
	//********************************************************************
	void SetMin(double dMin);
	//********************************************************************
	/// 获取最小值
	/// @author	Dong Min
	/// @date	2023-11-3 
	/// @return	最小值
	//********************************************************************
	double GetMin() { return m_Min; };

private:
	//CObjData*              m_pcObjData;
	EAccessConstraints     m_eConstraint;   //约束类型

	bool                   m_EnableMax;     //约束最大值是否使用
	bool                   m_EnableMin;     //约束最小值是否使用
	double                 m_Max;           //约束最大值
	double                 m_Min;           //约束最小值



};


