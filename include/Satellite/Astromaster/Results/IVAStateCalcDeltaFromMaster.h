#pragma once
#include <string>
#include "../../../ICEnum.h"
#include "../IComponentInfo.h"
class CObjManage;
class CSatellite;
class CMCSSegment;
class CAsStateCalc;

///
/// 计算量DeltaDec
///
class IATKOBJECT_API IVAStateCalcDeltaFromMaster : public IComponentInfo
{
public:
    IVAStateCalcDeltaFromMaster(const IVAStateCalcDeltaFromMaster&) = delete;
    IVAStateCalcDeltaFromMaster& operator=(const IVAStateCalcDeltaFromMaster&) = delete;

	IVAStateCalcDeltaFromMaster(CSatellite* pSate, CMCSSegment* pcSegment, CAsStateCalc* pcAsStateCalc, CObjManage* IAsGObjManage);
	~IVAStateCalcDeltaFromMaster();

	//********************************************************************
	/// 设置中心天体名称
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strCBName   中心天体名称，例:Earth，Moon，Mars
	/// @Return	
	//********************************************************************
	void SetCentralBodyName(std::string strCBName);
	//********************************************************************
	/// 获得中心天体名称
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	中心天体名称
	//********************************************************************
	std::string GetCentralBodyName();

	//********************************************************************
	/// 设置参考航天器
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strReference   参考航天器名称
	/// @Return	
	//********************************************************************
	void SetReference(std::string strReference);
	//********************************************************************
	/// 获得参考航天器名称
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	参考航天器名称
	//********************************************************************
	std::string GetReference();

private:
	CObjManage*       m_IAsGObjManage;
	CSatellite*       m_pSate;
	CMCSSegment*      m_pcSegment;
	CAsStateCalc*     m_pcAsStateCalc;
};
