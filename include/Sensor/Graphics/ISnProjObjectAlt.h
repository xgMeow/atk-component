#pragma once
#include "../../IAtkObj.h"
#include "IDisplayDistance.h"
#include <string>
class CSensor;

///
/// 投影对象
///
class IATKOBJECT_API ISnProjObjectAlt : public IDisplayDistance
{
public:
    ISnProjObjectAlt(const ISnProjObjectAlt&) = delete;
    ISnProjObjectAlt& operator=(const ISnProjObjectAlt&) = delete;

	ISnProjObjectAlt(CSensor* pCSensor);
	~ISnProjObjectAlt();

	//指定是否排除视界弧。
	double GetExcludeHorizonArcs();

private:
	CSensor* m_pCSensor;
};

