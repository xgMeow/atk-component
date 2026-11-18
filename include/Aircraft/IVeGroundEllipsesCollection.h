#pragma once
#include "../IAtkObj.h"
#include <vector>
#include <string>
struct CVehEllipseSet;
class IVeGroundEllipseElement;

///
/// 椭圆设置集合
///
class IATKOBJECT_API IVeGroundEllipsesCollection
{
public:
    IVeGroundEllipsesCollection(const IVeGroundEllipsesCollection&) = delete;
    IVeGroundEllipsesCollection& operator=(const IVeGroundEllipsesCollection&) = delete;

	IVeGroundEllipsesCollection(std::vector<CVehEllipseSet>* pVectorCVehEllipseSet);
	~IVeGroundEllipsesCollection();

	//********************************************************************
	/// 添加椭圆设置
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	/// @param[in]	strEllipseSetName  椭圆设置名称
	/// @return 椭圆设置
	//********************************************************************
	IVeGroundEllipseElement* Add(std::string strEllipseSetName);

	//********************************************************************
	///  获取指定名称椭圆设置
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	/// @param[in]	strEllipseSetName  椭圆设置名称
	/// @return	指定名称椭圆设置
	//********************************************************************
	IVeGroundEllipseElement* GetEllipseSet(std::string strEllipseSetName);

	//********************************************************************
	/// 移除所有椭圆设置
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	//********************************************************************
	void RemoveAll();

	//********************************************************************
	/// 移除指定序号椭圆设置
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	/// @param[in]	nIndex  指定序号
	//********************************************************************
	void RemoveAt(int nIndex);

	//********************************************************************
	/// 移除指定椭圆设置
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	/// @param[in]	strEllipseSetName  椭圆设置名称
	//********************************************************************
	void RemoveEllipseSet(std::string strEllipseSetName);

	//********************************************************************
	/// 获取集合个数
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	/// @return	集合个数
	//********************************************************************
	int GetCount();

	//********************************************************************
	///  获取指定序号椭圆设置
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	/// @param[in]	nIndex  指定序号
	/// @return	指定序号椭圆设置
	//********************************************************************
	IVeGroundEllipseElement* Item(int nIndex);

private:
	std::vector<IVeGroundEllipseElement*>			m_VectorIVeGroundEllipseElement;				//i对象椭圆设置集合

	std::vector<CVehEllipseSet>*							m_pVectorCVehEllipseSet;								//C对象椭圆设置集合
};

