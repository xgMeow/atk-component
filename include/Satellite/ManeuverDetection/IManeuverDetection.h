#pragma once
#include <vector>
#include <string>
#include <map>
#include "../../ICEnum.h"
#include "../../IAtkObj.h"

class CObjManage;

class IMnvTLEDataBaseDetection;
class IMnvPODDataBaseDetection;


///
/// 机动分析
///
class IATKOBJECT_API IManeuverDetection
{
public:
    IManeuverDetection(const IManeuverDetection&) = delete;
    IManeuverDetection& operator=(const IManeuverDetection&) = delete;

	IManeuverDetection(CObjManage* IAsGObjManage);
	~IManeuverDetection();

	//********************************************************************
	/// 基于TLE的历史机动检测
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @return	基于TLE的历史机动检测操作指针
	//********************************************************************
	IMnvTLEDataBaseDetection* GetTLEDataBaseDetection();

	//********************************************************************
	/// 基于定轨数据的机动检测
	/// @author	Dong Min
	/// @date	2025-09-20
	/// @return	基于定轨数据的机动检测操作指针
	//********************************************************************
	IMnvPODDataBaseDetection* GetPODDataBaseDetection();

private:
	CObjManage*        m_IAsGObjManage;

	IMnvTLEDataBaseDetection*  m_pTLEData;
	IMnvPODDataBaseDetection*  m_PODData;
};
