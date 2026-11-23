#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
#include "../../IClassInfo.h"
#include <vector>
struct CGfxSwath;
class IVeGfxElevation;

///
/// 刈幅
///
class IATKOBJECT_API IVeGfxSwath :public IClassInfo
{
public:
    IVeGfxSwath(const IVeGfxSwath&) = delete;
    IVeGfxSwath& operator=(const IVeGfxSwath&) = delete;

	IVeGfxSwath(CGfxSwath* pCGfxSwath);
	virtual ~IVeGfxSwath();

	//********************************************************************
	/// 是否支持类型
	/// @author	Gan Shu Long
	/// @date	2026-01-28
	/// @param[in]	eElevationType  类型
	/// @return	是否支持类型
	//********************************************************************
	bool IsElevationTypeSupported(EVeGfxElevation eElevationType);
	
	//********************************************************************
	/// 设置类型
	/// @author	Gan Shu Long
	/// @date	2026-01-28
	/// @param[in]	eElevationType  类型
	//********************************************************************
	void SetElevationType(EVeGfxElevation eElevationType);

	//********************************************************************
	/// 获得类型
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	/// @return	类型
	//********************************************************************
	EVeGfxElevation GetElevationType();

	//********************************************************************
	/// 获得支持类型
	/// @author	Gan Shu Long
	/// @date	2026-01-28
	/// @return	支持类型
	//********************************************************************
	std::vector<std::string> GetElevationSupportedTypes();

	//********************************************************************
	/// 获得夹角
	/// @author	Gan Shu Long
	/// @date	2026-01-28
	/// @return	夹角
	//********************************************************************
	IVeGfxElevation* GetElevation() { return m_Elevation; }
	
	//********************************************************************
	/// 设置显示设置类型
	/// @author	Gan Shu Long
	/// @date	2026-01-28
	/// @param[in]	eElevationType  类型
	//********************************************************************
	void SetOptions(EVeGfxOptions eElevationType);

	//********************************************************************
	/// 获得显示设置类型
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	/// @return	显示设置类型
	//********************************************************************
	EVeGfxOptions GetOptions();
		
private:
	CGfxSwath*								m_pCGfxSwath;							//C对象航线

	IVeGfxElevation*							m_Elevation;								//夹角
};



