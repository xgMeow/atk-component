#pragma once
#include "../../IAtkObj.h"
#include "../../Aircraft/VO/IGreatArcVO.h"
struct CObjData;

///
/// 车辆三维属性
///
class IATKOBJECT_API IGvVO :public IGreatArcVO
{
public:
    IGvVO(const IGvVO&) = delete;
    IGvVO& operator=(const IGvVO&) = delete;

	IGvVO(CObjData* pObjData);
	~IGvVO();

private:
	//屏蔽没有的基类属性
	using  IGreatArcVO::GetDataDisplay;
};
