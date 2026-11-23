#pragma once
#include "../../IAtkObj.h"
#include "../../Aircraft/Graphics/IGreatArcGraphics.h"

///
/// 潜艇二维属性
///
class IATKOBJECT_API ISuGraphics :public IGreatArcGraphics
{
public:
    ISuGraphics(const ISuGraphics&) = delete;
    ISuGraphics& operator=(const ISuGraphics&) = delete;

	ISuGraphics(CObjData* pObjData);
	~ISuGraphics();

private:
	//屏蔽没有的基类属性
	using  IGreatArcGraphics::GetRangeContours;
	using  IGreatArcGraphics::GetGroundEllipses;
};
