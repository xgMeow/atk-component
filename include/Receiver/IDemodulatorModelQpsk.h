#pragma once
#include "../IAtkObj.h"
#include "IDemodulatorModel.h"

///
/// 解调器模型QPSK
///
class IATKOBJECT_API IDemodulatorModelQpsk :public IDemodulatorModel
{
public:
    IDemodulatorModelQpsk(const IDemodulatorModelQpsk&) = delete;
    IDemodulatorModelQpsk& operator=(const IDemodulatorModelQpsk&) = delete;

	IDemodulatorModelQpsk();
	~IDemodulatorModelQpsk();

	//********************************************************************
	/// 获得 解调器模型名称
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	解调器模型名称
	//********************************************************************
	std::string GetName() { return "QPSK"; }

	//********************************************************************
	/// 获得 解调器模型类型
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	解调器模型类型
	//********************************************************************
	EDemodulatorModelType GetType() { return eDemodulatorModelTypeQPSK; }
};
