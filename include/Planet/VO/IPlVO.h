#pragma once
#include "../../IAtkObj.h"
class CObjManage;
struct CObjData;
class IVODataDisplayCollection;

///
/// 三维
///
class IATKOBJECT_API IPlVO
{
public:
    IPlVO(const IPlVO&) = delete;
    IPlVO& operator=(const IPlVO&) = delete;

	IPlVO(CObjData* pObjData, CObjManage* IAsGObjManage);
	~IPlVO();

	//********************************************************************
	/// 获得三维数据显示属性
	/// @author	Gan Shu Long
	/// @date	2026-03-09
	/// @return	三维数据显示指针		
	//********************************************************************
	IVODataDisplayCollection* GetDataDisplay() { return m_DataDisplay; }

private:
	IVODataDisplayCollection*		m_DataDisplay;				//三维数据显示指针
};
