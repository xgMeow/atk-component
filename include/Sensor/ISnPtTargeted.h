#pragma once
#include "../IAtkObj.h"
#include "ISnPointing.h"
#include "../ICEnum.h"
#include <vector>
#include <string>
struct CObjData;
class ISensor;
class CObjManage;
class IAtkObject;
class ISnPtTrgtBsight;
class ISnTargetCollection;
class CSensor;

///
/// 指向：目标定向
///
class IATKOBJECT_API ISnPtTargeted : public ISnPointing
{
public:
    ISnPtTargeted(const ISnPtTargeted&) = delete;
    ISnPtTargeted& operator=(const ISnPtTargeted&) = delete;

	ISnPtTargeted(CObjData* pCObjData, ISensor* pISensor, CObjManage* IAsGObjManage);
	~ISnPtTargeted();

	//********************************************************************
	/// 设置 瞄准类型
	/// @author	Gan Shu Long
	/// @date	2026-03-23
	/// @param[in]	eSnPtTrgtBsightType  瞄准类型
	//********************************************************************
	void SetBoresight(ESnPtTrgtBsightType eSnPtTrgtBsightType);

	//********************************************************************
	/// 获得 瞄准类型
	/// @author	Gan Shu Long
	/// @date	2026-03-23
	/// @return	瞄准类型
	//********************************************************************
	ESnPtTrgtBsightType GetBoresight();
	
	//********************************************************************
	/// 获得 瞄准指针
	/// @author	Gan Shu Long
	/// @date	2026-03-23
	/// @return	瞄准指针
	//********************************************************************
	ISnPtTrgtBsight* BoresightData() { return m_BoresightData; }

	//********************************************************************
	/// 获得 可选对象路径列表
	/// @author	Gan Shu Long
	/// @date	2026-03-23
	/// @return 可选对象路径列表
	//********************************************************************
	std::vector<std::string> GetAvailableTargets();
	
	//********************************************************************
	/// 获得 已选对象列表
	/// @author	Gan Shu Long
	/// @date	2026-03-23
	/// @return 已选对象列表
	//********************************************************************
	ISnTargetCollection* GetTargets() { return m_Targets; }

private:
	void GetSubObjAvailableTargets(IAtkObject* pIAtkObject);

private:
	CObjData*						m_pCObjData;
	CSensor*						m_pCSensor;

	ISensor*							m_pISensor;
	ISnPtTrgtBsight*				m_BoresightData;
	ISnTargetCollection*		m_Targets;
	std::vector<std::string>	m_VecStrAvailableTargets;
};

