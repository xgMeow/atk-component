#pragma once
#include "../IAtkObj.h"
#include "IRFFilterModel.h" 
#include "../ICEnum.h"
struct CCRFilter;

///
/// 滤波器 RaisedCosine
///
class IATKOBJECT_API IRFFilterModelRaisedCosine :public IRFFilterModel
{
public:
    IRFFilterModelRaisedCosine(const IRFFilterModelRaisedCosine&) = delete;
    IRFFilterModelRaisedCosine& operator=(const IRFFilterModelRaisedCosine&) = delete;

	IRFFilterModelRaisedCosine(CCRFilter* pCCRFilter);
	virtual ~IRFFilterModelRaisedCosine();

	//********************************************************************
	/// 获得 滤波器名称
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	滤波器名称
	//********************************************************************
	std::string GetName() { return "RaisedCosine"; }

	//********************************************************************
	/// 获得 滤波器类型
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	滤波器类型
	//********************************************************************
	ERFFilterModelType GetType() { return eRFFilterModelTypeRaisedCosine; }
																	

	//********************************************************************
	/// 设置  滚降因子
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @param[in]	dRollOffFactor 滚降因子
	//********************************************************************
	void SetRollOffFactorr(double dRollOffFactor);

	//********************************************************************
	/// 获得 滚降因子
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	滚降因子
	//********************************************************************
	double GetRollOffFactor();

	//********************************************************************
	/// 设置  符号率
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @param[in]	dSymbolRate 符号率
	//********************************************************************
	void SetSymbolRate(double dSymbolRate);

	//********************************************************************
	/// 获得 符号率
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	符号率
	//********************************************************************
	double GetSymbolRate();

private:
	CCRFilter*			 m_pCCRFilter;		//滤波器结构体
};
