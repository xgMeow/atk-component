#pragma once
#include "../../IAtkObj.h"
#include "../../Aircraft/Graphics/IGreatArcGraphics.h"
struct CObjData;

///
/// 车辆二维属性
///
class IATKOBJECT_API IGvGraphics :public IGreatArcGraphics
{
public:
    IGvGraphics(const IGvGraphics&) = delete;
    IGvGraphics& operator=(const IGvGraphics&) = delete;

	IGvGraphics(CObjData* pObjData);
	~IGvGraphics();
};
