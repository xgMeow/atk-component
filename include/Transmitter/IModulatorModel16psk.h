#pragma once
#include "../IAtkObj.h"
#include "IModulatorModel.h"
class CTransmitter;

///
/// 调制器：16psk
///
class IATKOBJECT_API IModulatorModel16psk :public IModulatorModel
{
public:
    IModulatorModel16psk(const IModulatorModel16psk&) = delete;
    IModulatorModel16psk& operator=(const IModulatorModel16psk&) = delete;

	IModulatorModel16psk(CTransmitter* pCTransmitter);
	~IModulatorModel16psk();
};
