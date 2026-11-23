#pragma once
#include "../IAtkObj.h"
#include "IPosition.h"

///
/// 位置：球坐标
///
class IATKOBJECT_API ISpherical : public IPosition
{
public:
    ISpherical(const ISpherical&) = delete;
    ISpherical& operator=(const ISpherical&) = delete;

	ISpherical();
	ISpherical(double dLat, double dLon, double dRadius);
	~ISpherical();

	void SetLat(double dLat);
	void SetLon(double dLon);
	void SetRadius(double dRadius);

	double GetLat();
	double GetLon();
	double GetRadius();

private:
	double	m_Lat;		//纬度(deg)
	double	m_Lon;	//经度(deg)
	double	m_Radius;		//球坐标半径(km) 
};
