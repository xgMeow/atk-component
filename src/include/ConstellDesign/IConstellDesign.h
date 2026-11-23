#pragma once
#include <string>
#include "../IAtkObject.h"

class CObjManage;
class ISatellite;
class IAtkObjectRoot;
struct CObjData;
struct Conste_SatInfo;
struct Conste_SeedSat;
struct CTleElem;

///
/// 星座设计
///
class IATKOBJECT_API IConstellDesign
{
public:
    IConstellDesign(const IConstellDesign&) = delete;
    IConstellDesign& operator=(const IConstellDesign&) = delete;

	IConstellDesign(IAtkObjectRoot* pRoot, CObjManage* IAsGObjManage);
	~IConstellDesign();

	//********************************************************************
	/// 星座设计 WalkerDelta
	/// @author	Gan Shu Long
	/// @date	2025-7-1
	/// @param[in]	sMajAx  半长轴
	/// @param[in]	ecc  偏心率
	/// @param[in]	inc  轨道倾角
	/// @param[in]	raan  升交点赤经
	/// @param[in]	argPeri  近拱点角
	/// @param[in]	trueAnomaly  真近点角
	/// @param[in]	numPlanes  轨道面个数
	/// @param[in]	numSatsPerPlane  面卫星数
	/// @param[in]	interPlaneSpacing  相位因子
	/// @param[in]	raanSpread  RAAN分布范围
	/// @return	
	//********************************************************************
	std::vector<ISatellite*> ConstellDesignWalkerDelta(double sMajAx, double ecc, double inc, double raan, double argPeri, double trueAnomaly, int numPlanes, int numSatsPerPlane, int interPlaneSpacing, double raanSpread);

	//********************************************************************
	/// 星座设计 WalkerDelta(种子)
	/// @author	Gan Shu Long
	/// @date	2025-7-1
	/// @param[in]	seedSatPath  种子卫星路径
	/// @param[in]	numPlanes  轨道面个数
	/// @param[in]	numSatsPerPlane  面卫星数
	/// @param[in]	interPlaneSpacing  相位因子
	/// @param[in]	raanSpread  RAAN分布范围
	/// @return	
	//********************************************************************
	std::vector<ISatellite*> ConstellDesignWalkerDeltaBySeed(std::string seedSatPath, int numPlanes, int numSatsPerPlane, int interPlaneSpacing, double raanSpread);

	//********************************************************************
	/// 星座设计 Walker-自定义
	/// @author	Gan Shu Long
	/// @date	2025-7-1
	/// @param[in]	sMajAx  半长轴
	/// @param[in]	ecc  偏心率
	/// @param[in]	inc  轨道倾角
	/// @param[in]	raan  升交点赤经
	/// @param[in]	argPeri  近拱点角
	/// @param[in]	trueAnomaly  真近点角
	/// @param[in]	numPlanes  轨道面个数
	/// @param[in]	numSatsPerPlane  面卫星数
	/// @param[in]	trueAnomalyPhasing  相邻平面真近点角增量
	/// @param[in]	raanIncrement  相邻平面RAAN差值
	/// @return	
	//********************************************************************
	std::vector<ISatellite*> ConstellDesignWalkerCustom(double sMajAx, double ecc, double inc, double raan, double argPeri, double trueAnomaly, int numPlanes, int numSatsPerPlane, double trueAnomalyPhasing, double raanIncrement);

	//********************************************************************
	/// 星座设计 Walker-自定义(种子)
	/// @author	Gan Shu Long
	/// @date	2025-7-1
	/// @param[in]	seedSatPath  种子卫星路径
	/// @param[in]	numPlanes  轨道面个数
	/// @param[in]	numSatsPerPlane  面卫星数
	/// @param[in]	trueAnomalyPhasing  相邻平面真近点角增量
	/// @param[in]	raanIncrement  相邻平面RAAN差值
	/// @return	
	//********************************************************************
	std::vector<ISatellite*> ConstellDesignWalkerCustomBySeed(std::string seedSatPath, int numPlanes, int numSatsPerPlane, double trueAnomalyPhasing, double raanIncrement);

	//********************************************************************
	/// 星座设计 玫瑰星座
	/// @author	Gan Shu Long
	/// @date	2025-7-1
	/// @param[in]	sMajAx  半长轴
	/// @param[in]	ecc  偏心率
	/// @param[in]	inc  轨道倾角
	/// @param[in]	raan  升交点赤经
	/// @param[in]	argPeri  近拱点角
	/// @param[in]	trueAnomaly  真近点角
	/// @param[in]	numPlanes  轨道面个数
	/// @param[in]	numSatsPerPlane  面卫星数
	/// @param[in]	molecule  协因子分子
	/// @return	
	//********************************************************************
	std::vector<ISatellite*> ConstellDesignRosette(double sMajAx, double ecc, double inc, double raan, double argPeri, double trueAnomaly, int numPlanes, int numSatsPerPlane, int molecule);

