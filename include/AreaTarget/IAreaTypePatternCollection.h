#pragma once
#include "../IAtkObj.h"
#include "IAreaTypeData.h"
#include <vector>
class IAreaTypePattern;
struct AsTAtPos;

///
/// 区域模式(边界坐标列表)
///
class IATKOBJECT_API IAreaTypePatternCollection :public IAreaTypeData
{
public:
    IAreaTypePatternCollection(const IAreaTypePatternCollection&) = delete;
    IAreaTypePatternCollection& operator=(const IAreaTypePatternCollection&) = delete;

	IAreaTypePatternCollection(AsTAtPos* pAsTAtPos);
	~IAreaTypePatternCollection();

	//********************************************************************
	/// 添加区域边界坐标
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @param[in]	dLat  维度
	/// @param[in]	dLon  经度
	/// @return 区域边界坐标
	//********************************************************************
	IAreaTypePattern* Add(double dLat, double dLon);

	//********************************************************************
	/// 插入区域边界坐标
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @param[in]	dLat  维度
	/// @param[in]	dLon  经度
	/// @param[in]	nIndex  指定序号
	/// @return 区域边界坐标
	//********************************************************************
	IAreaTypePattern* Insert(double dLat, double dLon, int nIndex);

	//********************************************************************
	/// 移除指定序号区域边界坐标
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @param[in]	nIndex  指定序号
	//********************************************************************
	void Remove(int nIndex);

	//********************************************************************
	/// 移除所有区域边界坐标
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	//********************************************************************
	void RemoveAll();

	//********************************************************************
	/// 返回数组
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @return	std::vector<IAreaTypePattern*> 区域边界坐标Vector
	//********************************************************************
	std::vector<IAreaTypePattern*> ToArray();

	//********************************************************************
	/// 获取集合个数
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @return	集合个数
	//********************************************************************
	int GetCount();

	//********************************************************************
	///  获取指定序号区域边界坐标
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @param[in]	nIndex  指定序号
	/// @return	指定序号区域边界坐标
	//********************************************************************
	IAreaTypePattern* Item(int nIndex);

private:
	AsTAtPos*										m_pAsTAtPos;							//C对象边界坐标列表
	std::vector<IAreaTypePattern*>		m_VectorIAreaTypePattern;
};
