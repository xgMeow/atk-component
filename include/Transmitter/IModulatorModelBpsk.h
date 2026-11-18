#pragma once
#include "../IAtkObj.h"
#include "IModulatorModel.h"
class CTransmitter;

///
/// 调制器：Bpsk
///
class IATKOBJECT_API IModulatorModelBpsk :public IModulatorModel
{
public:
    IModulatorModelBpsk(const IModulatorModelBpsk&) = delete;
    IModulatorModelBpsk& operator=(const IModulatorModelBpsk&) = delete;

	IModulatorModelBpsk(CTransmitter* pCTransmitter);
	~IModulatorModelBpsk();
};
