#pragma once
#include "../../../ICEnum.h"
#include "../IVAMCSSegment.h"
class CObjManage;
class CSatellite;
class CMCSTargetSequence;
class ISatellite;
class IVAProfileCollection;
class IVAMCSSegmentCollection;

///
/// 瞄准序列段
///
class IATKOBJECT_API IVAMCSTargetSequence : public IVAMCSSegment
{
public:
    IVAMCSTargetSequence(const IVAMCSTargetSequence&) = delete;
    IVAMCSTargetSequence& operator=(const IVAMCSTargetSequence&) = delete;

	IVAMCSTargetSequence(CSatellite* pSate, ISatellite* pISate, CMCSTargetSequence* pcTargetSequence, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVAMCSTargetSequence();

	//void ApplyProfile(IVAProfile* pProfile);

	//********************************************************************
	/// 应用瞄准序列段属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strProfile   属性页名称，0 = DifferentialCorrector1，1 = DifferentialCorrector2，
	///									2 = SQPOptimizer，3 = EvolutionOptimizer
	/// @Return				
	//********************************************************************
	//void ApplyProfileByName(std::string strProfile);

	//********************************************************************
	/// 应用瞄准序列段所有属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return				
	//********************************************************************
	void ApplyProfiles();

	//********************************************************************
	/// 重置瞄准序列段属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strProfile   属性页名称，0 = DifferentialCorrector1，1 = DifferentialCorrector2，
	///									2 = SQPOptimizer，3 = EvolutionOptimizer
	/// @Return				
	//********************************************************************
	//void ResetProfileByName(std::string strProfile);

	//********************************************************************
	/// 重置瞄准序列段所有属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return				
	//********************************************************************
	void ResetProfiles();

	//********************************************************************
	/// 设置动作类型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eActionType 动作类型
	/// @Return	
	//********************************************************************
	void SetAction(EVATargetSeqAction eActionType);
	//********************************************************************
	/// 获得动作类型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	动作类型
	//********************************************************************
	EVATargetSeqAction GetAction();

	//********************************************************************
	/// 获得属性页属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	属性页指针
	//********************************************************************
	IVAProfileCollection* GetProfiles();

	//********************************************************************
	/// 获得段属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	段集合指针
	//********************************************************************
	IVAMCSSegmentCollection* GetSegments();

private:
	CObjManage*                  m_IAsGObjManage;
	CSatellite*                  m_pSate;
	ISatellite*                  m_pISate;
	CMCSTargetSequence*          m_pcTargetSequence;

	IVAProfileCollection*        m_Profiles;
	IVAMCSSegmentCollection*     m_Segments;   //对象集合

};
