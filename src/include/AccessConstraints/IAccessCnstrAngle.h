#pragma once
#include "../ICEnum.h"
#include "IAccessConstraint.h"
struct CObjData;

///
/// 设置角度的约束
///
class IATKOBJECT_API IAccessCnstrAngle : public IAccessConstraint
{
public:
    IAccessCnstrAngle(const IAccessCnstrAngle&) = delete;
    IAccessCnstrAngle& operator=(const IAccessCnstrAngle&) = delete;

	IAccessCnstrAngle(CObjData* pcObjData, EAccessConstraints eConstraint);
	~IAccessCnstrAngle();

	//********************************************************************
	/// 设置角度值
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dAngle  角度值
	//********************************************************************
	void SetAngle(double dAngle);
	//********************************************************************
	/// 获取角度值
	/// @author	Dong Min
	/// @date	2023-11-3 
	/// @return	角度值
	//********************************************************************
	double GetAngle() { return m_Angle; };

private:
	//CObjData*              m_pcObjData;

	double                 m_Angle;         //角度值
	EAccessConstraints     m_eConstraint;   //约束类型

};
