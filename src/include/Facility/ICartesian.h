#pragma once
#include "../IAtkObj.h"
#include "IPosition.h"

///
/// 位置：笛卡尔坐标
///
class IATKOBJECT_API ICartesian : public IPosition
{

public:
    ICartesian(const ICartesian&) = delete;
    ICartesian& operator=(const ICartesian&) = delete;

	ICartesian();
	ICartesian(double x, double y, double z);
	~ICartesian();

	void SetX(double x);
	void SetY(double y);
	void SetZ(double z);

	double GetX();
	double GetY();
	double GetZ();

private:
	double	m_X;	//(m)
	double	m_Y;	//(m)
	double	m_Z;	//(m)

};
