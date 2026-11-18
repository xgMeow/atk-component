#pragma once
#include "../IAtkObj.h"
#include "IReceiverModel.h"
#include "../ICEnum.h"
#include <vector>
#include <string>
class CReceiver;
class IPolarization;
class IDemodulatorModel;
class IRFFilterModel;

///
/// 简单接收模型
///
class IATKOBJECT_API IReceiverModelSimple :public IReceiverModel
{
public:
    IReceiverModelSimple(const IReceiverModelSimple&) = delete;
    IReceiverModelSimple& operator=(const IReceiverModelSimple&) = delete;

	IReceiverModelSimple(CReceiver* pCReceiver);
	~IReceiverModelSimple();
	
	//********************************************************************
	/// 获得 接收类型名称
	/// @author	Gan Shu Long
	/// @date	2026-03-10
	/// @return	接收类型名称
	//********************************************************************
	std::string GetName() { return "Simple Receiver Model"; }

	//********************************************************************
	/// 获得 接收类型类型
	/// @author	Gan Shu Long
	/// @date	2026-03-10
	/// @return	接收类型类型
	//********************************************************************
	EReceiverModelType GetType() { return eReceiverModelTypeSimple; }
	
	//********************************************************************
	/// 设置 频率
	/// @author	Gan Shu Long
	/// @date	2026-03-10
	/// @param[in]	frequency 新值
	//********************************************************************
	void SetFrequency(double frequency);

	//********************************************************************
	/// 获得 频率
	/// @author	Gan Shu Long
	/// @date	2026-03-10
	/// @return	频率
	//********************************************************************
	double GetFrequency();

	//********************************************************************
	/// 设置 是否自动识别频率
	/// @author	Gan Shu Long
	/// @date	2026-03-10
	/// @param[in]	bAutoTrackFrequency  是否自动识别频率
	//********************************************************************
	void SetAutoTrackFrequency(bool bAutoTrackFrequency);

	//********************************************************************
	/// 获得 是否自动识别频率
	/// @author	Gan Shu Long
	/// @date	2026-03-10
	/// @return	是否自动识别频率
	//********************************************************************
	bool GetAutoTrackFrequency();

	//********************************************************************
	/// 设置 品质因子
	/// @author	Gan Shu Long
	/// @date	2026-03-10
	/// @param[in]	gOverT 新值
	//********************************************************************
	void SetGOverT(double gOverT);

	//********************************************************************
	/// 获得 品质因子
	/// @author	Gan Shu Long
	/// @date	2026-03-10
	/// @return	品质因子
	//********************************************************************
	double GetGOverT();

	//********************************************************************
	/// 设置 是否使用天线极化
	/// @author	Gan Shu Long
	/// @date	2026-03-10
	/// @param[in]	bEnablePolarization  是否使用天线极化
	//********************************************************************
	void SetEnablePolarization(bool bEnablePolarization);

	//********************************************************************
	/// 获得 是否使用天线极化
	/// @author	Gan Shu Long
	/// @date	2026-03-10
	/// @return	是否使用天线极化
	//********************************************************************
	bool GetEnablePolarization();

	//********************************************************************
	/// 设置 天线极化类型 (子类之间类型转换，子类成员值不变)
	/// @author	Gan Shu Long
	/// @date	2026-03-10
	/// @param[in]	newType  天线极化类型
	//********************************************************************
	void SetPolarizationType(EPolarizationType newType);

	//********************************************************************
	/// 获得 天线极化类型
	/// @author	Gan Shu Long
	/// @date	2026-03-10
	/// @return	天线极化类型
	//********************************************************************
	EPolarizationType GetPolarizationType();
	
	//********************************************************************
	/// 获得 天线极化
	/// @author	Gan Shu Long
	/// @date	2026-03-10
	/// @return	天线极化
	//********************************************************************
	IPolarization* GetPolarization() { return m_Polarization; }
	
	//********************************************************************
	/// 设置 是否自动设置调解
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @param[in]	bAutoSelectDemodulator  是否自动设置调解
	//********************************************************************
	void SetAutoSelectDemodulator(bool bAutoSelectDemodulator);

	//********************************************************************
	/// 获得 是否自动设置调解
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	是否自动设置调解
	//********************************************************************
	bool GetAutoSelectDemodulator();

	//********************************************************************
	/// 获得 支持的解调器类型
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return 支持的解调器类型
	//********************************************************************
	std::vector<std::string> GetSupportedDemodulators();

	//********************************************************************
	/// 按名称设置当前解调器类型
	/// @author	Gan Shu Long
	/// @date	2026-03-10
	/// @param[in]	demodulatorName  解调器类型名称
	//********************************************************************
	void SetDemodulator(std::string demodulatorName);

	//********************************************************************
	/// 获得  解调器
	/// @author	Gan Shu Long
	/// @date	2026-03-10
	/// @return	 解调器
	//********************************************************************
	IDemodulatorModel* GetDemodulator() { return m_Demodulator; }
	
	//********************************************************************
	/// 设置  带宽
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @param[in]	dBandwidth 带宽
	//********************************************************************
	void SetBandwidth(double dBandwidth);

	//********************************************************************
	/// 获得 带宽
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	带宽
	//********************************************************************
	double GetBandwidth();

	//********************************************************************
	/// 设置 是否自动调整带宽
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @param[in]	bAutoScaleBandwidth  是否自动调整带宽
	//********************************************************************
	void SetAutoScaleBandwidth(bool bAutoScaleBandwidth);

	//********************************************************************
	/// 获得 是否自动调整带宽
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	是否自动调整带宽
	//********************************************************************
	bool GetAutoScaleBandwidth();

	//********************************************************************
	/// 设置 是否使用滤波器
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @param[in]	bEnableFilter  是否使用滤波器
	//********************************************************************
	void SetEnableFilter(bool bEnableFilter);

	//********************************************************************
	/// 获得 是否使用滤波器
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	是否使用滤波器
	//********************************************************************
	bool GetEnableFilter();

	//********************************************************************
	/// 获得 支持的滤波器类型
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return 支持的滤波器类型
	//********************************************************************
	std::vector<std::string> GetSupportedFilters();
	
	//********************************************************************
	/// 按名称设置当前滤波器类型
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @param[in]	strFilterName  滤波器类型名称
	//********************************************************************
	void SetFilter(std::string strFilterName);

	//********************************************************************
	/// 获得  滤波器
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	 滤波器
	//********************************************************************
	IRFFilterModel* GetFilter() { return m_Filter; }

	//********************************************************************
	/// 设置  接收机额外损益
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @param[in]	dGain 接收机额外损益
	//********************************************************************
	void SetGain(double dGain);

	//********************************************************************
	/// 获得 接收机额外损益
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	接收机额外损益
	//********************************************************************
	double GetGain();

private:
	//********************************************************************
	/// 获得 解调器类型字符串
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @param[in]	eDemodulatorModelType  解调器类型
	/// @return 解调器类型字符串
	//********************************************************************
	std::string DemodulatorTypeToStr(EDemodulatorModelType eDemodulatorModelType);

	//********************************************************************
	/// 获得 滤波器类型字符串
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @param[in]	eRFFilterModelType 滤波器类型
	/// @return 滤波器类型字符串
	//********************************************************************
	std::string FilterTypeToStr(ERFFilterModelType eRFFilterModelType);

private:
	CReceiver*						m_CReceiver;				//保存一份C对象实例，省的每次改动时都需要重新便利寻找

	IPolarization*					m_Polarization;			//天线极化
	IDemodulatorModel*		m_Demodulator;			//解调器
	IRFFilterModel*				m_Filter;						//滤波器
};
