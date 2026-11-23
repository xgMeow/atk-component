#pragma once
#include "IVAMCSSequence.h"
class CObjManage;
class CSatellite;
class CMCSBackwardSequence;

///
/// 逆向序列段
///
class IATKOBJECT_API IVAMCSBackwardSequence : public IVAMCSSequence
{
public:
    IVAMCSBackwardSequence(const IVAMCSBackwardSequence&) = delete;
    IVAMCSBackwardSequence& operator=(const IVAMCSBackwardSequence&) = delete;

	IVAMCSBackwardSequence(CSatellite* pSate, ISatellite* pISate, CMCSBackwardSequence* pcBackwardSequence, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVAMCSBackwardSequence();

private:
	CMCSBackwardSequence*     m_pCMCSBackwardSequence;

};
