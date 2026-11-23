#pragma once
#include "../IAtkObj.h"
#include "../ICEnum.h"
#include <vector>
#include <string>

class CObjManage;
struct CObjData;
struct AsTAdvCatObj;
class CAdvCat;
class ISatellite;
class IAtkObject;

///
/// 高级接近分析主配置
///
class IATKOBJECT_API IAdvCATMain
{
public:
    IAdvCATMain(const IAdvCATMain&) = delete;
    IAdvCATMain& operator=(const IAdvCATMain&) = delete;

	IAdvCATMain(CObjData* pObjData, CObjManage* IAsGObjManage);
	~IAdvCATMain();

	//********************************************************************
	/// 设置主目标序列
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pPrimSate  主目标对象
	//********************************************************************
	void SetPrimaryList(ISatellite* pPrimSate);

	//********************************************************************
	/// 获取主目标序列
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @return	主目标列表
	//********************************************************************
	std::vector<ISatellite*> GetPrimaryList();

	//********************************************************************
	/// 从主目标列表移除指定目标对象
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pPrimSate  主目标对象
	//********************************************************************
	void RemovePrimary(ISatellite* pPrimSate);

	//********************************************************************
	/// 清空主目标列表
	/// @author	Dong Min
	/// @date	2025-04-28
	//********************************************************************
	void RemoveAllPrimary();

	//********************************************************************
	/// 设置椭球三轴切向
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pPrimSate  主目标对象
	/// @param[in]	dTangential  椭球三轴切向，单位m
	//********************************************************************
	void SetPriTangential(ISatellite* pPrimSate, double dTangential);

	//********************************************************************
	/// 获取椭球三轴切向
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pPrimSate  主目标对象
	/// @return	椭球三轴切向，单位m
	//********************************************************************
	double GetPriTangential(ISatellite* pPrimSate);

	//********************************************************************
	/// 设置椭球三轴横向
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pPrimSate  主目标对象
	/// @param[in]	dCrossTrack  椭球三轴横向，单位m
	//********************************************************************
	void SetPriCrossTrack(ISatellite* pPrimSate, double dCrossTrack);

	//********************************************************************
	/// 获取椭球三轴横向
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pPrimSate  主目标对象
	/// @return	椭球三轴横向，单位m
	//********************************************************************
	double GetPriCrossTrack(ISatellite* pPrimSate);

	//********************************************************************
	/// 设置椭球三轴法向
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pPrimSate  主目标对象
	/// @param[in]	dNormal  椭球三轴法向，单位m
	//********************************************************************
	void SetPriNormal(ISatellite* pPrimSate, double dNormal);

	//********************************************************************
	/// 获取椭球三轴法向
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pPrimSate  主目标对象
	/// @return	椭球三轴法向，单位m
	//********************************************************************
	double GetPriNormal(ISatellite* pPrimSate);

	//********************************************************************
	/// 设置包络球半径
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pPrimSate  主目标对象
	/// @param[in]	dRadius  包络球半径，单位m
	//********************************************************************
	void SetPriRadius(ISatellite* pPrimSate, double dRadius);

	//********************************************************************
	/// 获取包络球半径
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pPrimSate  主目标对象
	/// @return	包络球半径
	//********************************************************************
	double GetPriRadius(ISatellite* pPrimSate);

	//********************************************************************
	/// 设置椭球类别
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pPrimSate  主目标对象
	/// @param[in]	eClassType  椭球类别，单位m
	//********************************************************************
	void SetPriClass(ISatellite* pPrimSate, EAdvCatEllipType eClassType);

	//********************************************************************
	/// 获取椭球类别
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pPrimSate  主目标对象
	/// @return	椭球类别
	//********************************************************************
	EAdvCatEllipType GetPriClass(ISatellite* pPrimSate);

	//********************************************************************
	/// 设置次目标序列
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pScdSate  次目标对象
	//********************************************************************
	void SetSecondList(ISatellite* pScdSate);

	//********************************************************************
	/// 获取次目标序列
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @return	次目标列表
	//********************************************************************
	std::vector<ISatellite*> GetSecondList();

	//********************************************************************
	/// 从次目标列表移除指定目标对象
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pScdSate  次目标对象
	//********************************************************************
	void RemoveSecond(ISatellite* pScdSate);

	//********************************************************************
	/// 清空次目标列表
	/// @author	Dong Min
	/// @date	2025-04-28
	//********************************************************************
	void RemoveAllSecond();

	//********************************************************************
	/// 设置椭球三轴切向
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pScdSate  次目标对象
	/// @param[in]	dTangential  椭球三轴切向，单位m
	//********************************************************************
	void SetScdTangential(ISatellite* pScdSate, double dTangential);

