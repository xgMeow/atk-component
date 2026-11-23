#pragma once
#include "../../IAtkObj.h"
#include <vector>
struct CGfxContourAttri;
class IVeGfxElevationsElement;

///
/// 二维等高线分级列表
///
class IATKOBJECT_API IVeGfxElevationsCollection
{
public:
    IVeGfxElevationsCollection(const IVeGfxElevationsCollection&) = delete;
    IVeGfxElevationsCollection& operator=(const IVeGfxElevationsCollection&) = delete;

	IVeGfxElevationsCollection(std::vector<CGfxContourAttri>* pVectorCGfxContourAttri);
	~IVeGfxElevationsCollection();

	//********************************************************************
	/// 添加分级deg
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @param[in]	dLevelDeg  分级deg
	/// @return		
	//********************************************************************
	IVeGfxElevationsElement* AddLevel(double dLevelDeg);

	//********************************************************************
	/// 根据步长添加分级deg
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @param[in]	dStartElevation 开始Elevation
	/// @param[in]	dStopElevation 停止Elevation
	/// @param[in]	dSetpElevation 步长Elevation
	//********************************************************************
	void AddLevelRange(double dStartElevation, double dStopElevation, double dSetpElevation);

	//********************************************************************
	/// 移除所有分级
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	//********************************************************************
	void RemoveAll();

	//********************************************************************
	/// 移除指定序号分级
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @param[in]	nIndex  指定序号
	//********************************************************************
	void RemoveAt(int nIndex);

	//********************************************************************
	/// 获取分级个数
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @return	分级个数
	//********************************************************************
	int GetCount();

	//********************************************************************
	///  获取指定序号分级
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @param[in]	nIndex  指定序号
	/// @return	指定序号分级
	//********************************************************************
	IVeGfxElevationsElement* Item(int nIndex);

private:
	std::vector<IVeGfxElevationsElement*>		m_VectorIVeGfxElevationsElement;	//i对象等高线分级指针列表，按deg从小到大排序

	std::vector<CGfxContourAttri>*		m_pVectorCGfxContourAttri;							//C对象等高线分级指针列表
};

