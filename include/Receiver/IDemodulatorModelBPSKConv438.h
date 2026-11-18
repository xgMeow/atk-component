#pragma once
#include "../IAtkObj.h"
#include "IDemodulatorModel.h"

///
/// 解调器模型 BPSKConv_4_3_8
///
class IATKOBJECT_API IDemodulatorModelBPSKConv438 :public IDemodulatorModel
{
public:
    IDemodulatorModelBPSKConv438(const IDemodulatorModelBPSKConv438&) = delete;
    IDemodulatorModelBPSKConv438& operator=(const IDemodulatorModelBPSKConv438&) = delete;

	IDemodulatorModelBPSKConv438();
	~IDemodulatorModelBPSKConv438();

	//********************************************************************
	/// 获得 解调器模型名称
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	解调器模型名称
	//********************************************************************
	std::string GetName() { return "BPSKConv_4_3_8"; }

	//********************************************************************
	/// 获得 解调器模型类型
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	解调器模型类型
	//********************************************************************
	EDemodulatorModelType GetType() { return eDemodulatorModelTypeBPSKConv_4_3_8; }
};
