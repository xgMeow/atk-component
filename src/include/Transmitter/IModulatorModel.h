#pragma once
#include "../IAtkObj.h"
#include <string>
#include "../ICEnum.h"
#include "../IClassInfo.h"
class CTransmitter;

///
/// 调制器：基类
///
class IATKOBJECT_API IModulatorModel :public IClassInfo
{
public:
    IModulatorModel(const IModulatorModel&) = delete;
    IModulatorModel& operator=(const IModulatorModel&) = delete;

	IModulatorModel(CTransmitter* pCTransmitte);
	virtual ~IModulatorModel();
	
	//********************************************************************
	/// 获得 调制器名称
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	调制器名称
	//********************************************************************
	std::string GetName() { return m_Name; }

	//********************************************************************
	/// 获得 调制器类型
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	调制器类型
	//********************************************************************
	EModulatorModelType GetType() { return m_Type; }
	
	//********************************************************************
	/// 设置 是否选择信号PSD
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	bEnableSignalPSD  是否选择信号
	//********************************************************************
	void SetEnableSignalPSD(bool bEnableSignalPSD);

	//********************************************************************
	/// 获得 是否选择信号
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	是否选择信号
	//********************************************************************
	bool GetEnableSignalPSD();

	//********************************************************************
	/// 设置  空频谱数量
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	nPSDLimitMultiplier 空频谱数量
	//********************************************************************
	void SetPSDLimitMultiplier(int nPSDLimitMultiplier);

	//********************************************************************
	/// 获得 空频谱数量
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	空频谱数量
	//********************************************************************
	int GetPSDLimitMultiplier();

	//********************************************************************
	/// 设置 是否使用自动调整带宽标识
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	bAutoScaleBandwidth  是否使用自动调整带宽标识
	//********************************************************************
	void SetAutoScaleBandwidth(bool bAutoScaleBandwidth);

	//********************************************************************
	/// 获得 是否使用自动调整带宽标识
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	是否使用自动调整带宽标识
	//********************************************************************
	bool GetAutoScaleBandwidth();

	//********************************************************************
	/// 设置 是否使用对称调节标识
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	bSymmetricBandwidth  是否使用对称调节标识
	//********************************************************************
	void SetSymmetricBandwidth(bool bSymmetricBandwidth);

	//********************************************************************
	/// 获得 是否使用对称调节标识
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	是否使用对称调节标识
	//********************************************************************
	bool GetSymmetricBandwidth();

	//********************************************************************
	/// 设置  带宽上限单位MHz
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	dUpperBandwidthLimit 带宽上限单位MHz
	//********************************************************************
	void SetUpperBandwidthLimit(double dUpperBandwidthLimit);

	//********************************************************************
	/// 获得 带宽上限单位MHz
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	带宽上限单位MHz
	//********************************************************************
	double GetUpperBandwidthLimit();

	//********************************************************************
	/// 设置  带宽下限单位MHz
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	dLowerBandwidthLimit 带宽下限单位MHz
	//********************************************************************
	void SetLowerBandwidthLimit(double dLowerBandwidthLimit);

	//********************************************************************
	/// 获得 带宽下限单位MHz
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	带宽下限单位MHz
	//********************************************************************
	double GetLowerBandwidthLimit();

	//********************************************************************
	/// 设置  带宽单位MHz
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	dBandwidth  带宽单位MHz
	//********************************************************************
	void SetBandwidth(double dBandwidth);

	//********************************************************************
	/// 获得  带宽单位MHz
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	 带宽单位MHz
	//********************************************************************
	double GetBandwidth();

protected:
	std::string						m_Name;			//模型名称
	EModulatorModelType		m_Type;				//模型类型

private:
	CTransmitter*					m_CTransmitter;
};
