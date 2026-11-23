#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOSetInitialState;

///
/// RPOSetInitialState
///
class IATKOBJECT_API IVARPOSetInitialState : public IVAMCSRPOSegment
{
public:
    IVARPOSetInitialState(const IVARPOSetInitialState&) = delete;
    IVARPOSetInitialState& operator=(const IVARPOSetInitialState&) = delete;

	IVARPOSetInitialState(CSatellite* pSate, CRPOSetInitialState* pcRPOSetInitialState, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOSetInitialState();
};

