#pragma once
#include "ISnPtTrgtBsight.h"
#include "../ICEnum.h"
struct CObjData;
class CSensor;

///
/// 瞄准类型：追踪
///
class IATKOBJECT_API ISnPtTrgtBsightTrack : public ISnPtTrgtBsight
{
public:
    ISnPtTrgtBsightTrack(const ISnPtTrgtBsightTrack&) = delete;
    ISnPtTrgtBsightTrack& operator=(const ISnPtTrgtBsightTrack&) = delete;

	ISnPtTrgtBsightTrack(CObjData* pCObjData);
	~ISnPtTrgtBsightTrack();

	//********************************************************************
	/// 设置 追踪模式
	/// @author	Gan Shu Long
	/// @date	2026-03-23
	/// @param[in]	eTrackModeType  追踪模式
	//********************************************************************
	void SetTrackMode(ETrackModeType eTrackModeType);

	//********************************************************************
	/// 获得 追踪模式
	/// @author	Gan Shu Long
	/// @date	2026-03-23
	/// @return	追踪模式
	//********************************************************************
	ETrackModeType GetTrackMode();

	/// 设置 视轴类型 todo
	/// 获得 视轴类型 todo

private:
	CSensor*			m_pCSensor;
};
