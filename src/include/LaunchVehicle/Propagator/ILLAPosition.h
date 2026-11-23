#pragma once
#include "../../ICEnum.h"
#include "../../IAtkObj.h" 
class CLatLonAlt;

///
/// 经纬高位置
///
class IATKOBJECT_API ILLAPosition
{
public:
    ILLAPosition(const ILLAPosition&) = delete;
    ILLAPosition& operator=(const ILLAPosition&) = delete;

	ILLAPosition(CLatLonAlt* pLLA);
	~ILLAPosition();

	////********************************************************************
	///// 分配坐标
	///// @Author	Gan Shu Long
	///// @Date	2024-09-23
	///// @Input
	///// @Param	pILLAPosition  位置信息
	///// @Return	
	////********************************************************************
	//void Assign(ILLAPosition* pILLAPosition);

	////********************************************************************
	///// 设置 地理坐标
	///// @Author	Gan Shu Long
	///// @Date	2024-09-23
	///// @Input
	///// @Param	lat  地理位置纬度(rad)
	///// @Param	lon  地理位置经度(rad)
	///// @Param	alt  地理位置高度(m) 
	///// @Return	
	////********************************************************************
	//void AssignGeocentric(double lat, double lon, double alt);

	//********************************************************************
	/// 设置 地理坐标
	/// @author	Gan Shu Long
	/// @date	2024-09-23
	/// @param[in]	lat  地理位置纬度(deg)
	/// @param[in]	lon  地理位置经度(deg)
	/// @param[in]	alt  地理位置高度(m) 
	//********************************************************************
	void AssignGeodetic(double lat, double lon, double alt);

	////********************************************************************
	///// 转换坐标类型，new一个子类新空间返回，自身值不改变
	///// @Author	Gan Shu Long
	///// @Date	2024-09-23
	///// @Input
	///// @Param	converType  转换类型
	///// @Return	IPosition* 转换后类型指针
	////********************************************************************
	//ILLAPosition* ConvertTo(ELLAPositionType converType);

	//********************************************************************
	/// 获得轨道类型
	/// @author	Gan Shu Long
	/// @date	2024-09-23
	/// @return	轨道类型
	//********************************************************************
	ELLAPositionType GetType() { return eLLAPosGeodetic; }

private:
	CLatLonAlt*				m_pCLatLonAlt;
};

