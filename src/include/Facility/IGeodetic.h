#pragma once
#include "../IAtkObj.h"
#include "IPosition.h"
class CObjManage;

///
/// 位置：地理坐标
///
class IATKOBJECT_API IGeodetic : public IPosition
{
public:
    IGeodetic(const IGeodetic&) = delete;
    IGeodetic& operator=(const IGeodetic&) = delete;

	IGeodetic();
	IGeodetic(double lat, double lon, double alt);
	~IGeodetic();

	void SetLat(double lat);
	void SetLon(double lon);
	void SetAlt(double alt);

	double GetLat();
	double GetLon();
	double GetAlt();	

private:
	double	m_Lat;		//纬度(deg)
	double	m_Lon;	//经度(deg)
	double	m_Alt;		//高度(m)
};
