#pragma once
#include "../IAtkObject.h"
#include "../ICEnum.h"
#include "../AccessConstraints/IAccessConstraintCollection.h"
class CObjManage;
struct CObjData;
class CFacility;
class IPosition;
class IFaGraphics;
class IFaVO;

///
/// 地面站
///
class IATKOBJECT_API IFacility :public IAtkObject
{
public:
    IFacility(const IFacility&) = delete;
    IFacility& operator=(const IFacility&) = delete;

	IFacility(CObjData* pObjData, CObjManage* IAsGObjManage, IAtkObjectRoot* Root);
	~IFacility();

	//********************************************************************
	/// 获得位置属性
	/// @author	Gan Shu Long
	/// @date	2024-05-21
	/// @return	位置指针	
	//********************************************************************
	IPosition* GetPosition() { return m_Position; }

	//********************************************************************
	/// 设置 是否使用地形数据
	/// @author	Gan Shu Long
	/// @date	2026-10-21
	/// @param[in]	bUseTerrain  是否使用地形数据
	//********************************************************************
	void SetUseTerrain(bool bUseTerrain);

	//********************************************************************
	/// 获得 是否使用地形数据
	/// @author	Gan Shu Long
	/// @date	2026-10-21
	/// @return	是否使用地形数据
	//********************************************************************
	bool GetUseTerrain();

	//********************************************************************
	/// 设置 高度参考类型
	/// @author	Gan Shu Long
	/// @date	2026-10-21
	/// @param[in]	eAltRefType  高度参考类型
	//********************************************************************
	void SetAltRef(EAltRefType eAltRefType);

	//********************************************************************
	/// 获得 高度参考类型
	/// @author	Gan Shu Long
	/// @date	2026-10-21
	/// @return	高度参考类型
	//********************************************************************
	EAltRefType GetAltRef();

	//********************************************************************
	/// 设置 离地高度
	/// @author	Gan Shu Long
	/// @date	2026-10-21
	/// @param[in]	dHeightAboveGround  离地高度
	//********************************************************************
	void SetHeightAboveGround(double dHeightAboveGround);

	//********************************************************************
	/// 获得 离地高度
	/// @author	Gan Shu Long
	/// @date	2026-10-21
	/// @return	离地高度
	//********************************************************************
	double GetHeightAboveGround();

	//********************************************************************
	/// 获得二维属性
	/// @author	Gan Shu Long
	/// @date	2024-05-21
	/// @return	二维属性指针	
	//********************************************************************
	IFaGraphics* GetGraphics() { return m_Graphics; }

	//********************************************************************
	/// 获得三维属性
	/// @author	Gan Shu Long
	/// @date	2024-05-21
	/// @return	三维属性指针	
	//********************************************************************
	IFaVO* GetVO() { return m_VO; }

private:
	CFacility* m_pCFacility;

	IPosition*						m_Position;			//位置
	IFaGraphics*					m_Graphics;			//二维
	IFaVO*							m_VO;				//三维
};
