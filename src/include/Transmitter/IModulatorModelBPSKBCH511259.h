#pragma once
#include "../IAtkObj.h"
#include "IModulatorModel.h"
class CTransmitter;

///
/// 调制器：BPSKBCH511259
///
class IATKOBJECT_API IModulatorModelBPSKBCH511259 :public IModulatorModel
{
public:
    IModulatorModelBPSKBCH511259(const IModulatorModelBPSKBCH511259&) = delete;
    IModulatorModelBPSKBCH511259& operator=(const IModulatorModelBPSKBCH511259&) = delete;

	IModulatorModelBPSKBCH511259(CTransmitter* pCTransmitter);
	~IModulatorModelBPSKBCH511259();
};
