#pragma once
#include "../IAtkObj.h"
#include "IModulatorModel.h"
class CTransmitter;

///
/// 调制器：8psk
///
class IATKOBJECT_API IModulatorModel8psk :public IModulatorModel
{
public:
    IModulatorModel8psk(const IModulatorModel8psk&) = delete;
    IModulatorModel8psk& operator=(const IModulatorModel8psk&) = delete;

	IModulatorModel8psk(CTransmitter* pCTransmitter);
	~IModulatorModel8psk();
};
