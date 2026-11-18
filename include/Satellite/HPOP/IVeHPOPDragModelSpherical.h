#pragma once
#include "IVeHPOPDragModel.h"
class CSatellite;

///
/// 大气阻力摄动
///
class IATKOBJECT_API IVeHPOPDragModelSpherical : public IVeHPOPDragModel
{
public:
    IVeHPOPDragModelSpherical(const IVeHPOPDragModelSpherical&) = delete;
    IVeHPOPDragModelSpherical& operator=(const IVeHPOPDragModelSpherical&) = delete;

	IVeHPOPDragModelSpherical(CSatellite* pSate);
	~IVeHPOPDragModelSpherical();

	//********************************************************************
	/// 设置阻力面积
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dArea 阻力面积
	//********************************************************************
	void SetArea(double dArea);
	//********************************************************************
	/// 获得阻力面积
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	阻力面积
	//********************************************************************
	double GetArea();

	//********************************************************************
	/// 设置阻力系数
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dCd 阻力系数
	//********************************************************************
	void SetCd(double dCd);
	//********************************************************************
	/// 获得阻力系数
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	阻力系数
	//********************************************************************
	double GetCd();

private:
	CSatellite*     m_pSate;

};
