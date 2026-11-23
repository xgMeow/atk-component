#pragma once
#include "../../IAtkObj.h"
#include "../../Aircraft/Graphics/IGreatArcGraphics.h"

///
/// 舰船二维属性
///
class IATKOBJECT_API IShGraphics :public IGreatArcGraphics
{
public:
    IShGraphics(const IShGraphics&) = delete;
    IShGraphics& operator=(const IShGraphics&) = delete;

	IShGraphics(CObjData* pObjData);
	~IShGraphics();
};
