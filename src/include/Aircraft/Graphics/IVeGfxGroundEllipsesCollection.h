#pragma once
#include "../../IAtkObj.h"
#include <vector>
struct CVehEllipseSet;
class IVeGfxGroundEllipsesElement;

///
/// 椭圆设置集合
///
class IATKOBJECT_API IVeGfxGroundEllipsesCollection
{
public:
    IVeGfxGroundEllipsesCollection(const IVeGfxGroundEllipsesCollection&) = delete;
    IVeGfxGroundEllipsesCollection& operator=(const IVeGfxGroundEllipsesCollection&) = delete;

	IVeGfxGroundEllipsesCollection(std::vector<CVehEllipseSet>* pVectorCVehEllipseSet);
	~IVeGfxGroundEllipsesCollection();

	//********************************************************************
	/// 获取集合个数
	/// @author	Gan Shu Long
	/// @date	2026-01-09
	/// @return	集合个数
	//********************************************************************
	int GetCount();

	//********************************************************************
	///  获取指定序号椭圆设置
	/// @author	Gan Shu Long
	/// @date	2026-01-09
	/// @param[in]	nIndex  指定序号
	/// @return	指定序号椭圆设置
	//********************************************************************
	IVeGfxGroundEllipsesElement* Item(int nIndex);

private:
	std::vector<IVeGfxGroundEllipsesElement*>			m_VectorIVeGfxGroundEllipsesElement;				//i对象椭圆设置集合

	std::vector<CVehEllipseSet>*								m_pVectorCVehEllipseSet;										//C对象椭圆设置集合
};

