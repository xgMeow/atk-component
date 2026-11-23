#pragma once
#include "../IAtkObj.h"
#include "ITransmitterModel.h"
#include "../ICEnum.h"
struct CObjData;
class CTransmitter;
class ITransferFunctionPolynomialCollection;

///
/// 转发发射器：基类
///
class IATKOBJECT_API IReTransmitterModel :public ITransmitterModel
{
public:
    IReTransmitterModel(const IReTransmitterModel&) = delete;
    IReTransmitterModel& operator=(const IReTransmitterModel&) = delete;

	IReTransmitterModel(CObjData* pCObjData);
	~IReTransmitterModel();
	
	//********************************************************************
	/// 设置  饱和通量密度单位dBW/m^2
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	dSaturatedFluxDensity 饱和通量密度单位dBW/m^2
	//********************************************************************
	void SetSaturatedFluxDensity(double dSaturatedFluxDensity);

	//********************************************************************
	/// 获得 饱和通量密度单位dBW/m^2
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	饱和通量密度单位dBW/m^2
	//********************************************************************
	double GetSaturatedFluxDensity();
	
	//********************************************************************
	/// 获得 转换方法输入频率
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	转换方法输入频率
	//********************************************************************
	ITransferFunctionPolynomialCollection* GetFrequencyTransferFunctionPolynomial() { return m_FrequencyTransferFunctionPolynomial; }

	//********************************************************************
	/// 获得 转换方法功率回退
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	转换方法功率回退
	//********************************************************************
	ITransferFunctionPolynomialCollection* GetPowerBackOffTransferFunctionPolynomial() { return m_PowerBackOffTransferFunctionPolynomial; }

private:
	CTransmitter*												m_CTransmitter;
	ITransferFunctionPolynomialCollection*		m_FrequencyTransferFunctionPolynomial;			//转换方法输入频率
	ITransferFunctionPolynomialCollection*		m_PowerBackOffTransferFunctionPolynomial;		//转换方法功率回退
};
