#pragma once
#include <string>
#include "../../IAtkObj.h"
class CMCSSegment;
class CObjManage;

///
/// 段属性
///
class IATKOBJECT_API IVAMCSSegmentProperties
{
public:
    IVAMCSSegmentProperties(const IVAMCSSegmentProperties&) = delete;
    IVAMCSSegmentProperties& operator=(const IVAMCSSegmentProperties&) = delete;

	IVAMCSSegmentProperties(CMCSSegment* pSegment, CObjManage* IAsGObjManage);
	~IVAMCSSegmentProperties();

	//********************************************************************
	/// 设置段使用的坐标系
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strDisplayCS   坐标系名称
	/// @Return	
	//********************************************************************
	void SetDisplayCoordinateSystem(std::string strDisplayCS);
	//********************************************************************
	/// 获得段使用的坐标系
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	坐标系
	//********************************************************************
	std::string GetDisplayCoordinateSystem();

private:
	CMCSSegment*    m_pSegment;
	CObjManage*     m_IAsGObjManage;

};
