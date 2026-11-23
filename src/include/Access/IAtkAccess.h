#pragma once
#include "../IAtkObj.h"
#include "../ICEnum.h"
#include <string>
#include <vector>
class CObjManage;
class IAtkObject;
class CCTime;

///
/// 可见性
///
class IATKOBJECT_API IAtkAccess
{
public:
    IAtkAccess(const IAtkAccess&) = delete;
    IAtkAccess& operator=(const IAtkAccess&) = delete;

	IAtkAccess(CObjManage* IAsGObjManage, IAtkObject* pIAtkObject, IAtkObject* pIAccessObject);
	~IAtkAccess();

	//********************************************************************
	/// 清除可见性计算结果
	/// @author	Gan Shu Long
	/// @date	2026-09-22
	//********************************************************************
	void ClearAccess();

	//********************************************************************
	/// 可见性计算
	/// @author	Gan Shu Long
	/// @date	2026-09-22
	//********************************************************************
	void ComputeAccess();

	//********************************************************************
	/// 获取可见性计算结果
	/// @author	gan shu long
	/// @date	2026-09-22
	/// @return	
	//********************************************************************
	std::vector<std::vector<std::string>> ComputedAccessIntervalTimes();

	//********************************************************************
	/// 移除可见性
	/// @author	Gan Shu Long
	/// @date	2026-09-22
	//********************************************************************
	void RemoveAccess();

	//********************************************************************
	/// 设置可见性计算时间
	/// @author	Gan Shu Long
	/// @date	2026-09-22
	/// @param[in]	strStartTime  开始历元
	/// @param[in]	strStopTime	  结束历元
	//********************************************************************
	void SetAccessTimePeriod(std::string strStartTime, std::string strStopTime);

	//********************************************************************
	/// 获得可见性计算时间
	/// @author	Gan Shu Long
	/// @date	2026-09-22
	/// @return	开始历元
	//********************************************************************
	std::string GetAccessStartTime();

	//********************************************************************
	/// 获得可见性计算时间
	/// @author	Gan Shu Long
	/// @date	2026-09-22
	/// @return	结束历元
	//********************************************************************
	std::string GetAccessStopTime();

	//********************************************************************
	/// 设置可见性计算步长
	/// @author	gan shu long 
	/// @date	2026-09-03
	/// @param[in]	dTimeStep  计算步长
	//********************************************************************
	void SetTimeStep(double dTimeStep);

	//********************************************************************
	/// 获得可见性计算步长
	/// @author	gan shu long 
	/// @date	2026-09-03
	/// @return	计算步长
	//********************************************************************
	double GetTimeStep();

	//********************************************************************
	/// 设置使用光延迟
	/// @author	gan shu long 
	/// @date	2026-09-03
	/// @param[in]	bUseLTD  是否使用光延迟
	//********************************************************************
	void SetUseLTD(bool bUseLTD);

	//********************************************************************
	/// 获得是否使用光延迟
	/// @author	gan shu long 
	/// @date	2026-09-03
	/// @return 是否使用光延迟
	//********************************************************************
	bool GetUseLTD();

	//********************************************************************
	/// 输出可见性报告
	/// @author	Gan Shu Long
	/// @date	2026-09-03
	/// @param[in] 	eAccessReportType 可见性报告类型
	/// @return	可见性报告数据
	//********************************************************************
	std::string OutputAccessReport(EAccessReportType eAccessReportType);


private:
	CObjManage*     m_IAsGObjManage;
	IAtkObject*     m_pIAtkObject;
	IAtkObject*     m_pIAccessObject;

	//AccessCoverageDataTree* GetAccessData(AccessCore* pAccessCore);

};
