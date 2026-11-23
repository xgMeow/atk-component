#pragma once
#include <string>
#include "../../IAtkObj.h"
class CSatellite;
class ISatellite;

///
/// 地球引力
///
class IATKOBJECT_API IVeHPOPCentralBodyGravity
{
public:
    IVeHPOPCentralBodyGravity(const IVeHPOPCentralBodyGravity&) = delete;
    IVeHPOPCentralBodyGravity& operator=(const IVeHPOPCentralBodyGravity&) = delete;

	IVeHPOPCentralBodyGravity(CSatellite* pSate, ISatellite* pISate);
	~IVeHPOPCentralBodyGravity();

	//********************************************************************
	/// 设置HPOP轨道力模型中地球引力的阶数和次数
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	nMaximumDegree   阶数
	/// @param[in]	nMaximumOrder    次数
	//********************************************************************
	void SetMaximumDegreeAndOrder(int nMaximumDegree, int nMaximumOrder);

	//********************************************************************
	/// 设置HPOP轨道力模型中地球引力模型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	strGravModel 地球引力模型
	//********************************************************************
	void SetGravModel(std::string strGravModel);
	//********************************************************************
	/// 获得HPOP轨道力模型中地球引力模型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	地球引力模型
	//********************************************************************
	std::string GetGravModel();

	//********************************************************************
	/// 设置HPOP轨道力模型中地球引力的阶数
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	nDegree 阶数
	//********************************************************************
	void SetMaxDegree(int nDegree);
	//********************************************************************
	/// 获得HPOP轨道力模型中地球引力的阶数
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	阶数
	//********************************************************************
	int GetMaxDegree();

	//********************************************************************
	/// 设置HPOP轨道力模型中地球引力的次数
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	nOrder 次数
	//********************************************************************
	void SetMaxOrder(int nOrder);
	//********************************************************************
	/// 获得HPOP轨道力模型中地球引力的次数
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	次数
	//********************************************************************
	int GetMaxOrder();

private:
	CSatellite*     m_pSate;
	//ISatellite*     m_pISate;
};
