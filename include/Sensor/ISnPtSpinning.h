#pragma once
#include "../IAtkObj.h"
#include "ISnPointing.h"
#include "../ICEnum.h"
struct CObjData;
class CSensor;

///
/// 指向：旋转
///
class IATKOBJECT_API ISnPtSpinning : public ISnPointing
{
public:
    ISnPtSpinning(const ISnPtSpinning&) = delete;
    ISnPtSpinning& operator=(const ISnPtSpinning&) = delete;

	ISnPtSpinning(CObjData* pCObjData);
	~ISnPtSpinning();

	//********************************************************************
	/// 设置 扫描模式
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @param[in]	eSnScanMode  扫描模式
	//********************************************************************
	void SetScanMode(ESnScanMode eSnScanMode);

	//********************************************************************
	/// 获得 扫描模式
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @return	double 扫描模式
	//********************************************************************
	ESnScanMode GetScanMode();

	//********************************************************************
	/// 设置 开始角
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @param[in]	dClockAngleStart  开始角
	//********************************************************************
	void SetClockAngleStart(double dClockAngleStart);

	//********************************************************************
	/// 获得 开始角
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @return	double 开始角
	//********************************************************************
	double GetClockAngleStart();

	//********************************************************************
	/// 设置 结束角
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @param[in]	dClockAngleStop  结束角
	//********************************************************************
	void SetClockAngleStop(double dClockAngleStop);

	//********************************************************************
	/// 获得 结束角
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @return	double 结束角
	//********************************************************************
	double GetClockAngleStop();

	//********************************************************************
	/// 设置 选择速度
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @param[in]	dSpinRate  选择速度
	//********************************************************************
	void SetSpinRate(double dSpinRate);

	//********************************************************************
	/// 获得 选择速度m_SenPtSpin
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @return	double 选择速度
	//********************************************************************
	double GetSpinRate();

	//********************************************************************
	/// 设置 初始偏差角
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @param[in]	dOffsetAngle  初始偏差角
	//********************************************************************
	void SetOffsetAngle(double dOffsetAngle);

	//********************************************************************
	/// 获得 初始偏差角
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @return	double 初始偏差角
	//********************************************************************
	double GetOffsetAngle();
	
	//********************************************************************
	/// 设置 方位角
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @param[in]	dSpinAxisAzimuth  方位角
	//********************************************************************
	void SetSpinAxisAzimuth(double dSpinAxisAzimuth);

	//********************************************************************
	/// 获得 方位角
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @return	double 方位角
	//********************************************************************
	double GetSpinAxisAzimuth();

	//********************************************************************
	/// 设置 高度角
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @param[in]	dSpinAxisElevation  高度角
	//********************************************************************
	void SetSpinAxisElevation(double dSpinAxisElevation);

	//********************************************************************
	/// 获得 高度角
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @return	double 高度角
	//********************************************************************
	double GetSpinAxisElevation();
	
	//********************************************************************
	/// 设置 圆锥角
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @param[in]	dSpinAxisConeAngle  圆锥角
	//********************************************************************
	void SetSpinAxisConeAngle(double dSpinAxisConeAngle);

	//********************************************************************
	/// 获得 圆锥角
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @return	double 圆锥角
	//********************************************************************
	double GetSpinAxisConeAngle();

private:
	CSensor*				m_pCSensor;
};
