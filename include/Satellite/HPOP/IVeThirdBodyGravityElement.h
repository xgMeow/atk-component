#pragma once
#include <string>
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
class CSatellite;

///
/// 三体引力
///
class IATKOBJECT_API IVeThirdBodyGravityElement
{
public:
    IVeThirdBodyGravityElement(const IVeThirdBodyGravityElement&) = delete;
    IVeThirdBodyGravityElement& operator=(const IVeThirdBodyGravityElement&) = delete;

	IVeThirdBodyGravityElement(CSatellite* pSate, std::string strCentralBody);
	~IVeThirdBodyGravityElement();

	//********************************************************************
	/// 获得三体引力集合里的元素中心天体名称
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	中心天体名称
	//********************************************************************
	std::string GetCentralBody() { return m_CentralBody; }
	
	//********************************************************************
	/// 设置三体引力集合里的阶数
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dGravDegree 三体引力集合里的阶数
	//********************************************************************
	void SetGravityDegree(int dGravDegree);
	//********************************************************************
	/// 获得三体引力集合里的阶数
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	阶数
	//********************************************************************
	double GetGravityDegree();

	//********************************************************************
	/// 设置三体引力集合里的次数
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dGravOrder 三体引力集合里的次数
	//********************************************************************
	void SetGravityOrder(int dGravOrder);
	//********************************************************************
	/// 获得三体引力集合里的次数
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	次数
	//********************************************************************
	double GetGravityOrder();

	//********************************************************************
	/// 设置三体引力集合里的类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eTHGType 三体引力集合里的类型
	//********************************************************************
	void SetType(EThirdBodyGravType eTHGType);
	//********************************************************************
	/// 获得三体引力集合里的类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	类型
	//********************************************************************
	EThirdBodyGravType GetType();

	//********************************************************************
	/// 设置三体引力集合里的模型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	strModel 三体引力集合里的模型
	//********************************************************************
	void SetModel(std::string strModel);
	//********************************************************************
	/// 获得三体引力集合里的模型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	模型
	//********************************************************************
	std::string GetModel();

	//********************************************************************
	/// 设置三体引力集合里的引力常数
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dGM 三体引力集合里的引力常数
	//********************************************************************
	void SetGravityValue(double dGM);
	//********************************************************************
	/// 获得三体引力集合里的引力常数
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	引力常数
	//********************************************************************
	double GetGravityValue();

private:
	CSatellite*           m_pSate;

	std::string            m_CentralBody;     //三体引力集合里的元素中心天体名称

	int GetGravityID(std::string strCentralBody);

};

