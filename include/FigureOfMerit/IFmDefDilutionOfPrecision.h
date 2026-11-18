#pragma once
#include "../IAtkObj.h"
#include "../ICEnum.h"
#include "IFmDefCompute.h" 
#include <vector>
#include <string>

///
/// 品质因子定义：精度衰减因子
///
class IATKOBJECT_API IFmDefDilutionOfPrecision :public IFmDefCompute
{
public:
    IFmDefDilutionOfPrecision(const IFmDefDilutionOfPrecision&) = delete;
    IFmDefDilutionOfPrecision& operator=(const IFmDefDilutionOfPrecision&) = delete;

	IFmDefDilutionOfPrecision(AsCvFmDefn* pAsCvFmDefn);
	~IFmDefDilutionOfPrecision();

	//********************************************************************
	/// 获得 支持的计算类型
	/// @author	Gan Shu Long
	/// @date	2026-05-11
	/// @return 支持的计算类型
	//********************************************************************
	std::vector<std::string> GetComputeSupportedTypes() override;

	//********************************************************************
	/// 获得 是否支持计算类型
	/// @author	Gan Shu Long
	/// @date	2026-05-11
	/// @param[in]	eFmCompute  计算类型
	/// @return	bool 是否支持计算类型	
	//********************************************************************
	bool IsComputeTypeSupported(EFmCompute eFmCompute) override;

	//********************************************************************
	/// 获得 支持的方法类型
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @return 支持的方法类型
	//********************************************************************
	std::vector<std::string> GetSupportedMethods();

	//********************************************************************
	/// 获得 是否支持方法类型
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @param[in]	eFmMethod  方法类型
	/// @return	bool 是否支持方法类型	
	//********************************************************************
	bool IsMethodTypeSupported(EFmMethod eFmMethod);

	//********************************************************************
	/// 设置 方法类型
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @param[in]	eFmMethod  方法类型
	//********************************************************************
	void SetMethod(EFmMethod eFmMethod);

	//********************************************************************
	/// 获得  方法类型
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @return	 方法类型
	//********************************************************************
	EFmMethod GetMethod();

	//********************************************************************
	/// 获得 支持的类型
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @return 支持的类型
	//********************************************************************
	std::vector<std::string> GetSupportedTypes();

	//********************************************************************
	/// 获得 是否支持类型
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @param[in]	eFmComputeType  类型
	/// @return	bool 是否支持类型	
	//********************************************************************
	bool IsTypeSupported(EFmComputeType eFmComputeType);

	//********************************************************************
	/// 设置 类型
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @param[in]	eFmComputeType  类型
	//********************************************************************
	void SetType(EFmComputeType eFmComputeType);

	//********************************************************************
	/// 获得  类型
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @return	 类型
	//********************************************************************
	EFmComputeType GetType();

	//********************************************************************
	/// 设置 步长
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @param[in]	dTimeStep  步长
	//********************************************************************
	void SetTimeStep(double dTimeStep);

	//********************************************************************
	/// 获得  步长
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @return	 步长
	//********************************************************************
	double GetTimeStep();

	//********************************************************************
	/// 设置 无效值类型
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @param[in]	eFmInvalidValueActionType  无效值类型
	//********************************************************************
	void SetInvalidValueAction(EFmInvalidValueActionType eFmInvalidValueActionType);

	//********************************************************************
	/// 获得  无效值类型
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @return	 无效值类型
	//********************************************************************
	EFmInvalidValueActionType GetInvalidValueAction();
};
