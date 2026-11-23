#pragma once
#include "../IAtkObj.h" 
#include "../ICEnum.h"
struct CCRSystemNoiseTemperature;
class IAntennaNoiseTemperature;
///
/// 系统噪声温度
///
class IATKOBJECT_API ISystemNoiseTemperature
{
public:
    ISystemNoiseTemperature(const ISystemNoiseTemperature&) = delete;
    ISystemNoiseTemperature& operator=(const ISystemNoiseTemperature&) = delete;

	ISystemNoiseTemperature(CCRSystemNoiseTemperature* pCCRSystemNoiseTemperature);
	~ISystemNoiseTemperature();

	//********************************************************************
	/// 设置 计算类型
	/// @author	Gan Shu Long
	/// @date	2026-03-12
	/// @param[in]	eNoiseTempComputeType  计算类型
	//********************************************************************
	void SetComputeType(ENoiseTempComputeType eNoiseTempComputeType);

	//********************************************************************
	/// 获得 计算类型
	/// @author	Gan Shu Long
	/// @date	2026-03-12
	/// @return	计算类型
	//********************************************************************
	ENoiseTempComputeType GetComputeType();

	//********************************************************************
	/// 设置  常量
	/// @author	Gan Shu Long
	/// @date	2026-03-12
	/// @param[in]	dConstantNoiseTemperature 常量
	//********************************************************************
	void SetConstantNoiseTemperature(double dConstantNoiseTemperature);

	//********************************************************************
	/// 获得 常量
	/// @author	Gan Shu Long
	/// @date	2026-03-12
	/// @return	常量
	//********************************************************************
	double GetConstantNoiseTemperature();

	//********************************************************************
	/// 设置  天线到LNA传输线温度
	/// @author	Gan Shu Long
	/// @date	2026-03-12
	/// @param[in]	dAntennaToLnaLineTemperature 天线到LNA传输线温度
	//********************************************************************
	void SetAntennaToLnaLineTemperature(double dAntennaToLnaLineTemperature);

	//********************************************************************
	/// 获得 天线到LNA传输线温度
	/// @author	Gan Shu Long
	/// @date	2026-03-12
	/// @return	天线到LNA传输线温度
	//********************************************************************
	double GetAntennaToLnaLineTemperature();

	//********************************************************************
	/// 设置  LNA噪声系数
	/// @author	Gan Shu Long
	/// @date	2026-03-12
	/// @param[in]	dLnaNoiseFigure LNA噪声系数
	//********************************************************************
	void SetLnaNoiseFigure(double dLnaNoiseFigure);

	//********************************************************************
	/// 获得 LNA噪声系数
	/// @author	Gan Shu Long
	/// @date	2026-03-12
	/// @return	LNA噪声系数
	//********************************************************************
	double GetLnaNoiseFigure();

	//********************************************************************
	/// 设置  LNA温度
	/// @author	Gan Shu Long
	/// @date	2026-03-12
	/// @param[in]	dLnaTemperature LNA温度
	//********************************************************************
	void SetLnaTemperature(double dLnaTemperature);

	//********************************************************************
	/// 获得 LNA温度
	/// @author	Gan Shu Long
	/// @date	2026-03-12
	/// @return	LNA温度
	//********************************************************************
	double GetLnaTemperature();

	//********************************************************************
	/// 设置  LNA到接收机传输线温度
	/// @author	Gan Shu Long
	/// @date	2026-03-12
	/// @param[in]	dLnaToReceiverLineTemperature LNA到接收机传输线温度
	//********************************************************************
	void SetLnaToReceiverLineTemperature(double dLnaToReceiverLineTemperature);

	//********************************************************************
	/// 获得 LNA到接收机传输线温度
	/// @author	Gan Shu Long
	/// @date	2026-03-12
	/// @return	LNA到接收机传输线温度
	//********************************************************************
	double GetLnaToReceiverLineTemperature();

	//********************************************************************
	/// 获得 天线噪声温度
	/// @author	Gan Shu Long
	/// @date	2026-03-12
	/// @return	天线噪声温度
	//********************************************************************
	IAntennaNoiseTemperature* GetAntennaNoiseTemperature() { return m_AntennaNoiseTemperature; }
	
private:
	CCRSystemNoiseTemperature*		m_pCCRSystemNoiseTemperature;		//系统噪声温度结构体

	IAntennaNoiseTemperature*				m_AntennaNoiseTemperature;				//天线噪声温度
};
