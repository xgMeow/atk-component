#pragma once
#include "IClassicalLocation.h"
class CSatellite;

///
/// 轨道根数过近地点时间
///
class IATKOBJECT_API IClassicalLocationTimePastPerigee : public IClassicalLocation
{
public:
    IClassicalLocationTimePastPerigee(const IClassicalLocationTimePastPerigee&) = delete;
    IClassicalLocationTimePastPerigee& operator=(const IClassicalLocationTimePastPerigee&) = delete;

	IClassicalLocationTimePastPerigee(CSatellite* pSate);
	~IClassicalLocationTimePastPerigee();

	//********************************************************************
	/// 设置过近地点时间
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dTPP 过近地点时间
	//********************************************************************
	void SetValue(double dTPP);
	//********************************************************************
	/// 获得过近地点时间
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	过近地点时间
	//********************************************************************
	double GetValue();

private:
	CSatellite*     m_pSate;

};
