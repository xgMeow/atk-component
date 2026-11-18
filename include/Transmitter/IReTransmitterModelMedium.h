#pragma once
#include "../IAtkObj.h"
#include "IReTransmitterModel.h"
#include "../ICEnum.h"
#include <vector>
#include <string>
struct CObjData;
class CTransmitter;
class IPolarization;
class IRFFilterModel;

///
/// 转发发射器：中等转发器
///
class IATKOBJECT_API IReTransmitterModelMedium :public IReTransmitterModel
{
public:
    IReTransmitterModelMedium(const IReTransmitterModelMedium&) = delete;
    IReTransmitterModelMedium& operator=(const IReTransmitterModelMedium&) = delete;

	IReTransmitterModelMedium(CObjData* pCObjData);
	~IReTransmitterModelMedium();
	
	//********************************************************************
	/// 设置  功率
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	dSaturatedPower 功率
	//********************************************************************
	void SetSaturatedPower(double dSaturatedPower);

	//********************************************************************
	/// 获得 功率
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	功率
	//********************************************************************
	double GetSaturatedPower();
	
	//********************************************************************
	/// 设置 发射增益
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	dAntennaGain  发射增益
	//********************************************************************
	void SetAntennaGain(double dAntennaGain);

	//********************************************************************
	/// 获得 发射增益
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	发射增益
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
	IRFFilterModel*			m_Filter;						//滤波器

	CTransmitter*				m_CTransmitter;
};
