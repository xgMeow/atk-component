#pragma once
#include "IVePassNumbering.h"
class CSatellite;

///
/// 初始圈数
///
class IATKOBJECT_API IVePassNumberingFirstPassNum : public IVePassNumbering
{
public:
	IVePassNumberingFirstPassNum(const IVePassNumberingFirstPassNum&) = delete;
	IVePassNumberingFirstPassNum& operator=(const IVePassNumberingFirstPassNum&) = delete;

	IVePassNumberingFirstPassNum(CSatellite* pSate);
	~IVePassNumberingFirstPassNum();

	//********************************************************************
	/// 设置初始圈数
	/// @author	Gan Shu Long
	/// @date	2026-10-20
	/// @param[in]	nFirstPassNum 初始圈数
	//********************************************************************
	void SetFirstPassNum(int nFirstPassNum);

	//********************************************************************
	/// 获得初始圈数
	/// @author	Gan Shu Long
	/// @date	2026-10-20
	/// @return	初始圈数
	//********************************************************************
	int GetFirstPassNum();

private:
	CSatellite* m_pSate;

};