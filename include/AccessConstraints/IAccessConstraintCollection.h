#pragma once
#include <string>
#include <vector>
#include <map>
#include "../ICEnum.h"
#include "../IAtkObj.h"
class IAccessConstraint;
class IAccessCnstrMinMax;
class IAccessCnstrAngle;
struct CObjData;
struct CObjBasicConstr;
struct CObjSunConstr;
struct CObjCommConstr;        

///
/// 约束集合
///
class IATKOBJECT_API IAccessConstraintCollection
{
public:
    IAccessConstraintCollection(const IAccessConstraintCollection&) = delete;
    IAccessConstraintCollection& operator=(const IAccessConstraintCollection&) = delete;

	IAccessConstraintCollection(CObjData* pObjData);
	~IAccessConstraintCollection();

	//********************************************************************
	/// 通过类型添加约束，约束已激活则返回空
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eConstraint   约束类型
	/// @return	约束属性
	//********************************************************************
	IAccessConstraint* AddConstraint(EAccessConstraints eConstraint);

	//********************************************************************
	/// 通过名称添加约束，约束已激活则返回空
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	strCnstrName   约束名称 AzimuthAngle、ElevationAngle、Range、AzimuthRate、
	///			ElevationRate、RangeRate、AngularRate、Altitude、PropagationDelay、LineOfSight、
	///			SunElevationAngle、SunGroundElevAngle、LunarElevationAngle、LOSSunExclusion、LOSLunarExclusion
	/// @return	约束属性
	//********************************************************************
	IAccessConstraint* AddNamedConstraint(std::string strCnstrName);

	//********************************************************************
	/// 对象所支持的约束名称
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	所支持的约束名称
	//********************************************************************
	std::vector<std::string> AvailableConstraints();

	//********************************************************************
	/// 通过类型获得已激活的约束，约束未激活则返回空
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eConstraint   约束类型
	/// @return	约束属性
	//********************************************************************
	IAccessConstraint* GetActiveConstraint(EAccessConstraints eConstraint);

	//********************************************************************
	/// 通过名称获得已激活的约束，约束未激活则返回空
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	strCnstrName   约束类型
	/// @return	约束属性
	//********************************************************************
	IAccessConstraint* GetActiveNamedConstraint(std::string strCnstrName);

	//********************************************************************
	/// 判断此类型约束是否激活
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eConstraint   约束类型
	/// @return	true-约束激活
	//********************************************************************
	bool IsConstraintActive(EAccessConstraints eConstraint);

	//********************************************************************
	/// 判断对象是否支持此类型约束
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eConstraint   约束类型
	/// @return	true-支持约束类型
	//********************************************************************
	bool IsConstraintSupported(EAccessConstraints eConstraint);

	//********************************************************************
	/// 判断此名称约束是否激活
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	strCnstrName   约束类型
	/// @return	true-约束激活
	//********************************************************************
	bool IsNamedConstraintActive(std::string strCnstrName);

	//********************************************************************
	/// 判断对象是否支持此名称约束
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	strCnstrName   约束名称
	/// @return	true-支持约束类型
	//********************************************************************
	bool IsNamedConstraintSupported(std::string strCnstrName);

	//********************************************************************
	/// 移除此类型约束
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eConstraint   约束类型
	//********************************************************************
	void RemoveConstraint(EAccessConstraints eConstraint);

	//********************************************************************
	/// 移除此名称约束
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	strCnstrName   约束名称
	//********************************************************************
	void RemoveNamedConstraint(std::string strCnstrName);

	IAccessConstraint*     Item(int nIndex);   //按添加顺序，获得第nIndex个约束

	int                    GetCount();         //约数个数             

private:
	CObjData*                                            m_pObjData;

	std::map<EAccessConstraints, IAccessConstraint*>     m_mapAccessCnstr;      //添加的约束map
	
			
	//约束名称转类型
	EAccessConstraints CnstrNameToType(std::string strCnstrName);
	//移除约束通过类型
	void RemoveCnstr(EAccessConstraints eConstraint);   
	//判断是否支持某类型的约束
	bool IsCnstrSupported( EAccessConstraints eConstraint);
	//设置约束类型
	bool SetAccessConstraint(IAccessConstraint* &pIAccessConstraint, EAccessConstraints eConstraint);
	//设置约束大小值
	bool SetAccessCnstrMinMax(IAccessCnstrMinMax* &pIAccessCnstrMinMax, EAccessConstraints eConstraint);
	//设置约束角度
	bool SetAccessCnstrAngle(IAccessCnstrAngle* &pIAccessCnstrAngle, EAccessConstraints eConstraint);
	//获取底层C对象
	bool GetCObjConstr(EAccessConstraints eConstraint, CObjBasicConstr* &pBasicConstr, CObjSunConstr* &pSunConstr, CObjCommConstr* &pCommConstr);
};
