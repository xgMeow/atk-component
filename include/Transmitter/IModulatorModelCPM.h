#pragma once
#include "../IAtkObj.h"
#include "IModulatorModel.h"
class CTransmitter;

///
/// 调制器：CPM
///
class IATKOBJECT_API IModulatorModelCPM :public IModulatorModel
{
public:
    IModulatorModelCPM(const IModulatorModelCPM&) = delete;
    IModulatorModelCPM& operator=(const IModulatorModelCPM&) = delete;

	IModulatorModelCPM(CTransmitter* pCTransmitter);
	~IModulatorModelCPM();
};
