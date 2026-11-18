#pragma once
#include "../IAtkObj.h"
#include "IModulatorModel.h"
class CTransmitter;

///
/// 调制器：BPSKConv438
///
class IATKOBJECT_API IModulatorModelBPSKConv438 :public IModulatorModel
{
public:
    IModulatorModelBPSKConv438(const IModulatorModelBPSKConv438&) = delete;
    IModulatorModelBPSKConv438& operator=(const IModulatorModelBPSKConv438&) = delete;

	IModulatorModelBPSKConv438(CTransmitter* pCTransmitter);
	~IModulatorModelBPSKConv438();
};
