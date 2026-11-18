#pragma once
#include <vector>
#include <string>
#include <map>
#include "../IAtkObj.h"
#include "../ICEnum.h"
struct CObjData;
class CObjManage;
class IAtkObjectRoot;
class IScenario;
struct CatSpaceStruct;
class ICATAdvance;
class CCatSpaceObj;
class CCatSimulation;
class CCatConjunction;

typedef struct AsTCatRes
{
	std::string		catName{};			///< 名字，ssc
	std::string		catTime{};			///< 最近距离时间
	double			catRange{0.0};			///< 最近距离, km
	double			catVel{0.0};				///< 最近距离对应相对速度, km/s
} AsTCatRes;

///
/// 接近分析
///
class IATKOBJECT_API ICat
{
public:
    ICat(const ICat&) = delete;
    ICat& operator=(const ICat&) = delete;

	ICat(IAtkObjectRoot* pRoot, CObjManage* IAsGObjManage);
	~ICat();

	//********************************************************************
	/// 根据卫星与TLE数据库对象计算
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[in]	vecSatelliteName 卫星对象名称，例Satellite1
	/// @param[in]	strTLEFilePath TLE数据文件路径
	/// @param[in]	vecExcSSCNum 排除SSC编号
	//********************************************************************
	void SetSatelliteFromScenario(std::vector<std::string> vecSatelliteName, std::string strTLEFilePath, std::vector<std::string> vecExcSSCNum = std::vector<std::string>());

	//********************************************************************
	/// 根据导弹/火箭与TLE数据库对象计算
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[in]	vecObjName 导弹/火箭对象名称，例Missile
	/// @param[in]	strTLEFilePath TLE数据文件路径
	/// @param[in]	vecExcSSCNum 排除SSC编号
	//********************************************************************
	void SetMissOrLauVehFromScenario(std::vector<std::string> vecObjName, std::string strTLEFilePath, std::vector<std::string> vecExcSSCNum = std::vector<std::string>());

	//********************************************************************
	/// 输入目标国际编号
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[in]	vecSSCNumber 库文件SSC编号，例00005
	/// @param[in]	strTLEFilePath TLE数据文件路径
	/// @param[in]	vecExcSSCNum 排除SSC编号
	//********************************************************************
	void SetInputSSCNumObject(std::vector<std::string> vecSSCNumber, std::string strTLEFilePath, std::vector<std::string> vecExcSSCNum = std::vector<std::string>());

	//********************************************************************
	/// 数据库目标遍历计算
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[in]	strTLEFilePath 库文件路径
	/// @param[in]	vecExcSSCNum 排除SSC编号
	//********************************************************************
	void SetAllTLEObjects(std::string strTLEFilePath, std::vector<std::string> vecExcSSCNum = std::vector<std::string>());

	//********************************************************************
	/// 是否使用场景时间
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[in]	bUse true-使用场景区间
	//********************************************************************
	void SetUseScenarioTimePeriod(bool bUse);
	//********************************************************************
	/// 获取是否使用场景时间
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @return	true-使用场景区间
	//********************************************************************
	bool GetUseScenarioTimePeriod();

	//********************************************************************
	/// 设置仿真分析时间
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[in]	strStartTime 仿真开始历元
	/// @param[in]	strStopTime 仿真结束历元
	//********************************************************************
	void SetTimePeriod(std::string strStartTime, std::string strStopTime);

	//********************************************************************
	/// 获取仿真分析时间
	/// @author	Gan Shu Long
	/// @date	2026-09-22
	/// @return	开始分析时间		
	//********************************************************************
	std::string GetStartTime();

	//********************************************************************
	/// 获取仿真分析时间
	/// @author	Gan Shu Long
	/// @date	2026-09-22
	/// @return	结束分析时间		
	//********************************************************************
	std::string GetStopTime();

	//********************************************************************
	/// 设置相对距离门限
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[in]	dValue 相对距离门限
	//********************************************************************
	void SetMaxRange(double dValue);
	//********************************************************************
	/// 获取相对距离门限
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @return	相对距离门限
	//********************************************************************
	double GetMaxRange();

	//********************************************************************
	/// 计算
	/// @author	Dong Min
	/// @date	2025-09-20
	//********************************************************************
	void Compute();

	//********************************************************************
	/// 获取结果
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[out]	PrimarySSC 主目标
	/// @param[out]	SecondarySSC 次目标
	/// @param[out]	EquivDist 等效距离 // m_MissDist/10 和 fabs(m_MissDistR)中较大者
	/// @param[out]	MissDistance 相对距离
	/// @param[out]	MissDistR 径向距离
	/// @param[out]	MissDistT 横向距离
	/// @param[out]	MissDistN 法向距离
	/// @param[out]	AngleCA 接近夹角
	/// @param[out]	RelativeVelocity 相对速度
	/// @param[out]	TCA 接近时刻
	/// @param[out]	Tin 开始时刻
	/// @param[out]	Tout 结束时刻
	//********************************************************************
	void GetResults(std::vector<std::string>& PrimarySSC,
		std::vector<std::string>& SecondarySSC,
		std::vector<double>& EquivDist,
		std::vector<double>& MissDistance,
		std::vector<double>& MissDistR,
		std::vector<double>& MissDistT,
		std::vector<double>& MissDistN,
		std::vector<double>& AngleCA,
		std::vector<double>& RelativeVelocity,
		std::vector<std::string>& TCA,
		std::vector<std::string>& Tin,
		std::vector<std::string>& Tout);

	//********************************************************************
	/// 高级配置指针
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @return	
	//********************************************************************
	ICATAdvance* GetAdvance();


	//********************************************************************
	/// 接近分析计算
	/// @author	
	/// @date	
	/// @param[in]	primElem 主目标卫星轨道根数 a, e, i, raan，argper，ma
	/// @param[in]	secElems 次目标卫星轨道根数 a, e, i, raan，argper，ma
	/// @param[in]	OrbPropType 轨道预报模型，与卫星对象对应
	/// @param[in]	startUTC 场景开始时间
	/// @param[in]	stopUTC 场景结束时间
	/// @param[in]	t1 分析时段开始时间UTC
	/// @param[in]	t2 分析时段结束时间UTC
	/// @param[in]	range 相对距离阈值, km
	/// @param[in]	vel 对速度阈值, km/s
	/// @param[out]	result 结果
	//********************************************************************
	void CatComponent(std::vector<double> primElem,
		std::vector<std::vector<double>> secElems,
		EVePropagatorType OrbPropType,
		std::string startUTC,
		std::string stopUTC,
		std::string t1,
		std::string t2,
		double range,
		double vel,
		std::vector<AsTCatRes>& result);

private:
	int SetObjElement(IScenario* pIScen, EVePropagatorType OrbPropType, std::vector<double> objElem, std::string strObjName, std::vector<CObjData*>& vecFrom);

private:
	IAtkObjectRoot*    m_pRoot;
	CObjManage*        m_IAsGObjManage;
	CCatSimulation*    m_pSimulationToRun;
	ICATAdvance*       m_ICATAdvance;

	int                                  m_Mode;
	bool                                 m_UseScenarioTimePeriod;
	std::vector<std::string>             m_excludeVec;
	std::vector<std::string>             m_primariesSSCs;
	std::map<std::string, CCatSpaceObj*> m_TleObj;
	std::map<std::string, CCatSpaceObj*> m_SatObj;
	std::vector<CCatConjunction>*        m_pCatFound;
};
