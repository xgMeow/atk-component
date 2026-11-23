#pragma once
#include "../../ICEnum.h"
#include <vector>
struct CObjData;
class IScenario;
struct CVehAttSegment;

///
/// 单段姿态列表
///
class IATKOBJECT_API IVeMultiSegmentBasic
{
public:
    IVeMultiSegmentBasic(const IVeMultiSegmentBasic&) = delete;
    IVeMultiSegmentBasic& operator=(const IVeMultiSegmentBasic&) = delete;

	IVeMultiSegmentBasic(CObjData* pObjData, IScenario* pIScenario);
	~IVeMultiSegmentBasic();

	//********************************************************************
	/// 添加姿态段，默认开始时间为当前最后一条姿态段开始时间+1小时
	/// @author	Gan Shu Long
	/// @date	2026-02-28
	/// @param[in]	strStartTime 开始时间
	/// @param[in]	eVeProfile 姿态类型
	/// @param[in]	dqx
	/// @param[in]	dqy
	/// @param[in]	dqz
	/// @param[in]	dqs
	/// @return	是否添加成功
	//********************************************************************
	bool Add(std::string strStartTime, EVeProfile eVeProfile, double dqx, double dqy, double dqz, double dqs);

	//********************************************************************
	/// 删除姿态段
	/// @author	Gan Shu Long
	/// @date	2026-02-28
	/// @param[in]	index 删除索引
	/// @return	是否删除成功
	//********************************************************************
	bool Remove(int index);

	//********************************************************************
	///姿态段数量
	/// @author	Gan Shu Long
	/// @date	2026-03-01
	/// @return	int 姿态段数量
	//********************************************************************
	int GetCount();

private:
	CObjData*												m_pObjData;
	IScenario*												m_pIScenario;
	std::vector<CVehAttSegment>*				m_pVectorCVehAttSegment;
};