	//********************************************************************
	/// 获取椭球三轴切向
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pScdSate  次目标对象
	/// @return	椭球三轴切向，单位m
	//********************************************************************
	double GetScdTangential(ISatellite* pScdSate);

	//********************************************************************
	/// 设置椭球三轴横向
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pScdSate  次目标对象
	/// @param[in]	dCrossTrack  椭球三轴横向，单位m
	//********************************************************************
	void SetScdCrossTrack(ISatellite* pScdSate, double dCrossTrack);

	//********************************************************************
	/// 获取椭球三轴横向
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pScdSate  次目标对象
	/// @return	椭球三轴横向，单位m
	//********************************************************************
	double GetScdCrossTrack(ISatellite* pScdSate);

	//********************************************************************
	/// 设置椭球三轴法向
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pScdSate  次目标对象
	/// @param[in]	dNormal  椭球三轴法向，单位m
	//********************************************************************
	void SetScdNormal(ISatellite* pScdSate, double dNormal);

	//********************************************************************
	/// 获取椭球三轴法向
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pScdSate  次目标对象
	/// @return	椭球三轴法向，单位m
	//********************************************************************
	double GetScdNormal(ISatellite* pScdSate);

	//********************************************************************
	/// 设置包络球半径
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pScdSate  次目标对象
	/// @param[in]	dRadius  包络球半径，单位m
	//********************************************************************
	void SetScdRadius(ISatellite* pScdSate, double dRadius);

	//********************************************************************
	/// 获取包络球半径
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pScdSate  次目标对象
	/// @return	包络球半径
	//********************************************************************
	double GetScdRadius(ISatellite* pScdSate);

	//********************************************************************
	/// 设置椭球类别
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pScdSate  次目标对象
	/// @param[in]	eClassType  椭球类别，单位m
	//********************************************************************
	void SetScdClass(ISatellite* pScdSate, EAdvCatEllipType eClassType);

	//********************************************************************
	/// 获取椭球类别
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	pScdSate  次目标对象
	/// @return	椭球类别
	//********************************************************************
	EAdvCatEllipType GetScdClass(ISatellite* pScdSate);

	//********************************************************************
	/// 设置是否使用场景时间
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	bUseSceInterval  是否使用场景时间，true-使用场景分析时间
	//********************************************************************
	void SetUseSceInterval(bool bUseSceInterval);

	//********************************************************************
	/// 获取是否使用场景时间
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @return	是否使用场景时间，true-使用场景分析时间
	//********************************************************************
	bool GetUseSceInterval();

	//********************************************************************
	/// 设置分析时间段
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	strStartTime  开始分析时间
	/// @param[in]	strEndTime 结束分析时间
	/// @note 返回值：姿态属性指针
	//********************************************************************
	void SetTimePeriod(std::string strStartTime, std::string strEndTime);

	//********************************************************************
	/// 获取分析时间段
	/// @author	Gan Shu Long
	/// @date	2026-09-22
	/// @return	开始分析时间		
	//********************************************************************
	std::string GetStartTime();

	//********************************************************************
	/// 获取分析时间段
	/// @author	Gan Shu Long
	/// @date	2026-09-22
	/// @return	结束分析时间		
	//********************************************************************
	std::string GetStopTime();

	//********************************************************************
	/// 设置阈值
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	dThreshold  距离阈值，单位m
	//********************************************************************
	void SetThreshold(double dThreshold);

	//********************************************************************
	/// 获取阈值
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @return  距离阈值，单位m
	//********************************************************************
	double GetThreshold();

	//********************************************************************
	/// 设置是否使用距离测量
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @param[in]	bUseRangeMeasure  true = 使用点距离；false = 使用椭距
	//********************************************************************
	void SetUseRangeMeasure(bool bUseRangeMeasure);

	//********************************************************************
	/// 获取是否使用距离测量
	/// @author	Dong Min
	/// @date	2025-04-28
	/// @return  true = 使用点距离；false = 使用椭距
	//********************************************************************
	bool GetUseRangeMeasure();

	//********************************************************************
	/// 计算
	/// @author	Dong Min
	/// @date	2025-04-28
	//********************************************************************
	void Compute();

	//********************************************************************
	/// 获取结果数据大小
	/// @author	Dong Min
	/// @date	2025-05-09
	/// @param[in]	primID  
	/// @param[in]	secID  
	/// @param[in]	tca  
	/// @param[in]	caMinRange  
	/// @param[in]	caMinVel  
	//********************************************************************
	void GetDetail(std::vector<std::string>& primID,
		std::vector<std::string>& secID,
		std::vector<std::string>& tca,
		std::vector<double>& caMinRange,
		std::vector<double>& caMinVel);

private:
	CObjManage* m_IAsGObjManage;
	std::vector<ISatellite*> vecPriISate;
	std::vector<ISatellite*> vecSecISate;

	CAdvCat* m_pAdvCAT;

};

