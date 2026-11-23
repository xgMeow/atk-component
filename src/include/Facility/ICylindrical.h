#pragma once
#include "../IAtkObj.h"
#include "IPosition.h"

///
/// 位置：圆柱坐标
///
class IATKOBJECT_API ICylindrical : public IPosition
{
public:
    ICylindrical(const ICylindrical&) = delete;
    ICylindrical& operator=(const ICylindrical&) = delete;

	ICylindrical();
	ICylindrical(double dRadius, double dLon, double dZ);
	~ICylindrical();

	void SetRadius(double dRadius);
	void SetLon(double dLon);
	void SetZ(double dZ);

	double GetRadius();
	double GetLon();
	double GetZ();

private:
	double	m_Radius;
	double	m_Lon;
	double	m_Z;
};
