#pragma once
#include "../IAtkObj.h" 
#include "../ICEnum.h"
struct CCRAntennaNoise;

///
/// 天线噪声温度
///
class IATKOBJECT_API IAntennaNoiseTemperature
{
public:
    IAntennaNoiseTemperature(const IAntennaNoiseTemperature&) = delete;
    IAntennaNoiseTemperature& operator=(const IAntennaNoiseTemperature&) = delete;

	IAntennaNoiseTemperature(CCRAntennaNoise* pCCRAntennaNoise);
	~IAntennaNoiseTemperature();

	////********************************************************************
	///// 设置 计算类型
	///// @Author	Gan Shu Long
	///// @Date	2026-03-12
	///// @Input
	///// @Param	eNoiseTempComputeType  计算类型
	///// @Return	
	////********************************************************************
	//void SetComputeType(ENoiseTempComputeType eNoiseTempComputeType);

	////********************************************************************
	///// 获得 计算类型
	///// @Author	Gan Shu Long
	///// @Date	2026-03-12
	///// @Return	计算类型
	////********************************************************************
	//ENoiseTempComputeType GetComputeType();

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

private:
	CCRAntennaNoise*		m_pCCRAntennaNoise;		//天线噪声温度结构体
};
