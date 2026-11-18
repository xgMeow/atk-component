#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
#include <string>
class CLaunchVehicle;
struct CObjData;

///
/// 历元间隔
///
class IATKOBJECT_API ICrdnEventIntervalSmartInterval
{
public:
    ICrdnEventIntervalSmartInterval(const ICrdnEventIntervalSmartInterval&) = delete;
    ICrdnEventIntervalSmartInterval& operator=(const ICrdnEventIntervalSmartInterval&) = delete;

	ICrdnEventIntervalSmartInterval(CObjData* pObjData);
	~ICrdnEventIntervalSmartInterval();

	//********************************************************************
	/// 设置开始历元
	/// @author	Gan Shu Long
	/// @date	2024-09-23
	/// @param[in]	startEpoch 开始历元
	//********************************************************************
	void SetStartEpoch(std::string  startEpoch);

	//********************************************************************
	/// 获得开始历元
	/// @author	Gan Shu Long
	/// @date	2024-09-23
	/// @return	开始历元
	//********************************************************************
	std::string  GetStartEpoch();

	//********************************************************************
	/// 设置结束历元
	/// @author	Gan Shu Long
	/// @date	2024-09-23
	/// @param[in]	stopEpoch 结束历元
	//********************************************************************
	void SetStopEpoch(std::string  stopEpoch);

	//********************************************************************
	/// 获得结束历元
	/// @author	Gan Shu Long
	/// @date	2024-09-23
	/// @return	结束历元
	//********************************************************************
	std::string  GetStopEpoch();

	//********************************************************************
	/// 设置 历元类型
	/// @author	Gan Shu Long
	/// @date	2026-10-22
	/// @param[in]	eCrdnSmartIntervalState 历元类型
	//********************************************************************
	void SetState(ECrdnSmartIntervalState eCrdnSmartIntervalState);

	//********************************************************************
	/// 获得 历元类型
	/// @author	Gan Shu Long
	/// @date	2026-10-22
	/// @return	历元类型
	//********************************************************************
	ECrdnSmartIntervalState GetState();

private:
	CObjData*		m_pObjData;
};

