#pragma once
#include "../../IAtkObj.h"
#include "IGreatArcGraphics.h"
struct CObjData;
class IVeGfxElevContours;
class IVeGfxSwath;

///
/// 飞机二维属性
///
class IATKOBJECT_API IAcGraphics :public IGreatArcGraphics
{
public:
    IAcGraphics(const IAcGraphics&) = delete;
    IAcGraphics& operator=(const IAcGraphics&) = delete;

	IAcGraphics(CObjData* pObjData);
	~IAcGraphics();

	//********************************************************************
	/// 获得二维等高线属性
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @return	二维等高线指针		
	//********************************************************************
	IVeGfxElevContours* GetElevContours() { return m_ElevContours; }

	//********************************************************************
	/// 获得二维刈幅
	/// @author	Gan Shu Long
	/// @date	2026-01-28
	/// @return	二维刈幅
	//********************************************************************
	IVeGfxSwath* GetSwath() { return m_Swath; }

private:
	IVeGfxElevContours*			m_ElevContours;	//等高线
	IVeGfxSwath*						m_Swath;									//二维刈幅
};
