#pragma once
#include "../../Satellite/Attitude/IVeAttitude.h"
struct CObjData;

///
/// 姿态：STK文件
///
class IATKOBJECT_API IVeAttitudeStkExternal : public IVeAttitude
{
public:
    IVeAttitudeStkExternal(const IVeAttitudeStkExternal&) = delete;
    IVeAttitudeStkExternal& operator=(const IVeAttitudeStkExternal&) = delete;

	IVeAttitudeStkExternal(CObjData* pObjData);
	~IVeAttitudeStkExternal();

	//********************************************************************
	/// 设置STK星历文件路径
	/// @author	Gan Shu Long
	/// @date	2024-09-24
	/// @param[in]	strFilename STK星历文件路径
	//********************************************************************
	void SetFilename(std::string  strFilename);

	//********************************************************************
	/// 获得STK星历文件路径
	/// @author	Gan Shu Long
	/// @date	2024-09-24
	/// @return	STK星历文件路径
	//********************************************************************
	std::string  GetFilename();

	//********************************************************************
	/// 获得开始时间
	/// @author	Gan Shu Long
	/// @date	2024-09-24
	/// @return	开始时间
	//********************************************************************
	std::string  GetStartTime();

	//********************************************************************
	/// 获得结束时间
	/// @author	Gan Shu Long
	/// @date	2024-09-24
	/// @return	结束时间
	//********************************************************************
	std::string  GetStopTime();

private:
	CObjData*							m_pObjData;
};
