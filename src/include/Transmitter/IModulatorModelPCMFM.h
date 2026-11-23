#pragma once
#include "../IAtkObj.h"
#include "IModulatorModel.h"
class CTransmitter;

///
/// 调制器：PCMFM
///
class IATKOBJECT_API IModulatorModelPCMFM :public IModulatorModel
{
public:
    IModulatorModelPCMFM(const IModulatorModelPCMFM&) = delete;
    IModulatorModelPCMFM& operator=(const IModulatorModelPCMFM&) = delete;

	IModulatorModelPCMFM(CTransmitter* pCTransmitter);
	~IModulatorModelPCMFM();
};
