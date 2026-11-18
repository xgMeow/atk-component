#pragma once
#include <vector>
#include <string>
#include "../../IAtkObj.h"
struct CObjData;
struct CGfxObjDataDisplay;
class IVODataDisplayElement;

///
/// 三维数据显示集合
///
class IATKOBJECT_API IVODataDisplayCollection
{
public:
    IVODataDisplayCollection(const IVODataDisplayCollection&) = delete;
    IVODataDisplayCollection& operator=(const IVODataDisplayCollection&) = delete;

	IVODataDisplayCollection(std::vector<CGfxObjDataDisplay>* pVectorCGfxObjDataDisplay);
	~IVODataDisplayCollection();

	//********************************************************************
	/// 添加数据显示元素
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	strName  数据显示名称
	///	"Beta Angle Eclipse"
	///	"Classical Elements"
	///	"Euler姿态"
	///	"J2000 Position Velocity"
	///	"RTN light"
	///	"位置速度"
	///	"圈数"
	///	"地固系位置速度"
	///	"地固系纬度经度半径"
	///	"地固系纬度经度高度"
	///	"地影"
	///	"日期时间"
	///	"时间圈数姿态"
	///	"相对位置"
	///	"轨道周期"
	/// @return	数据显示属性指针
	//********************************************************************
	IVODataDisplayElement* Add(std::string strName);

	//********************************************************************
	/// 移除所有数据显示属性指针
	/// @author	Dong Min
	/// @date	2023-11-3
	//********************************************************************
	void RemoveAll();

	//********************************************************************
	/// 移除指定数据显示属性指针
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	nIndex  集合中第nIndex个元素
	//********************************************************************
	void RemoveAt(int nIndex);

	//********************************************************************
	/// 获得集合个数
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	集合个数	
	//********************************************************************
	int GetCount();

	//********************************************************************
	/// 获得指定数据显示属性指针
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	nIndex  X轴长度
	/// @return	数据显示属性指针
	//********************************************************************
	IVODataDisplayElement* Item(int nIndex);

private:
	std::vector<CGfxObjDataDisplay>*			m_pVectorCGfxObjDataDisplay;

	std::vector<std::string>								m_AvailableData;   //支持数据名称
	std::vector<IVODataDisplayElement*>		m_vecVODspyElem;   //元素数组

	bool IsAvailableFileName(std::string strFileName);

};
