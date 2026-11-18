#pragma once
#include "IVAProfile.h"
class CMCSTargetSequence;

///
/// 微分修正
///
class IATKOBJECT_API IVAProfileDifferentialCorrector : public IVAProfile
{
public:
    IVAProfileDifferentialCorrector(const IVAProfileDifferentialCorrector&) = delete;
    IVAProfileDifferentialCorrector& operator=(const IVAProfileDifferentialCorrector&) = delete;

	IVAProfileDifferentialCorrector(CMCSTargetSequence* pcTargetSequence, CAsShooterProfile* pCAsShoProf, IVAProfileCollection* pIProfileColl);
	~IVAProfileDifferentialCorrector();

	//void SetClearCorrectionsBeforeRun(bool bClear);
	//bool GetClearCorrectionsBeforeRun() { return m_ClearCorrectionsBeforeRun; }
};
