#pragma once
#include "../IAtkObj.h"
#include "../ICEnum.h"
#include "IFmDefCompute.h" 

///
/// 品质因子定义：可见约束
///
class IATKOBJECT_API IFmDefAccessConstraint :public IFmDefCompute
{
public:
    IFmDefAccessConstraint(const IFmDefAccessConstraint&) = delete;
    IFmDefAccessConstraint& operator=(const IFmDefAccessConstraint&) = delete;

	IFmDefAccessConstraint(AsCvFmDefn* pAsCvFmDefn);
	~IFmDefAccessConstraint();

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
	/// 设置 约束类型
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @param[in]	eFmConstraint  约束类型
	//********************************************************************
	void SetConstraint(EFmConstraint eFmConstraint);

	//********************************************************************
	/// 获得  约束类型
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @return	 约束类型
	//********************************************************************
	EFmConstraint GetConstraint();

	//********************************************************************
	/// 设置 跨对象类型
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @param[in]	eFmAcrossAssets  跨对象类型
	//********************************************************************
	void SetAcrossAssets(EFmAcrossAssets eFmAcrossAssets);

	//********************************************************************
	/// 获得  跨对象类型
	/// @author	Gan Shu Long
	/// @date	2026-05-08
	/// @return	 跨对象类型
	//********************************************************************
	EFmAcrossAssets GetAcrossAssets();

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
	/// @date	2026-05-11
	/// @param[in]	eFmInvalidValueActionType  无效值类型
	//********************************************************************
	void SetInvalidValueAction(EFmInvalidValueActionType eFmInvalidValueActionType);

	//********************************************************************
	/// 获得  无效值类型
	/// @author	Gan Shu Long
	/// @date	2026-05-11
	/// @return	 无效值类型
	//********************************************************************
	EFmInvalidValueActionType GetInvalidValueAction();
};
