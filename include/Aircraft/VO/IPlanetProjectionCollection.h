#pragma once
#include "../../IAtkObj.h"
#include <vector>
struct CGfxAttSphPlanetProj;
class IPlanetProjection;

///
/// 三维姿态球行星投影列表
///
class IATKOBJECT_API IPlanetProjectionCollection
{
public:
    IPlanetProjectionCollection(const IPlanetProjectionCollection&) = delete;
    IPlanetProjectionCollection& operator=(const IPlanetProjectionCollection&) = delete;

	IPlanetProjectionCollection(std::vector<CGfxAttSphPlanetProj>* pVectorCGfxAttSphPlanetProj);
	~IPlanetProjectionCollection();

	//********************************************************************
	/// 获取个数
	/// @author	Gan Shu Long
	/// @date	2026-01-21
	/// @return	个数
	//********************************************************************
	int GetCount();

	//********************************************************************
	///  获取指定序号分级
	/// @author	Gan Shu Long
	/// @date	2026-01-21
	/// @param[in]	nIndex  指定序号
	/// @return	指定序号分级
	//********************************************************************
	IPlanetProjection* Item(int nIndex);

private:
	std::vector<IPlanetProjection*>				m_VectorIPlanetProjection;					//i对象行星投影指针列表

	std::vector<CGfxAttSphPlanetProj>*		m_pVectorCGfxAttSphPlanetProj;		//C对象行星投影指针列表
};

