#pragma once
#include "IAtkObject.h"
class CObjManage;
class ICObjectFunction;

///
/// 场景对象
///
class IATKOBJECT_API IScenario :public IAtkObject
{
public:
    IScenario(const IScenario&) = delete;
    IScenario& operator=(const IScenario&) = delete;

	IScenario(CObjData* pObjData, CObjManage* IAsGObjManage, IAtkObjectRoot* Root);
	~IScenario();

	//********************************************************************
	/// 设置 场景时间
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	strStartUTC  开始时间，例："1 Jan 2000 00:00:00.000"
	/// @param[in]	strStopUTC   结束时间，例："2 Jan 2000 00:00:00.000"
	//********************************************************************
	void SetTimePeriod(std::string strStartUTC, std::string strStopUTC);

	//********************************************************************
	/// 设置开始时间
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	strStartTime  开始时间，例："1 Jan 2000 00:00:00.000"
	//********************************************************************
	void SetStartTime(std::string strStartTime);
	//********************************************************************
	/// 获取开始时间
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	开始时间
	//********************************************************************
	std::string GetStartTime();

	//********************************************************************
	/// 设置结束时间
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	strStopTime   结束时间，例："2 Jan 2000 00:00:00.000"
	//********************************************************************
	void SetStopTime(std::string strStopTime);
	//********************************************************************
	/// 获取结束时间
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	结束时间
	//********************************************************************
	std::string GetStopTime();

	//********************************************************************
	/// 获取仿真步长
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @note 取值：结束时间
	//********************************************************************
	//double GetStepSize();

	//********************************************************************
	/// 获取开始时间BACC格式
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	开始时间
	//********************************************************************
	std::string GetStartTimeBACC();

	//********************************************************************
	/// 获取结束时间BACC格式
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	结束时间
	//********************************************************************
	std::string GetStopTimeBACC();

	//********************************************************************
	/// 获取增加时长时间
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	strTime   输入时间，例："2012-03-15T10:00:00"
	/// @param[in]	dSec   增加时间长度
	/// @param[in]	strAddTime   添加后的时间
	/// @return	是否添加成功
	//********************************************************************
	bool GetAddTime(std::string strTime, double dSec, std::string& strAddTime);

};
