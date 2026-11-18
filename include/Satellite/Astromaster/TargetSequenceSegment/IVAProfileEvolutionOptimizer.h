#pragma once
#include "IVAProfile.h"
class CMCSTargetSequence;

///
/// 智能优化算法
///
class IATKOBJECT_API IVAProfileEvolutionOptimizer : public IVAProfile
{
public:
    IVAProfileEvolutionOptimizer(const IVAProfileEvolutionOptimizer&) = delete;
    IVAProfileEvolutionOptimizer& operator=(const IVAProfileEvolutionOptimizer&) = delete;

	IVAProfileEvolutionOptimizer(CMCSTargetSequence* pcTargetSequence, CAsShooterProfile* pCAsShoProf, IVAProfileCollection* pIProfileColl);
	~IVAProfileEvolutionOptimizer();

	//void SetClearCorrectionsBeforeRun(bool bClear);
	//bool GetClearCorrectionsBeforeRun() { return m_ClearCorrectionsBeforeRun; }

};

