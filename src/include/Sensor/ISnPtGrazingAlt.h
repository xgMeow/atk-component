#pragma once
#include "../IAtkObj.h"
#include "ISnPointing.h"
struct CObjData;
class CSensor;

///
/// 指向：入射高度
///
class IATKOBJECT_API ISnPtGrazingAlt : public ISnPointing
{
public:
    ISnPtGrazingAlt(const ISnPtGrazingAlt&) = delete;
    ISnPtGrazingAlt& operator=(const ISnPtGrazingAlt&) = delete;

	ISnPtGrazingAlt(CObjData* pCObjData);
	~ISnPtGrazingAlt();

	//********************************************************************
	/// 设置 方位角偏移量
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @param[in]	dAzimuthOffset  方位角偏移量
	//********************************************************************
	void SetAzimuthOffset(double dAzimuthOffset);

	//********************************************************************
	/// 获得 方位角偏移量
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @return	double 方位角偏移量
	//********************************************************************
	double GetAzimuthOffset();

	//********************************************************************
	/// 设置 入射高度
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @param[in]	dGrazingAlt  入射高度
	//********************************************************************
	void SetGrazingAlt(double dGrazingAlt);

	//********************************************************************
	/// 获得 入射高度
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @return	double 入射高度
	//********************************************************************
	double GetGrazingAlt();

private:
	CSensor*				m_pCSensor;
};

