#pragma once
#include "../IAtkObj.h"
#include "IPosition.h"

///
/// 位置：地心坐标
///
class IATKOBJECT_API IGeocentric : public IPosition
{
public:
    IGeocentric(const IGeocentric&) = delete;
    IGeocentric& operator=(const IGeocentric&) = delete;

	IGeocentric();
	IGeocentric(double lat, double lon, double alt);
	~IGeocentric();

	void SetLat(double lat);
	void SetLon(double lon);
	void SetAlt(double alt);

	double GetLat();
	double GetLon();
	double GetAlt();

private:
	double	m_Lat;		//纬度(deg)
	double	m_Lon;	//经度(deg)
	double	m_Alt;		//高度(km)
};
