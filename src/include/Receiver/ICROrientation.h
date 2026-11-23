#pragma once
#include "../IAtkObj.h"
#include "../Sensor/IOrientation.h"
struct CObjData;
class ICartesian3Vector;

///
/// 天线指向
///
class IATKOBJECT_API ICROrientation :public IOrientation
{
public:
    ICROrientation(const ICROrientation&) = delete;
    ICROrientation& operator=(const ICROrientation&) = delete;

	ICROrientation(CObjData* pCObjData);
	virtual ~ICROrientation();

	//********************************************************************
	/// 获得  偏移
	/// @author	Gan Shu Long
	/// @date	2026-03-19
	/// @return	 偏移
	//********************************************************************
	ICartesian3Vector* GetPositionOffset() { return m_PositionOffset; }

private:
	ICartesian3Vector*			m_PositionOffset;			//偏移
};

