#pragma once
#include "../IAtkObj.h"
#include "ITransmitterModel.h"
#include "../ICEnum.h"
#include <vector>
#include <string>
class CTransmitter;
class IPolarization;
class IModulatorModel;
class IRFFilterModel;

///
/// 发射器模型：中等发射器
///
class IATKOBJECT_API ITransmitterModelMedium :public ITransmitterModel
{
public:
    ITransmitterModelMedium(const ITransmitterModelMedium&) = delete;
    ITransmitterModelMedium& operator=(const ITransmitterModelMedium&) = delete;

	ITransmitterModelMedium(CTransmitter* pCTransmitter);
	~ITransmitterModelMedium();
	
	//********************************************************************
	/// 设置  频率
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	dFrequency 频率
	//********************************************************************
	void SetFrequency(double dFrequency);

	//********************************************************************
	/// 获得 频率
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	频率
	//********************************************************************
	double GetFrequency();

	//********************************************************************
	/// 设置  数据速率
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	dDataRate 数据速率
	//********************************************************************
	void SetDataRate(double dDataRate);
	
	//********************************************************************
	/// 获得 数据速率
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	数据速率
	//********************************************************************
	double GetDataRate();

	//********************************************************************
	/// 设置  功率
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	dPower 功率
	//********************************************************************
	void SetPower(double dPower);
		
	//********************************************************************
	/// 获得 功率
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	功率
	//********************************************************************
	double GetPower();

	//********************************************************************
	/// 设置  增益
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	dAntennaGain 增益
	//********************************************************************
	void SetAntennaGain(double dAntennaGain);

	//********************************************************************
	/// 获得 增益
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	增益
	//********************************************************************
	double GetAntennaGain();

	//********************************************************************
	/// 设置 是否使用天线极化
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	bEnablePolarization  是否使用天线极化
	//********************************************************************
	void SetEnablePolarization(bool bEnablePolarization);

	//********************************************************************
	/// 获得 是否使用天线极化
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	是否使用天线极化
	//********************************************************************
	bool GetEnablePolarization();

	//********************************************************************
	/// 设置 天线极化类型 (子类之间类型转换，子类成员值不变)
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	ePolarizationType  天线极化类型
	//********************************************************************
	void SetPolarizationType(EPolarizationType ePolarizationType);

	//********************************************************************
	/// 获得 天线极化类型
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	天线极化类型
	//********************************************************************
	EPolarizationType GetPolarizationType();

	//********************************************************************
	/// 获得 天线极化
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	天线极化
	//********************************************************************
	IPolarization* GetPolarization() { return m_Polarization; }
	
	//********************************************************************
	/// 获得 支持的调制器模型名称
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return 支持的调制器模型名称
	//********************************************************************
	std::vector<std::string> GetSupportedModulators();

	//********************************************************************
	/// 按名称设置 调制器模型
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	strModulatorName  调制器模型名称
	//********************************************************************
	void SetModulator(std::string strModulatorName);

	//********************************************************************
	/// 设置 调制器模型类型
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	eModulatorModelType  调制器模型类型
	//********************************************************************
	void SetModulatorModelType(EModulatorModelType eModulatorModelType);

	//********************************************************************
	/// 获得 调制器模型类型
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	调制器模型类型
	//********************************************************************
	EModulatorModelType GetModulatorModelType();

	//********************************************************************
	/// 获得 调制器模型
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	调制器模型
	//********************************************************************
	IModulatorModel* GetModulator() { return m_Modulator; }
	
	//********************************************************************
	/// 设置 是否使用滤波器
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	bEnableFilter  是否使用滤波器
	//********************************************************************
	void SetEnableFilter(bool bEnableFilter);

	//********************************************************************
	/// 获得 是否使用滤波器
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	是否使用滤波器
	//********************************************************************
	bool GetEnableFilter();

	//********************************************************************
	/// 获得 支持的滤波器类型
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return 支持的滤波器类型
	//********************************************************************
	std::vector<std::string> GetSupportedFilters();

	//********************************************************************
	/// 按名称设置当前滤波器类型
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	strFilterName  滤波器类型名称
	//********************************************************************
	void SetFilter(std::string strFilterName);

	//********************************************************************
	/// 设置 滤波器类型
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	eRFFilterModelType  滤波器类型
	//********************************************************************
	void SetFilterModelType(ERFFilterModelType eRFFilterModelType);

	//********************************************************************
	/// 获得 滤波器类型
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	滤波器类型
	//********************************************************************
	ERFFilterModelType GetFilterModelType();

	//********************************************************************
	/// 获得  滤波器
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	 滤波器
	//********************************************************************
	IRFFilterModel* GetFilter() { return m_Filter; }

	//********************************************************************
	/// 设置  发射机额外损益dB
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	dPostTransmitGainsLosses 发射机额外损益dB
	//********************************************************************
	void SetPostTransmitGainsLosses(double dPostTransmitGainsLosses);

	//********************************************************************
	/// 获得 发射机额外损益dB
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	发射机额外损益dB
	//********************************************************************
	double GetPostTransmitGainsLosses();

private:
	IPolarization*				m_Polarization;			//天线极化
	IModulatorModel*			m_Modulator;				//调制器
	IRFFilterModel*			m_Filter;						//滤波器

	CTransmitter*				m_CTransmitter;
};
