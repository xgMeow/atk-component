#pragma once
#include "../../IAtkObj.h"
class CObjManage;
struct CObjData;
class CSensor;
class ISnVOPulse;
class IVOVector;
class IVODataDisplayCollection;

///
/// 传感器三维
///
class IATKOBJECT_API ISnVO
{
public:
    ISnVO(const ISnVO&) = delete;
    ISnVO& operator=(const ISnVO&) = delete;

	ISnVO(CObjData* pObjData);
	~ISnVO();

	//********************************************************************
	/// 设置三维空间投影属性
	/// @author	Gan Shu Long
	/// @date	2024-06-12
	/// @param[in]	nSpaceProjection  三维空间投影属性
	//********************************************************************
	void SetSpaceProjection(double nSpaceProjection);

	//********************************************************************
	/// 获得三维空间投影属性
	/// @author	Gan Shu Long
	/// @date	2024-06-12
	/// @return	三维空间投影属性		
	//********************************************************************
	double GetSpaceProjection();

	//********************************************************************
	/// 设置 是否使用距离约束
	/// @author	Gan Shu Long
	/// @date	2026-03-24
	/// @param[in]	bEnableRangeConstraint  是否使用距离约束
	//********************************************************************
	void SetEnableRangeConstraint(bool bEnableRangeConstraint);

	//********************************************************************
	/// 获得 是否使用距离约束
	/// @author	Gan Shu Long
	/// @date	2026-03-24
	/// @return	是否使用距离约束
	//********************************************************************
	bool GetEnableRangeConstraint();

	//********************************************************************
	/// 获得三维脉冲属性
	/// @author	Gan Shu Long
	/// @date	2024-06-12
	/// @return	三维脉冲属性指针		
	//********************************************************************
	ISnVOPulse* GetPulse() { return m_Pulse; }

	//********************************************************************
	/// 获得三维向量属性
	/// @author	Gan Shu Long
	/// @date	2024-06-12
	/// @return	三维向量属性指针		
	//********************************************************************
	IVOVector* GetVector() { return m_Vector; }

	//********************************************************************
	/// 获得三维数据显示属性
	/// @author	Gan Shu Long
	/// @date	2026-01-05
	/// @return	三维数据显示属性指针		
	//********************************************************************
	IVODataDisplayCollection* GetDataDisplay() { return m_DataDisplay; }

private:
	CSensor*		m_pCSensor;

	ISnVOPulse*							m_Pulse;						//三维脉冲属性
	IVOVector*								m_Vector;					//三维向量属性
	IVODataDisplayCollection*     m_DataDisplay;			//三维数据显示属性
};
