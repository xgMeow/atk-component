#pragma once
#include "../IAtkObj.h"
#include "IDemodulatorModel.h"

///
/// 解调器模型 8PSK
///
class IATKOBJECT_API IDemodulatorModel8PSK :public IDemodulatorModel
{
public:
    IDemodulatorModel8PSK(const IDemodulatorModel8PSK&) = delete;
    IDemodulatorModel8PSK& operator=(const IDemodulatorModel8PSK&) = delete;

	IDemodulatorModel8PSK();
	~IDemodulatorModel8PSK();

	//********************************************************************
	/// 获得 解调器模型名称
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	解调器模型名称
	//********************************************************************
	std::string GetName() { return "8PSK"; }

	//********************************************************************
	/// 获得 解调器模型类型
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	解调器模型类型
	//********************************************************************
	EDemodulatorModelType GetType() { return eDemodulatorModelType8psk; }
};
