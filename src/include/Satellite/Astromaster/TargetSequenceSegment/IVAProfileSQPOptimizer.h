#pragma once
#include "IVAProfile.h"
class CMCSTargetSequence;

///
/// 序列二次规划
///
class IATKOBJECT_API IVAProfileSQPOptimizer : public IVAProfile
{
public:
    IVAProfileSQPOptimizer(const IVAProfileSQPOptimizer&) = delete;
    IVAProfileSQPOptimizer& operator=(const IVAProfileSQPOptimizer&) = delete;

	IVAProfileSQPOptimizer(CMCSTargetSequence* pcTargetSequence, CAsShooterProfile* pCAsShoProf, IVAProfileCollection* pIProfileColl);
	~IVAProfileSQPOptimizer();

	//void SetClearCorrectionsBeforeRun(bool bClear);
	//bool GetClearCorrectionsBeforeRun() { return m_ClearCorrectionsBeforeRun; }
};

