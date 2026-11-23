#pragma once
#include "../IAtkObj.h"
#include "ISnSimpleConicPattern.h"
#include "ISnRectangularPattern.h"
#include "ISnPtFixed.h"
#include "../ICEnum.h"
class ISensor;
class CSensor;
class CObjManage;

///
/// 常用任务
///
class IATKOBJECT_API ISnCommonTasks
{
public:
    ISnCommonTasks(const ISnCommonTasks&) = delete;
    ISnCommonTasks& operator=(const ISnCommonTasks&) = delete;

	ISnCommonTasks(ISensor* pISensor, CSensor* pCSensor, CObjManage* IAsGObjManage);
	~ISnCommonTasks();

	//********************************************************************
	/// 设置 圆锥传感器，返回指针，改变返回值，源数据也会跟着改变
	/// @author	Gan Shu Long
	/// @date	2023-11-27
	/// @param[in]	coneAngle 半锥角
	/// @param[in]	angularResolution 点之间的角分离
	/// @return	ISnSimpleConicPattern*  圆锥传感器类型指针
	//********************************************************************
	ISnSimpleConicPattern* SetPatternSimpleConic(double coneAngle, double angularResolution);

	//********************************************************************
	/// 设置 矩形传感器，返回指针，改变返回值，源数据也会跟着改变
	/// @author	Gan Shu Long
	/// @date	2023-11-27
	/// @param[in]	verticalHalfAngle 垂直半推角
	/// @param[in]	horizontalHalfAngle 水平半推角
	/// @return	ISnRectangularPattern*  矩形传感器类型指针
	//********************************************************************
	ISnRectangularPattern* SetPatternRectangular(double verticalHalfAngle, double horizontalHalfAngle);

	//********************************************************************
	/// 设置 固定欧拉值角度，返回指针，改变返回值，源数据也会跟着改变
	/// @author	Gan Shu Long
	/// @date	2023-11-27
	/// @param[in]	sequence  欧拉角序列
	/// @param[in]	a	欧拉角a
	/// @param[in]	b	欧拉角b
	/// @param[in]	c	欧拉角c
	/// @return	ISnPtFixed* 固定指向指针
	ISnPtFixed* SetPointingFixedEuler(EEulerOrientationSequence sequence, double a, double b, double c);

	//********************************************************************
	/// 设置 固定四元数角度，返回指针，改变返回值，源数据也会跟着改变
	/// @author	Gan Shu Long
	/// @date	2023-11-27
	/// @param[in]	x  四元数x
	/// @param[in]	y  四元数y
	/// @param[in]	z  四元数z
	/// @param[in]	s  四元数s
	/// @return	ISnPtFixed* 固定指向指针
	ISnPtFixed* SetPointingFixedQuat(double x, double y, double z, double s);

private:
	ISensor* m_pISensor;
	
	CObjManage* m_IAsGObjManage;
	CSensor* m_pCSensor;
};

