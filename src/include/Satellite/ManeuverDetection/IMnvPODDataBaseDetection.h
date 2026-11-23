#pragma once
#include <vector>
#include <string>
#include <map>
#include "../../ICEnum.h"
#include "../../IAtkObj.h"

class CMdOrbit2Orbit;
class CObjManage;


///
/// 机动分析
///
class IATKOBJECT_API IMnvPODDataBaseDetection
{
public:
    IMnvPODDataBaseDetection(const IMnvPODDataBaseDetection&) = delete;
    IMnvPODDataBaseDetection& operator=(const IMnvPODDataBaseDetection&) = delete;

	IMnvPODDataBaseDetection(CObjManage* IAsGObjManage);
	~IMnvPODDataBaseDetection();

	//********************************************************************
	/// 设置预报模型
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[in]	eType 预报模型，包括二体，J2，Vinti
	//********************************************************************
	void SetOrbitPropagator(EVePropagatorType eType);
	//********************************************************************
	/// 获取预报模型
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @return	预报模型
	//********************************************************************
	EVePropagatorType GetOrbitPropagator();

	//********************************************************************
	/// 设置交叉弧段预报步长
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[in]	dValue 交叉弧段预报步长
	//********************************************************************
	void SetStepOfCrossPropagation(double dValue);
	//********************************************************************
	/// 获取交叉弧段预报步长
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @return	交叉弧段预报步长
	//********************************************************************
	double GetStepOfCrossPropagation();

	//********************************************************************
	/// 设置A目标定轨数据历元
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[in]	strTime 历元时刻
	//********************************************************************
	void SetObjectATime(std::string strTime);
	//********************************************************************
	/// 获取A目标定轨数据历元
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @return	历元时刻
	//********************************************************************
	std::string GetObjectATime();

	//********************************************************************
	/// 设置A目标J2000坐标系
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[in]	dX x轴
	/// @param[in]	dY y轴
	/// @param[in]	dZ z轴
	/// @param[in]	dVx x轴速度
	/// @param[in]	dVy y轴速度
	/// @param[in]	dVz z轴速度
	//********************************************************************
	void SetObjectAJ2000Frame(double dX,
		double dY, 
		double dZ, 
		double dVx, 
		double dVy,
		double dVz);
	//********************************************************************
	/// 获取A目标J2000坐标系
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[out]	dX x轴
	/// @param[out]	dY y轴
	/// @param[out]	dZ z轴
	/// @param[out]	dVx x轴速度
	/// @param[out]	dVy y轴速度
	/// @param[out]	dVz z轴速度
	//********************************************************************
	void GetObjectAJ2000Frame(double& dX,
		double& dY,
		double& dZ,
		double& dVx,
		double& dVy,
		double& dVz);

	//********************************************************************
	/// 设置A目标LVLH坐标系
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[in]	dox x轴距离均方差
	/// @param[in]	doy y轴距离均方差
	/// @param[in]	doz z轴距离均方差
	/// @param[in]	dovx x轴速度均方差
	/// @param[in]	dovy y轴速度均方差
	/// @param[in]	dovz z轴速度均方差
	//********************************************************************
	void SetObjectAVVLHFrame(double dox,
		double doy,
		double doz,
		double dovx,
		double dovy,
		double dovz);
	//********************************************************************
	/// 获取A目标LVLH坐标系
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[out]	dox x轴距离均方差
	/// @param[out]	doy y轴距离均方差
	/// @param[out]	doz z轴距离均方差
	/// @param[out]	dovx x轴速度均方差
	/// @param[out]	dovy y轴速度均方差
	/// @param[out]	dovz z轴速度均方差
	//********************************************************************
	void GetObjectAVVLHFrame(double& dox,
		double& doy,
		double& doz,
		double& dovx,
		double& dovy,
		double& dovz);

	//********************************************************************
	/// 设置B目标定轨数据历元
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[in]	strTime 历元时刻
	//********************************************************************
	void SetObjectBTime(std::string strTime);
	//********************************************************************
	/// 获取B目标定轨数据历元
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @return	历元时刻
	//********************************************************************
	std::string GetObjectBTime();

	//********************************************************************
	/// 设置B目标J2000坐标系
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[in]	dX x轴
	/// @param[in]	dY y轴
	/// @param[in]	dZ z轴
	/// @param[in]	dVx x轴速度
	/// @param[in]	dVy y轴速度
	/// @param[in]	dVz z轴速度
	//********************************************************************
	void SetObjectBJ2000Frame(double dX,
		double dY,
		double dZ,
		double dVx,
		double dVy,
		double dVz);
	//********************************************************************
	/// 获取B目标J2000坐标系
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[out]	dX x轴
	/// @param[out]	dY y轴
	/// @param[out]	dZ z轴
	/// @param[out]	dVx x轴速度
	/// @param[out]	dVy y轴速度
	/// @param[out]	dVz z轴速度
	//********************************************************************
	void GetObjectBJ2000Frame(double& dX,
		double& dY,
		double& dZ,
		double& dVx,
		double& dVy,
		double& dVz);

	//********************************************************************
	/// 设置B目标LVLH坐标系
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[in]	dox x轴距离均方差
	/// @param[in]	doy y轴距离均方差
	/// @param[in]	doz z轴距离均方差
	/// @param[in]	dovx x轴速度均方差
	/// @param[in]	dovy y轴速度均方差
	/// @param[in]	dovz z轴速度均方差
	//********************************************************************
	void SetObjectBVVLHFrame(double dox,
		double doy,
		double doz,
		double dovx,
		double dovy,
		double dovz);
	//********************************************************************
	/// 获取B目标LVLH坐标系
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[out]	dox x轴距离均方差
	/// @param[out]	doy y轴距离均方差
	/// @param[out]	doz z轴距离均方差
	/// @param[out]	dovx x轴速度均方差
	/// @param[out]	dovy y轴速度均方差
	/// @param[out]	dovz z轴速度均方差
	//********************************************************************
	void GetObjectBVVLHFrame(double& dox,
		double& doy,
		double& doz,
		double& dovx,
		double& dovy,
		double& dovz);

	//********************************************************************
	/// 计算
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[out]	nMnvRes 机动关联结果：0-同目标未机动，1-同目标机动，2-相异目标
	/// @param[out]	strDetectDVutc 预估的机动时刻
	/// @param[out]	dDetectDVx 预估的机动分量Vx
	/// @param[out]	dDetectDVy 预估的机动分量Vy
	/// @param[out]	dDetectDVz 预估的机动分量Vz
	/// @param[out]	dSma 半长轴偏差
	/// @param[out]	dInc 倾角偏差
	/// @param[out]	dEcc 离心率偏差
	/// @param[out]	dRAAN 升交点赤经偏差
	/// @param[out]	strTime UTC时间
	/// @param[out]	dMahDist 马氏距离
	//********************************************************************
	void Compute(
		int& nMnvRes,
		std::string& strDetectDVutc,
		double& dDetectDVx,
		double& dDetectDVy,
		double& dDetectDVz,
		double& dSma,
		double& dInc,
		double& dEcc,
		double& dRAAN,
		std::vector<std::string>& strTime,
		std::vector<double>& dMahDist);

private:
	CObjManage*        m_IAsGObjManage;
	CMdOrbit2Orbit*    m_CMdOrbit2Orbit;

};
