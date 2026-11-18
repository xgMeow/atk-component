#pragma once
#include <string>
#include <vector>
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
struct CGfxVehPass;
class IVeLeadTrailData;

///
/// 二维轨迹属性
///
class IATKOBJECT_API IVeGfxLeadTrailData
{
public:
    IVeGfxLeadTrailData(const IVeGfxLeadTrailData&) = delete;
    IVeGfxLeadTrailData& operator=(const IVeGfxLeadTrailData&) = delete;

	IVeGfxLeadTrailData(CGfxVehPass* pCGfxVehPass);
	~IVeGfxLeadTrailData();

	//********************************************************************
	/// 判断是否支持此轨迹类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eTrailData  轨迹类型
	/// @return	true-支持此轨迹类型
	//********************************************************************
	bool IsTrailDataTypeSupported(ELeadTrailData eTrailData);

	//********************************************************************
	/// 设置轨迹类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eTrailData  轨迹类型
	//********************************************************************
	void SetTrailDataType(ELeadTrailData eTrailData);

	//********************************************************************
	/// 判断二维轨迹是否还有参数
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	二维轨迹是否还有参数，true-有参数
	//********************************************************************
	bool GetHasTrailData();

	//********************************************************************
	/// 获得二维轨迹属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	二维轨迹属性指针	
	//********************************************************************
	IVeLeadTrailData* GetTrailData();

	//********************************************************************
	/// 获得二维轨迹支持类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	二维轨迹支持类型
	//********************************************************************
	std::vector<std::string> GetTrailDataSupportedTypes();

	//********************************************************************
	/// 获得二维轨迹类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	二维轨迹类型
	//********************************************************************
	ELeadTrailData GetTrailDataType();

private:
	CGfxVehPass*				m_pCGfxVehPass;				//C对象二维轨迹指针

	IVeLeadTrailData*            m_TrailData;                 //二维轨迹属性

};

