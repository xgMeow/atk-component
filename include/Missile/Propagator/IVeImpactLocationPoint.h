#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
#include "IVeImpactLocation.h"
struct CObjData;
class CMissile;
class IVeImpact;
class IVeLaunchControl;


///
/// 位置落点
///
class IATKOBJECT_API IVeImpactLocationPoint : public IVeImpactLocation
{
public:
    IVeImpactLocationPoint(const IVeImpactLocationPoint&) = delete;
    IVeImpactLocationPoint& operator=(const IVeImpactLocationPoint&) = delete;

	IVeImpactLocationPoint(CObjData* pObjData);
	~IVeImpactLocationPoint();

	//********************************************************************
	/// 获得支持的增量类型
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @return 支持的增量类型
	//********************************************************************
	std::vector<std::string> GetLaunchControlSupportedTypes();

	//********************************************************************
	/// 判断是否支持增量类型
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @param	eVeLaunchControl  增量类型
	/// @return 是否支持增量类型
	//********************************************************************
	bool IsLaunchControlTypeSupported(EVeLaunchControl eVeLaunchControl);

	//********************************************************************
	/// 设置增量类型
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @param[in]	eVeLaunchControl  增量类型
	//********************************************************************
	void SetLaunchControlType(EVeLaunchControl eVeLaunchControl);

	//********************************************************************
	/// 获得增量类型
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @return	增量类型
	//********************************************************************
	EVeLaunchControl GetLaunchControlType();

	//********************************************************************
	/// 获得增量
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @return	增量		
	//********************************************************************
	IVeLaunchControl* GetLaunchControl() { return m_LaunchControl; }

	//只支持经纬高位置落点，其他相关接口函数不需要
	//********************************************************************
	/// 获得落点
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @return	落点		
	//********************************************************************
	IVeImpact* GetImpact() { return m_Impact; }

private:
	CObjData*											m_pObjData;
	CMissile*												m_pCMissile;

	IVeImpact*											m_Impact;
	IVeLaunchControl*								m_LaunchControl;
};
