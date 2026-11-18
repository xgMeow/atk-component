#pragma once
#include "../IAtkObj.h"
#include "../ICEnum.h"
#include <string>
struct CVehEllipseSet;
class IVeEllipseDataCollection;

///
/// 椭圆设置
///
class IATKOBJECT_API IVeGroundEllipseElement
{
public:
    IVeGroundEllipseElement(const IVeGroundEllipseElement&) = delete;
    IVeGroundEllipseElement& operator=(const IVeGroundEllipseElement&) = delete;

	IVeGroundEllipseElement(CVehEllipseSet* pCVehEllipseSet);
	~IVeGroundEllipseElement();

	//********************************************************************
	/// 设置椭圆设置名称
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	/// @param[in]	strEllipseName 椭圆设置名称
	//********************************************************************
	void SetEllipseName(std::string strEllipseName);

	//********************************************************************
	/// 获取椭圆设置名称
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	/// @return 椭圆设置名称
	//********************************************************************
	std::string GetEllipseName();

	//********************************************************************
	/// 获得椭圆数据集合
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	/// @return	地面椭圆设置集合指针
	//********************************************************************
	IVeEllipseDataCollection* GetEllipseData() { return m_EllipseData; }

private:
	IVeEllipseDataCollection*	m_EllipseData;					//i对象椭圆数据集合

	CVehEllipseSet*					m_pCVehEllipseSet;			//C对象椭圆设置
};
