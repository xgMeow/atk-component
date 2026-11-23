#pragma once
#include "../IAtkObj.h"
#include "../Sensor/ILocationData.h"
#include "../ICEnum.h"
#include <vector>
struct CObjData;

///
/// 位置
///
class IATKOBJECT_API IPosition : public ILocationData
{
public:
    IPosition(const IPosition&) = delete;
    IPosition& operator=(const IPosition&) = delete;

	IPosition();
	IPosition(CObjData* pCObjData);
	~IPosition();

	//********************************************************************
	/// 分配坐标
	/// @author	Gan Shu Long
	/// @date	2026-01-16
	/// @param[in]	pIPosition  位置信息
	//********************************************************************
	void Assign(IPosition* pIPosition);

	//********************************************************************
	/// 设置 笛卡尔坐标
	/// @author	Gan Shu Long
	/// @date	2026-01-16
	/// @param[in]	dX  坐标x
	/// @param[in]	dY  坐标y
	/// @param[in]	dZ  坐标z
	//********************************************************************
	void AssignCartesian(double dX, double dY, double dZ);

	////********************************************************************
	///// 设置 柱坐标
	///// @Author	Gan Shu Long
	///// @Date	2026-01-16
	///// @Input
	///// @Param	dRadius  半径
	///// @Param	dLon		经度
	///// @Param	dZ			Z
	///// @Return	
	////********************************************************************
	//void AssignCylindrical(double dRadius, double dLon, double dZ);

	////********************************************************************
	///// 设置 地心坐标
	///// @Author	Gan Shu Long
	///// @Date	2026-01-16
	///// @Input
	///// @Param	dLat  地心位置纬度(deg)
	///// @Param	dLon  地心位置经度(deg)
	///// @Param	dAlt	地心位置高度
	///// @Return	
	////********************************************************************
	//void AssignGeocentric(double dLat, double dLon, double dAlt);

	//********************************************************************
	/// 设置 地理坐标
	/// @author	Gan Shu Long
	/// @date	2026-01-16
	/// @param[in]	dLat  地理位置纬度(deg)
	/// @param[in]	dLon  地理位置经度(deg)
	/// @param[in]	dAlt  地理位置高度(m) 
	//********************************************************************
	void AssignGeodetic(double dLat, double dLon, double dAlt);
	
	////********************************************************************
	///// 设置 球坐标
	///// @Author	Gan Shu Long
	///// @Date	2026-01-16
	///// @Input
	///// @Param	dLat  球坐标纬度(deg)
	///// @Param	dLon  球坐标经度(deg)
	///// @Param	dRadius	球坐标半径
	///// @Return	
	////********************************************************************
	//void AssignSpherical(double dLat, double dLon, double dRadius);
	
	////********************************************************************
	///// 转换坐标类型，深拷贝复制一个新对象返回，改变这个返回对象的值，不影响内核
	///// @Author	Gan Shu Long
	///// @Date	2026-01-16
	///// @Input
	///// @Param	converType  转换类型
	///// @Return	IPosition* 转换后类型指针
	////********************************************************************
	//IPosition* ConvertTo(EPositionType converType);

	//********************************************************************
	/// 获取笛卡尔坐标
	/// @author	Gan Shu Long
	/// @date	2026-01-16
	/// @param[in]	 x  坐标x
	/// @param[in]	 y  坐标y
	/// @param[in]	 z  坐标z
	//********************************************************************
	void QueryCartesian(double & x, double & y, double & z);

	//********************************************************************
	/// 获取笛卡尔坐标数组
	/// @author	Gan Shu Long
	/// @date	2026-01-16
	/// @return	笛卡尔坐标数组
	//********************************************************************
	std::vector<double> QueryCartesianArray();

	//********************************************************************
	/// 获取 地理坐标
	/// @author	Gan Shu Long
	/// @date	2026-10-21
	/// @param[in]	dLat  地理位置纬度(deg)
	/// @param[in]	dLon  地理位置经度(deg)
	/// @param[in]	dAlt  地理位置高度(m) 
	//********************************************************************
	void QueryGeodetic(double & dLat, double & dLon, double & dAlt);

	//********************************************************************
	/// 获取 地理坐标数组
	/// @author	Gan Shu Long
	/// @date	2026-10-21
	/// @return	地理坐标数组
	//********************************************************************
	std::vector<double> QueryGeodeticArray();

	////********************************************************************
	///// 获取柱坐标
	///// @Author	Gan Shu Long
	///// @Date	2026-01-16
	///// @Input
	///// @Param	dRadius  半径
	///// @Param	dLon		经度
	///// @Param	dZ			Z
	///// @Return	
	////********************************************************************
	//void QueryCylindrical(double &dRadius, double &dLon, double &dZ);

	////********************************************************************
	///// 获取柱坐标数组
	///// @Author	Gan Shu Long
	///// @Date	2026-01-16
	///// @Input
	///// @Return	柱坐标数组
	////********************************************************************
	//std::vector<double> QueryCylindricalArray();

	////********************************************************************
	///// 获取球坐标
	///// @Author	Gan Shu Long
	///// @Date	2026-01-16
	///// @Input
	///// @Param	dLat  球坐标纬度(deg)
	///// @Param	dLon  球坐标经度(deg)
	///// @Param	dRadius	球坐标半径
	///// @Return	
	////********************************************************************
	//void QuerySpherical(double &dLat, double &dLon, double &dRadius);

	////********************************************************************
	///// 获取球坐标数组
	///// @Author	Gan Shu Long
	///// @Date	2026-01-16
	///// @Input
	///// @Return	球坐标数组
	////********************************************************************
	//std::vector<double> QuerySphericalArray();
	
	//********************************************************************
	/// 获取坐标类型
	/// @author	Gan Shu Long
	/// @date	2026-01-16
	/// @return	坐标类型
	//********************************************************************
	EPositionType GetPosType() { return m_PosType; }

private:
	//********************************************************************
	/// 更新信息到C对象
	/// @author	Gan Shu Long
	/// @date	2026-01-16
	/// @param[in]	value1  
	/// @param[in]	value2  
	/// @note 参数 value3
	/// @param value0
	void updateInfoToCObj(double value0, double value1, double value2);
							
protected:
		EPositionType		m_PosType;

	//因为无法在基类函数中将this转向子类实例
	//所以只能暂时将子类成员数据全部备份到基类中，用来保存子类类型的值，必须保持和基类一致
	//double m_Data[3];	//ICartesian[X,Y,Z](m); IGeodetic[Lat,Lon,Alt]
	
private:
	CObjData*			m_pCObjData;
};

