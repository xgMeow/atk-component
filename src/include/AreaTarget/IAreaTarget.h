#pragma once
#include "../IAtkObj.h"
#include "../IAtkObject.h"
#include "../ICEnum.h"
class CObjManage;
struct CObjData;
class IAreaTypeData;
class IATCommonTasks;
class IPosition;
class IATGraphics;
class CAreaTarget;

///
/// 区域目标
///
class IATKOBJECT_API IAreaTarget :public IAtkObject
{
public:
    IAreaTarget(const IAreaTarget&) = delete;
    IAreaTarget& operator=(const IAreaTarget&) = delete;

	IAreaTarget(CObjData* pObjData, CObjManage* IAsGObjManage, IAtkObjectRoot* Root);
	~IAreaTarget();

	//********************************************************************
	/// 设置区域类型
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @param[in]	eAreaType  区域类型
	//********************************************************************
	void SetAreaType(EAreaType eAreaType);

	//********************************************************************
	/// 获得区域类型
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @return	区域类型
	//********************************************************************
	EAreaType GetAreaType();

	//********************************************************************
	/// 获得区域类型数据
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @return	区域类型数据
	//********************************************************************
	IAreaTypeData* GetAreaTypeData() { return m_AreaTypeData; }

	//********************************************************************
	/// 获得常用任务
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @return	区域类型数据
	//********************************************************************
	IATCommonTasks* GetCommonTasks() { return m_ATCommonTasks; }

	//********************************************************************
	/// 获得质心
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @return	质心
	//********************************************************************
	IPosition* GetPosition() { return m_Position; }

	//********************************************************************
	/// 设置是否自动计算质心
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @param[in]	bAutoCentroid  是否自动计算质心
	//********************************************************************
	void SetAutoCentroid(bool bAutoCentroid);

	//********************************************************************
	/// 获得是否自动计算质心
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @return	是否自动计算质心
	//********************************************************************
	bool GetAutoCentroid();

	//********************************************************************
	/// 获得二维
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @return	二维
	//********************************************************************
	IATGraphics* GetGraphics() { return m_Graphics; }

private:
	CAreaTarget*				m_pCAreaTarget;

	IAreaTypeData*			m_AreaTypeData;			//区域类型数据
	IATCommonTasks*		m_ATCommonTasks;		//常用任务
	IPosition*						m_Position;						//质心
	IATGraphics*				m_Graphics;					//二维
};
