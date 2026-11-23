#pragma once
#include <string>
#include "../IComponentInfo.h"

class CObjManage;
class CSatellite;
class CMCSSegment;
class CAsStateCalc;

///
/// 计算量Sunlight
///
class IATKOBJECT_API IVAStateCalcSunlight : public IComponentInfo
{
public:
    IVAStateCalcSunlight(const IVAStateCalcSunlight&) = delete;
    IVAStateCalcSunlight& operator=(const IVAStateCalcSunlight&) = delete;

	IVAStateCalcSunlight(
		CObjManage* IAsGObjManage,
		CSatellite* pSate,
		CMCSSegment* pcSegment,
		CAsStateCalc* pcAsStateCalc);
	~IVAStateCalcSunlight();


	//********************************************************************
	/// 设置参考航天器
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strReference   参考航天器名称,例:"Satellite/Satellite1"
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