	//********************************************************************
	/// 星座设计 玫瑰星座(种子)
	/// @author	Gan Shu Long
	/// @date	2025-7-1
	/// @param[in]	seedSatPath  种子卫星路径
	/// @param[in]	numPlanes  轨道面个数
	/// @param[in]	numSatsPerPlane  面卫星数
	/// @param[in]	molecule  协因子分子
	/// @return	
	//********************************************************************
	std::vector<ISatellite*> ConstellDesignRosetteBySeed(std::string seedSatPath, int numPlanes, int numSatsPerPlane, int molecule);

	//********************************************************************
	/// 星座设计 花星座
	/// @author	Gan Shu Long
	/// @date	2025-7-1
	/// @param[in]	sMajAx  半长轴
	/// @param[in]	ecc  偏心率
	/// @param[in]	inc  轨道倾角
	/// @param[in]	raan  升交点赤经
	/// @param[in]	argPeri  近拱点角
	/// @param[in]	trueAnomaly  真近点角
	/// @param[in]	returnCircle  回归圈数
	/// @param[in]	returnDay  回归天数
	/// @param[in]	phaseDensity  相位密度
	/// @param[in]	interPlaneSpacing  相邻平面相位因子
	/// @param[in]	numSats  总卫星数
	/// @param[in]	raanSpread  分布范围
	/// @return	
	//********************************************************************
	std::vector<ISatellite*> ConstellDesignFlower(double sMajAx, double ecc, double inc, double raan, double argPeri, double trueAnomaly, int returnCircle, int returnDay, int phaseDensity, int interPlaneSpacing, int numSats, double raanSpread);

	//********************************************************************
	/// 星座设计 花星座(种子)
	/// @author	Gan Shu Long
	/// @date	2025-7-1
	/// @param[in]	seedSatPath  种子卫星路径
	/// @param[in]	returnCircle  回归圈数
	/// @param[in]	returnDay  回归天数
	/// @param[in]	phaseDensity  相位密度
	/// @param[in]	interPlaneSpacing  相邻平面相位因子
	/// @param[in]	numSats  总卫星数
	/// @param[in]	raanSpread  分布范围
	/// @return	
	//********************************************************************
	std::vector<ISatellite*> ConstellDesignFlowerBySeed(std::string seedSatPath, int returnCircle, int returnDay, int phaseDensity, int interPlaneSpacing, int numSats, double raanSpread);

	//********************************************************************
	/// 星座设计 非对称花星座
	/// @author	Gan Shu Long
	/// @date	2025-7-1
	/// @param[in]	sMajAx  半长轴
	/// @param[in]	ecc  偏心率
	/// @param[in]	inc  轨道倾角
	/// @param[in]	raan  升交点赤经
	/// @param[in]	argPeri  近拱点角
	/// @param[in]	trueAnomaly  真近点角
	/// @param[in]	returnCircle  回归圈数
	/// @param[in]	returnDay  回归天数
	/// @param[in]	numSats  总卫星数
	/// @param[in]	raanIncrement  升交点赤经差
	/// @return	
	//********************************************************************
	std::vector<ISatellite*> ConstellDesignNonSymFlower(double sMajAx, double ecc, double inc, double raan, double argPeri, double trueAnomaly, int returnCircle, int returnDay, int numSats, double raanIncrement);

	//********************************************************************
	/// 星座设计 非对称花星座(种子)
	/// @author	Gan Shu Long
	/// @date	2025-7-1
	/// @param[in]	seedSatPath  种子卫星路径
	/// @param[in]	returnCircle  回归圈数
	/// @param[in]	returnDay  回归天数
	/// @param[in]	numSats  总卫星数
	/// @param[in]	raanIncrement  升交点赤经差
	/// @return	
	//********************************************************************
	std::vector<ISatellite*> ConstellDesignNonSymFlowerBySeed(std::string seedSatPath, int returnCircle, int returnDay, int numSats, double raanIncrement);

private:
	bool GetSeedSatInfo(std::string seedSatPath, Conste_SeedSat& conste, std::string& parentObjPath, std::string&  strRefObjName, CObjData *pSeedData);
	void SetConsteSeedSatOrb(int seedSatType, double sMajAx, double ecc, double inc, double raan, double argPeri, double trueAnomaly, Conste_SeedSat& conste);
	void SetConsteSeedSatTLE(int seedSatType, CTleElem tleElem, Conste_SeedSat& conste);
	void CreateCSatellites(CObjData *pSeedData, int nConsType, std::string parentObjPath, std::string strRefObjName, std::vector<Conste_SatInfo> vecResultElem, std::vector<ISatellite*>& objID);

private:
	IAtkObjectRoot*		m_Root;
	CObjManage*			m_IAsGObjManage;
};
