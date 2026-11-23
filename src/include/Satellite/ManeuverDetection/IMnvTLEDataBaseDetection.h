#pragma once
#include <vector>
#include <string>
#include <map>
#include "../../ICEnum.h"
#include "../../IAtkObj.h"

class CMdHistroyTLE;
class CObjManage;


///
/// 机动分析
///
class IATKOBJECT_API IMnvTLEDataBaseDetection
{
public:
    IMnvTLEDataBaseDetection(const IMnvTLEDataBaseDetection&) = delete;
    IMnvTLEDataBaseDetection& operator=(const IMnvTLEDataBaseDetection&) = delete;

	IMnvTLEDataBaseDetection(CObjManage* IAsGObjManage);
	~IMnvTLEDataBaseDetection();

	//********************************************************************
	/// 设置待检测卫星TLE数据
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[in]	strFilePath 待检测卫星TLE数据文件路径
	//********************************************************************
	void SetTLEData(std::string strFilePath);
	//********************************************************************
	/// 获取待检测卫星TLE数据
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @return 待检测卫星TLE数据文件路径
	//********************************************************************
	std::string GetTLEData();

	//********************************************************************
	/// 设置判断方法
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[in]	eMethodType 判断方法
	//********************************************************************
	void SetJudMethodType(EJudMethodType eMethodType);
	//********************************************************************
	/// 获取判断方法
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @return	判断方法
	//********************************************************************
	EJudMethodType GetJudMethodType();

	//********************************************************************
	/// 设置判断方法值
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[in]	dValue 判断方法值
	///			       EJudMethodType取eConfidenceLevel时，用于判断某历史数据点是否异常的置信概率
	///			       EJudMethodType取eMahalanobisDistar时，利用n-sigma法则进行机动检测的设定值n
	//********************************************************************
	void SetJudMethodID(double dValue);
	//********************************************************************
	/// 获取判断方法值
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @return	判断方法值
	//********************************************************************
	double GetJudMethodID();

	//********************************************************************
	/// 设置检测参数
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[in]	eType 检测参数
	//********************************************************************
	void SetOrbitalElem(EOrbitalElemType eType);
	//********************************************************************
	/// 获取检测参数
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @return	检测参数
	//********************************************************************
	EOrbitalElemType GetOrbitalElem();

	//********************************************************************
	/// 设置机动量估计方法
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[in]	eType 机动量估计方法
	//********************************************************************
	void SetEstMethodType(EEstMethodType eType);
	//********************************************************************
	/// 获取机动量估计方法
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @return	机动量估计方法
	//********************************************************************
	EEstMethodType GetEstMethodType();

	//********************************************************************
	/// 设置平滑方法
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[in]	eType 平滑方法
	//********************************************************************
	void SetSmoothMethod(ESmoothMethodType eType);
	//********************************************************************
	/// 获取平滑方法
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @return	平滑方法
	//********************************************************************
	ESmoothMethodType GetSmoothMethod();

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
	/// 计算
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @param[out]	strTime 机动时间
	/// @param[out]	dOutliers 异常值
	/// @param[out]	dSemiimajorAxisDev 半长轴偏差
	/// @param[out]	dRadial 径向机动
	/// @param[out]	dTransverse 迹向机动
	/// @param[out]	dNormal 法向机动
	//********************************************************************
	void Compute(std::vector<std::string>& strTime,
		std::vector<double>& dOutliers,
		std::vector<double>& dSemiimajorAxisDev,
		std::vector<double>& dRadial,
		std::vector<double>& dTransverse,
		std::vector<double>& dNormal);

private:
	CObjManage*                   m_IAsGObjManage;
	CMdHistroyTLE*                m_CMdHistroyTLE;


};
