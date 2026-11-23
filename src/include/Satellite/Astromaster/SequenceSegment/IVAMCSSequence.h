#pragma once
#include "../../../ICEnum.h"
#include "../IVAMCSSegment.h"
class ISatellite;
class CObjManage;
class CSatellite;
class CMCSSequence;
class IVAMCSSegmentCollection;

///
/// 序列段
///
class IATKOBJECT_API IVAMCSSequence : public IVAMCSSegment
{
public:
    IVAMCSSequence(const IVAMCSSequence&) = delete;
    IVAMCSSequence& operator=(const IVAMCSSequence&) = delete;

	IVAMCSSequence(CSatellite* pSate, ISatellite* pISate, CMCSSequence* pcSequence, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVAMCSSequence();

	//********************************************************************
	/// 设置传递给下一段的状态
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eSeqStateToPass  传递给下一段的状态
	/// @Return	
	//********************************************************************
	void SetSequenceStateToPass(EVASequenceStateToPass eSeqStateToPass);
	//********************************************************************
	/// 获得传递给下一段的状态
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	传递给下一段的状态
	//********************************************************************
	EVASequenceStateToPass GetSequenceStateToPass();
		
	//********************************************************************
	/// 获得段属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	段指针
	//********************************************************************
	IVAMCSSegmentCollection* GetSegments();

private:
	CObjManage*                 m_IAsGObjManage;
	CSatellite*                 m_pSate;
	CMCSSequence*               m_pcSequence;
	ISatellite*                 m_pISate;

	IVAMCSSegmentCollection*    m_Segments;              //段属性

};
