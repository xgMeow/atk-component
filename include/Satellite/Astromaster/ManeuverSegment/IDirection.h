#pragma once
#include <vector>
#include "../../../IAtkObj.h"
#include "../../../IClassInfo.h"
#include "../../../ICEnum.h"
class CMCSManeuver;
class IVAMCSManeuver;
class IDirectionXYZ;
class IDirectionRADec;

///
/// 机动段坐标
///
class IATKOBJECT_API IDirection :public IClassInfo
{
public:
    IDirection(const IDirection&) = delete;
    IDirection& operator=(const IDirection&) = delete;

	IDirection(CMCSManeuver* pManeuver, IVAMCSManeuver* pIVAMCSManeuver, bool bIsSubClass);
	virtual ~IDirection();

	//********************************************************************
	/// 转换坐标类型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	pDirection  坐标类型属性
	/// @Return	
	//********************************************************************
	void Assign(IDirection* pDirection);

	//********************************************************************
	/// 设置球坐标
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dRA   方位角
	/// @Param	dDec  仰角
	/// @Return	
	//********************************************************************
	void AssignRADec(double dRA, double dDec);

	//********************************************************************
	/// 设置直角坐标
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dX  速度增量Vx
	/// @Param	dY  速度增量Vy
	/// @Param	dZ  速度增量Vz
	/// @Return	
	//********************************************************************
	void AssignXYZ(double dX, double dY, double dZ);

	//********************************************************************
	/// 转换到某坐标
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eType  坐标类型
	/// @Return	坐标属性
	//********************************************************************
	IDirection* ConvertTo(EDirectionType eType);

	//********************************************************************
	/// 获得球坐标值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Output
	/// @Param	dRA   方位角
	/// @Param	dDec  仰角
	/// @Return	
	//********************************************************************
	void QueryRADec(double &dRA, double &dDec);

	//********************************************************************
	/// 获得球坐标值数组
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	[方位角、仰角]
	//********************************************************************
	std::vector<double> QueryRADecArray();

	//********************************************************************
	/// 获得直角坐标值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Output
	/// @Param	dX  速度增量Vx
	/// @Param	dY  速度增量Vy
	/// @Param	dZ  速度增量Vz
	/// @Return	
	//********************************************************************
	void QueryXYZ(double &dX,double &dY,double &dZ);

	//********************************************************************
	/// 获得直角坐标数组
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	[速度增量Vx、速度增量Vy、速度增量Vz]
	//********************************************************************
	std::vector<double> QueryXYZArray();

protected:
	EDirectionType       m_eDirectionType;
	IDirectionXYZ*       m_pIDirectionXYZ;
	IDirectionRADec*     m_pIDirectionRADec;

private:
	CMCSManeuver*        m_pcManeuver;
	IVAMCSManeuver*      m_pIVAMCSManeuver;

	bool                 m_bIsSubClass;

};
