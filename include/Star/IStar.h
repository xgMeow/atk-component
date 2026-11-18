#pragma once
#include "../IAtkObject.h"
#include "../AccessConstraints/IAccessConstraintCollection.h"
class CObjManage;
struct CObjData;
class CStar;
class IStGraphics;

///
/// 恒星
///
class IATKOBJECT_API IStar :public IAtkObject
{
public:
    IStar(const IStar&) = delete;
    IStar& operator=(const IStar&) = delete;

	IStar(CObjData* pObjData, CObjManage* IAsGObjManage, IAtkObjectRoot* Root);
	~IStar();

	//********************************************************************
	/// 设置 赤经(deg)
	/// @author	Gan Shu Long
	/// @date	2026-03-09
	/// @param[in]	locationRightAscension 赤经(deg)
	//********************************************************************
	void SetLocationRightAscension(double locationRightAscension);

	//********************************************************************
	/// 获得 赤经(deg)
	/// @author	Gan Shu Long
	/// @date	2026-03-09
	/// @return	 赤经(deg)
	//********************************************************************
	double GetLocationRightAscension();

	//********************************************************************
	/// 设置 赤纬(deg)
	/// @author	Gan Shu Long
	/// @date	2026-03-09
	/// @param[in]	locationDeclination 赤纬(deg)
	//********************************************************************
	void SetLocationDeclination(double locationDeclination);

	//********************************************************************
	/// 获得 赤纬(deg)
	/// @author	Gan Shu Long
	/// @date	2026-03-09
	/// @return	 赤纬(deg)
	//********************************************************************
	double GetLocationDeclination();

	//********************************************************************
	/// 设置 赤经(arc sec/year)
	/// @author	Gan Shu Long
	/// @date	2026-03-09
	/// @param[in]	properMotionRightAscension 赤经(arc sec/year)
	//********************************************************************
	void SetProperMotionRightAscension(double properMotionRightAscension);

	//********************************************************************
	/// 获得 赤经(arc sec/year)
	/// @author	Gan Shu Long
	/// @date	2026-03-09
	/// @return	 赤经(arc sec/year)
	//********************************************************************
	double GetProperMotionRightAscension();

	//********************************************************************
	/// 设置 赤纬(darc sec/year)
	/// @author	Gan Shu Long
	/// @date	2026-03-09
	/// @param[in]	properMotionDeclination 赤纬(darc sec/year)
	//********************************************************************
	void SetProperMotionDeclination(double properMotionDeclination);

	//********************************************************************
	/// 获得 赤纬(darc sec/year)
	/// @author	Gan Shu Long
	/// @date	2026-03-09
	/// @return	 赤纬(darc sec/year)
	//********************************************************************
	double GetProperMotionDeclination();

	//********************************************************************
	/// 设置 星等
	/// @author	Gan Shu Long
	/// @date	2026-03-09
	/// @param[in]	magnitude 星等
	//********************************************************************
	void SetMagnitude(double magnitude);

	//********************************************************************
	/// 获得 星等
	/// @author	Gan Shu Long
	/// @date	2026-03-09
	/// @return	 星等
	//********************************************************************
	double GetMagnitude();

	//********************************************************************
	/// 设置 年视差
	/// @author	Gan Shu Long
	/// @date	2026-03-09
	/// @param[in]	parallax 年视差
	//********************************************************************
	void SetParallax(double parallax);

	//********************************************************************
	/// 获得 年视差
	/// @author	Gan Shu Long
	/// @date	2026-03-09
	/// @return	 年视差
	//********************************************************************
	double GetParallax();

	//********************************************************************
	/// 获得二维属性
	/// @author	Gan Shu Long
	/// @date	2026-03-09
	/// @return	二维属性指针	
	//********************************************************************
	IStGraphics* GetGraphics() { return m_Graphics; }

private:
	CStar*					m_pCStar;

	IStGraphics*		m_Graphics;			//二维
};
