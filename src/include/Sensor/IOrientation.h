#pragma once
#include "../IAtkObj.h"
#include "../IClassInfo.h"
#include "../ICEnum.h"
struct CObjData;
class CQuaternion;

///
/// 指向固定属性
///
class IATKOBJECT_API IOrientation :public IClassInfo
{
public:
    IOrientation(const IOrientation&) = delete;
    IOrientation& operator=(const IOrientation&) = delete;

	IOrientation(CObjData* pCObjData);
	virtual ~IOrientation();

	//********************************************************************
	/// 按方位高度角设置值
	/// @author	Gan Shu Long
	/// @date	2026-03-17
	/// @param[in]	dAzimuth		方位
	/// @param[in]	dElevation	高度角
	/// @param[in]	eAzElAboutBoresight	视轴类型
	//********************************************************************
	void AssignAzEl(double dAzimuth, double dElevation, EAzElAboutBoresight eAzElAboutBoresight = eAzElAboutBoresightUnknown);

	//********************************************************************
	/// 按欧拉角设置值
	/// @author	Gan Shu Long
	/// @date	2026-03-17
	/// @param[in]	eEulerOrientationSequence  欧拉角序列
	/// @param[in]	a	欧拉角a
	/// @param[in]	b	欧拉角b
	/// @param[in]	c	欧拉角c
	//********************************************************************
	void AssignEulerAngles(EEulerOrientationSequence eEulerOrientationSequence, double a, double b, double c);

	//********************************************************************
	/// 按四元数设置值
	/// @author	Gan Shu Long
	/// @date	2026-03-17
	/// @param[in]	x  四元数x
	/// @param[in]	y  四元数y
	/// @param[in]	z  四元数z
	/// @param[in]	s  四元数s
	//********************************************************************
	void AssignQuaternion(double x, double y, double z, double s);

	//********************************************************************
	/// 按 YPR设置值
	/// @author	Gan Shu Long
	/// @date	2026-03-17
	/// @param[in]	eYPRAnglesSequence  序列
	/// @param[in]	dYaw
	/// @param[in]	dPitch
	/// @param[in]	dRoll
	//********************************************************************
	void AssignYPRAngles(EYPRAnglesSequence eYPRAnglesSequence, double dYaw, double dPitch, double dRoll);
	
	//********************************************************************
	/// 按 矩阵设置值
	/// @author	Gan Shu Long
	/// @date	2026-03-23
	/// @param[in]	d11
	/// @param[in]	d12
	/// @param[in]	d13
	/// @param[in]	d21
	/// @param[in]	d22
	/// @param[in]	d23
	/// @param[in]	d31
	/// @param[in]	d32
	/// @param[in]	d33
	//********************************************************************
	void AssignMatrix3d(
		double d11, double d12, double d13,
		double d21, double d22, double d23,
		double d31, double d32, double d33);

	//********************************************************************
	/// 获得 方位高度角设置值
	/// @author	Gan Shu Long
	/// @date	2026-03-18
	/// @param[in]	dAzimuth		方位
	/// @param[in]	dElevation	高度角
	/// @param[in]	eAzElAboutBoresight	视轴类型
	//********************************************************************
	void QueryAzEl(double &dAzimuth, double &dElevation, EAzElAboutBoresight &eAzElAboutBoresight);

	//********************************************************************
	/// 获得 按欧拉角设置值
	/// @author	Gan Shu Long
	/// @date	2026-03-18
	/// @param[in]	eEulerOrientationSequence  欧拉角序列 （根据该值确定获取对应序列的a/b/c值）
	/// @param[in]	a	欧拉角a
	/// @param[in]	b	欧拉角b
	/// @param[in]	c	欧拉角c
	//********************************************************************
	void QueryEulerAngles(EEulerOrientationSequence &eEulerOrientationSequence, double &a, double &b, double &c);

	//********************************************************************
	/// 获得 按四元数设置值
	/// @author	Gan Shu Long
	/// @date	2026-03-18
	/// @param[in]	x  四元数x
	/// @param[in]	y  四元数y
	/// @param[in]	z  四元数z
	/// @param[in]	s  四元数s
	//********************************************************************
	void QueryQuaternion(double &x, double &y, double &z, double &s);

	//********************************************************************
	/// 获得 YPR设置值
	/// @author	Gan Shu Long
	/// @date	2026-03-17
	/// @param[in]	eYPRAnglesSequence  序列
	/// @param[in]	dYaw
	/// @param[in]	dPitch
	/// @param[in]	dRoll
	//********************************************************************
	void QueryYPRAngles(EYPRAnglesSequence &eYPRAnglesSequence, double &dYaw, double &dPitch, double &dRoll);
	
	//********************************************************************
	/// 获得 矩阵设置值
	/// @author	Gan Shu Long
	/// @date	2026-03-23
	/// @param[in]	d11
	/// @param[in]	d12
	/// @param[in]	d13
	/// @param[in]	d21
	/// @param[in]	d22
	/// @param[in]	d23
	/// @param[in]	d31
	/// @param[in]	d32
	/// @param[in]	d33
	//********************************************************************
	void QueryMatrix3d(
		double &d11, double &d12, double &d13,
		double &d21, double &d22, double &d23,
		double &d31, double &d32, double &d33);

	//********************************************************************
	/// 获得 固定指向偏置姿态类型
	/// @author	Gan Shu Long
	/// @date	2026-03-17
	/// @return	固定指向偏置姿态类型
	//********************************************************************
	EOrientationType GetOrientationType();

private:
	int EEulerOrientationSequenceToInt(EEulerOrientationSequence eEulerOrientationSequence);
	int EYPRAnglesSequenceToInt(EYPRAnglesSequence eYPRAnglesSequence);

private:
	CObjData*								m_pObjData; 
};

