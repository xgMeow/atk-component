#pragma once
#include "../IAtkObject.h"
#include "../ICEnum.h"
class CObjManage;
struct CObjData;
class CMissile;
class IVePropagator;
class IVeAttitude;
class IVeGroundEllipsesCollection;
class IMsGraphics;
class IMsVO;


///
/// 导弹
///
class IATKOBJECT_API IMissile :public IAtkObject
{
public:
    IMissile(const IMissile&) = delete;
    IMissile& operator=(const IMissile&) = delete;

	IMissile(CObjData* pObjData, CObjManage* IAsGObjManage, IAtkObjectRoot* Root);
	~IMissile();

	//********************************************************************
	/// 获得轨道类型
	/// @author	Gan Shu Long
	/// @date	2026-03-04
	/// @return	轨道类型
	//********************************************************************
	EVePropagatorType GetTrajectoryType();

	//********************************************************************
	/// 设置轨道类型
	/// @author	Gan Shu Long
	/// @date	2026-03-04
	/// @param[in]	eTrajectoryType  轨道类型
	//********************************************************************
	void SetTrajectoryType(EVePropagatorType eTrajectoryType);

	//********************************************************************
	/// 获得支持的轨道类型
	/// @author	Gan Shu Long
	/// @date	2026-03-04
	/// @return 支持的轨道类型
	//********************************************************************
	std::vector<std::string> GetTrajectorySupportedTypes();

	//********************************************************************
	/// 判断是否支持轨道类型
	/// @author	Gan Shu Long
	/// @date	2026-03-04
	/// @return 是否支持轨道类型
	//********************************************************************
	bool IsTrajectoryTypeSupported(EVePropagatorType eTrajectoryType);

	//********************************************************************
	/// 获得轨道指针
	/// @author	Gan Shu Long
	/// @date	2026-03-04
	/// @return	轨道指针
	//********************************************************************
	IVePropagator* GetTrajectory() { return m_Trajectory; }

	//********************************************************************
	/// 获得支持的姿态类型
	/// @author	Gan Shu Long
	/// @date	2026-03-04
	/// @return 支持的姿态类型
	//********************************************************************
	std::vector<std::string> GetAttitudeSupportedTypes();

	//********************************************************************
	/// 判断是否支持姿态类型
	/// @author	Gan Shu Long
	/// @date	2026-03-04
	/// @return 是否支持姿态类型
	//********************************************************************
	bool IsAttitudeTypeSupported(EVeAttitude eAttitudeType);

	//********************************************************************
	/// 设置姿态类型
	/// @author	Gan Shu Long
	/// @date	2026-03-04
	/// @param[in]	eAttitudeType  姿态类型
	//********************************************************************
	void SetAttitudeType(EVeAttitude eAttitudeType);

	//********************************************************************
	/// 获得姿态类型
	/// @author	Gan Shu Long
	/// @date	2026-03-04
	/// @return	姿态类型
	//********************************************************************
	EVeAttitude GetAttitudeType();

	//********************************************************************
	/// 获得姿态指针
	/// @author	Gan Shu Long
	/// @date	2026-03-04
	/// @return	姿态指针
	//********************************************************************
	IVeAttitude* GetAttitude() { return m_Attitude; }

	//********************************************************************
	/// 获得地面椭圆设置集合
	/// @author	Gan Shu Long
	/// @date	2026-03-06
	/// @return	地面椭圆设置集合指针
	//********************************************************************
	IVeGroundEllipsesCollection* GetGroundEllipses() { return m_GroundEllipses; }

	//********************************************************************
	/// 获得二维属性
	/// @author	Gan Shu Long
	/// @date	2026-03-04
	/// @return	二维属性指针	
	//********************************************************************
	IMsGraphics* GetGraphics() { return m_Graphics; }

	//********************************************************************
	/// 获得三维属性
	/// @author	Gan Shu Long
	/// @date	2026-03-04
	/// @return	三维属性指针	
	//********************************************************************
	IMsVO* GetVO() { return m_VO; }

private:
	CMissile*										m_pCMissile;

	CObjData*									m_pObjData;
	IVePropagator*							m_Trajectory;								//轨道指针
	IVeAttitude*									m_Attitude;									//姿态指针
	IVeGroundEllipsesCollection*		m_GroundEllipses;						//地面椭圆设置集合
	IMsGraphics*								m_Graphics;								//二维
	IMsVO*										m_VO;											//三维
};
