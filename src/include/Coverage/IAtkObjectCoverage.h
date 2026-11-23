#pragma once
#include "../IAtkObj.h"
#include "../ICEnum.h"
#include <string>
class CObjManage;
class ICvAssetListCollection;
class IObjectCoverageFOM;

///
/// 覆盖性
///
class IATKOBJECT_API IAtkObjectCoverage
{
public:
	IAtkObjectCoverage(const IAtkObjectCoverage&) = delete;
	IAtkObjectCoverage& operator=(const IAtkObjectCoverage&) = delete;

	IAtkObjectCoverage(CObjManage* IAsGObjManage);
	~IAtkObjectCoverage();

	//********************************************************************
	/// 清除所有覆盖性计算结果
	/// @author	Gan Shu Long
	/// @date	2026-10-01
	//********************************************************************
	void ClearCoverage();

	//********************************************************************
	/// 覆盖性计算
	/// @author	Gan Shu Long
	/// @date	2026-10-01
	//********************************************************************
	void Compute();

	//********************************************************************
	/// 输出覆盖性报告
	/// @author	Gan Shu Long
	/// @date	2026-10-14
	/// @param[in] 	eCoverageReportType 覆盖性报告类型
	/// @return	覆盖性报告数据
	//********************************************************************
	std::string OutputCoverageReport(ECoverageReportType eCoverageReportType);

	//********************************************************************
	/// 设置覆盖性计算开始历元
	/// @author	Gan Shu Long
	/// @date	2026-10-09
	/// @param[in]	strStartTime  覆盖性计算开始历元
	/// 时间格式支持(1993-01-01 00:00:00.00)、(1 Jan 1993 00:00:00.0)和(1 January 1993 00:00:00.0)
	//********************************************************************
	void SetStartTime(std::string strStartTime);

	//********************************************************************
	/// 获得覆盖性计算开始历元
	/// @author	Gan Shu Long
	/// @date	2026-10-01
	/// @return	覆盖性计算开始历元
	/// 时间格式支持(1993-01-01 00:00:00.00)
	//********************************************************************
	std::string GetStartTime();

	//********************************************************************
	/// 设置覆盖性计算结束历元
	/// @author	Gan Shu Long
	/// @date	2026-10-09
	/// @param[in]	strStopTime  覆盖性计算结束历元
	/// 时间格式支持(1993-01-01 00:00:00.00)、(1 Jan 1993 00:00:00.0)和(1 January 1993 00:00:00.0)
	//********************************************************************
	void SetStopTime(std::string strStopTime);

	//********************************************************************
	/// 获得覆盖性计算结束历元
	/// @author	Gan Shu Long
	/// @date	2026-10-01
	/// @return	覆盖性计算结束历元
	/// 时间格式支持(1993-01-01 00:00:00.00)
	//********************************************************************
	std::string GetStopTime();

	//********************************************************************
	/// 设置计算步长
	/// @author	gan shu long 
	/// @date	2026-10-14
	/// @param[in]	dTimeStep  计算步长
	//********************************************************************
	void SetTimeStep(double dTimeStep);

	//********************************************************************
	/// 获得计算步长
	/// @author	gan shu long 
	/// @date	2026-10-14
	/// @return	计算步长
	//********************************************************************
	double GetTimeStep();

	//********************************************************************
	/// 获得覆盖性访问对象集合
	/// @author	Gan Shu Long
	/// @date	2026-10-01
	/// @return	覆盖性访问对象集合
	//********************************************************************
	ICvAssetListCollection* GetAccAssets() { return m_AccAssets; }

	//********************************************************************
	/// 获得覆盖性目标对象集合
	/// @author	Gan Shu Long
	/// @date	2026-10-01
	/// @return	覆盖性目标对象集合
	//********************************************************************
	ICvAssetListCollection* GetTarAssets() { return m_TarAssets; }

	//********************************************************************
	/// 获得覆盖性计算品质因子
	/// @author	Gan Shu Long
	/// @date	2026-10-14
	/// @return	覆盖性计算品质因子
	//********************************************************************
	IObjectCoverageFOM* GetFOM() { return m_FOM; }

private:
	CObjManage*					m_IAsGObjManage;

	ICvAssetListCollection*     m_AccAssets;	//访问对象集合
	ICvAssetListCollection*     m_TarAssets;	//目标对象集合
	IObjectCoverageFOM*			m_FOM;			//覆盖性计算品质因子
};
