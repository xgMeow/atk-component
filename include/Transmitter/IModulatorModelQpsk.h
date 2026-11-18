#pragma once
#include "../IAtkObj.h"
#include "IModulatorModel.h"
class CTransmitter;

///
/// 调制器：Qpsk
///
class IATKOBJECT_API IModulatorModelQpsk :public IModulatorModel
{
public:
    IModulatorModelQpsk(const IModulatorModelQpsk&) = delete;
    IModulatorModelQpsk& operator=(const IModulatorModelQpsk&) = delete;

	IModulatorModelQpsk(CTransmitter* pCTransmitter);
	~IModulatorModelQpsk();
};
