#pragma once
#include <vector>
#include "../../IAtkObj.h"
struct CGfxVeh2DCustom;
class IVeGfxInterval;

///
/// 二维自定义显示集合
///
class IATKOBJECT_API IVeGfxIntervalsCollection
{
public:
    IVeGfxIntervalsCollection(const IVeGfxIntervalsCollection&) = delete;
    IVeGfxIntervalsCollection& operator=(const IVeGfxIntervalsCollection&) = delete;

	IVeGfxIntervalsCollection(std::vector<CGfxVeh2DCustom>* pCGfxVeh2DCustoms);
	~IVeGfxIntervalsCollection();

	//********************************************************************
	/// 设置二维自定义显示添加属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	strStart  开始时间
	/// @param[in]	strStop  结束时间
	/// @return	自定义显示属性指针
	//********************************************************************
	IVeGfxInterval* Add(std::string strStart,std::string strStop);

	//********************************************************************
	/// 设置二维自定义显示移除所有属性
	/// @author	Dong Min
	/// @date	2023-11-3
	//********************************************************************
	void RemoveAll();

	//********************************************************************
	/// 设置二维自定义显示移除指定属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	nIndex  指定属性序号
	//********************************************************************
	void RemoveAt(int nIndex);

	//********************************************************************
	/// 设置二维自定义显示集合属性个数
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	二维自定义显示集合属性个数
	//********************************************************************
	int GetCount();

	//********************************************************************
	/// 设置二维自定义显示集合属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	nIndex  指定序号，按添加顺序排列
	/// @return	二维自定义显示集合属性指针
	//********************************************************************
	IVeGfxInterval* Item(int nIndex);

private:
	std::vector<CGfxVeh2DCustom>*		m_pCGfxVeh2DCustoms;	//C对象二维显示自定义队列指针

	std::vector<IVeGfxInterval*>		m_vecGfxInterval;		//二维自定义显示集合属性

};
