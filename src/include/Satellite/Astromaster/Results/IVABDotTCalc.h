#pragma once
#include <string>
#include "../IComponentInfo.h"
class CMCSSegment;
class CAsStateCalc;

///
/// 计算量BDotT
///
class IATKOBJECT_API IVABDotTCalc : public IComponentInfo
{
public:
    IVABDotTCalc(const IVABDotTCalc&) = delete;
    IVABDotTCalc& operator=(const IVABDotTCalc&) = delete;

	IVABDotTCalc(CObjManage* pObjManage, CMCSSegment* pcSegment, CAsStateCalc* pcAsStateCalc);
	~IVABDotTCalc();

	//********************************************************************
	/// 设置中心天体名称
	/// @Author	Dong Min
	/// @Date	2025-12-11
	/// @Input
	/// @Param	strCBName   中心天体名称，例：Earth，Moon，Mars
	/// @Return	
	//********************************************************************
	void SetCentralBodyName(std::string strCBName);
	//********************************************************************
	/// 获得中心天体名称
	/// @Author	Dong Min
	/// @Date	2025-12-11
	/// @Return	中心天体名称
	//********************************************************************
	std::string GetCentralBodyName();

	//********************************************************************
	/// 设置参考向量
	/// @Author	Dong Min
	/// @Date	2025-12-11
	/// @Input
	/// @Param	strRefVec   例："Satellite/Satellite2 J2000.X"
	/// @Return	
	//********************************************************************
	void SetRefrenceVector(std::string strRefVec);
	//********************************************************************
	/// 获得参考向量
	/// @Author	Dong Min
	/// @Date	2025-12-11
	/// @Return	参考向量
	//********************************************************************
	std::string GetRefrenceVector();

private:
	CObjManage*       m_pObjManage;
	CMCSSegment*      m_pcSegment;
	CAsStateCalc*     m_pcAsStateCalc;
};
