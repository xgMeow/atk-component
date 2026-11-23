#pragma once
#include "IVeWaypointsElement.h"
#include "../ICEnum.h"
#include <vector>
struct CObjData;


///
/// 路径列表
///
class IATKOBJECT_API IVeWaypointsCollection
{
public:
    IVeWaypointsCollection(const IVeWaypointsCollection&) = delete;
    IVeWaypointsCollection& operator=(const IVeWaypointsCollection&) = delete;

	IVeWaypointsCollection(CObjData* pObjData);
	~IVeWaypointsCollection();

	//********************************************************************
	/// 复制路径集合的最后一个元素，添加到集合最后
	/// @author	Gan Shu Long
	/// @date	2023-11-27
	/// @return	IVeWaypointsElement* 路径点指针
	//********************************************************************
	IVeWaypointsElement* Add();

	//********************************************************************
	/// 确定集合是否包含指定时间的路径点
	/// @author	Gan Shu Long
	/// @date	2023-11-27
	/// @param[in]	time 指定时间
	/// @return	bool 是否包含指定时间的路径点
	//********************************************************************
	bool Contains(double time);

	//********************************************************************
	/// 确定集合是否包含指定的路径点并返回现有路径的索引
	/// @author	Gan Shu Long
	/// @date	2023-11-27
	/// @param[in]	time 指定时间
	/// @return	int 指定时间在集合中的索引，索引< 0表示在集合中不存在的方式点。
	//********************************************************************
	int IndexOf(double time);

	//********************************************************************
	/// 从集合中删除所有元素
	/// @author	Gan Shu Long
	/// @date	2023-11-27
	//********************************************************************
	void RemoveAll();

	//********************************************************************
	/// 使用指定索引从集合中删除元素
	/// @author	Gan Shu Long
	/// @date	2023-11-27
	/// @param[in]	index
	//********************************************************************
	void RemoveAt(int index);

	//********************************************************************
	/// 获取集合
	/// @author	Gan Shu Long
	/// @date	2023-11-27
	/// @return	std::vector<IVeWaypointsElement*> 路径点指针Vector
	//********************************************************************
	std::vector<IVeWaypointsElement*> ToArray();

	//********************************************************************
	/// 给定索引,返回集合中的一个元素
	/// @author	Gan Shu Long
	/// @date	2023-12-8
	/// @param[in]	index 索引
	/// @return	IVeWaypointsElement* 路径点指针
	//********************************************************************
	IVeWaypointsElement* Item(int index);

	//********************************************************************
	///集合中元素的数量
	/// @author	Gan Shu Long
	/// @date	2025-09-15
	/// @return	int 集合中元素的数量
	//********************************************************************
	int GetCount();

protected:
	std::vector<IVeWaypointsElement*> m_WaypointsElementVector;

private:
	void*			m_CObjData;		//保存一份C对象实例，省的每次改动时都需要重新便利寻找
	EATKObjectType	m_eCObjType;	//C对象类型，IPosition同时是IFacility和ISensor的成员变量类型
};
