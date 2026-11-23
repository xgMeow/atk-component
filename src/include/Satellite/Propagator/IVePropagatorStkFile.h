#pragma once
#include "IVePropagator.h"
class CObjManage;
class CSatellite;
class ISatellite;

///
/// stk星历数据
///
class IATKOBJECT_API IVePropagatorStkFile : public IVePropagator
{
public:
    IVePropagatorStkFile(const IVePropagatorStkFile&) = delete;
    IVePropagatorStkFile& operator=(const IVePropagatorStkFile&) = delete;

	IVePropagatorStkFile(CSatellite* pSate, ISatellite* pISate, CObjManage* IAsGObjManage);
	~IVePropagatorStkFile();

	//********************************************************************
	/// 获得stk星历数据开始时间
	/// @author	Dong Min
	/// @date	2025-8-23
	/// @return	stk星历数据开始时间			
	//********************************************************************
	std::string GetStartTime();

	//********************************************************************
	/// 获得stk星历数据结束时间
	/// @author	Dong Min
	/// @date	2025-8-23
	/// @return	stk星历数据结束时间
	//********************************************************************
	std::string GetStopTime();

	//********************************************************************
	/// 设置stk星历文件
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	strFileName 星历文件名
	//********************************************************************
	void SetFileName(std::string strFileName);
	//********************************************************************
	/// 获得stk星历文件
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	stk星历文件名
	//********************************************************************
	std::string GetFileName();

private:
	CSatellite*          m_pSate;

};
