#pragma once
#include "IVeVOProximityAreaObject.h"
struct CObjData;
struct CGfxControlBox;

///
/// 三维抵近控制盒
///
class IATKOBJECT_API IVeVOControlBox : public IVeVOProximityAreaObject
{
public:
    IVeVOControlBox(const IVeVOControlBox&) = delete;
    IVeVOControlBox& operator=(const IVeVOControlBox&) = delete;

	IVeVOControlBox(CGfxControlBox* pCGfxControlBox);
	~IVeVOControlBox();

	//********************************************************************
	/// 设置X轴长度
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dXAxisLen  X轴长度
	//********************************************************************
	void SetXAxisLength(double dXAxisLen);
	//********************************************************************
	/// 获得X轴长度
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	X轴长度		
	//********************************************************************
	double GetXAxisLength();

	//********************************************************************
	/// 设置Y轴长度
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dYAxisLen  Y轴长度
	//********************************************************************
	void SetYAxisLength(double dYAxisLen);
	//********************************************************************
	/// 获得Y轴长度
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	Y轴长度	
	//********************************************************************
	double GetYAxisLength();

	//********************************************************************
	/// 设置Z轴长度
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dZAxisLen  Z轴长度
	//********************************************************************
	void SetZAxisLength(double dZAxisLen);
	//********************************************************************
	/// 获得Z轴长度
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	Z轴长度	
	//********************************************************************
	double GetZAxisLength();

	//********************************************************************
	/// 设置X轴偏移量
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dXOffset  X轴偏移量
	//********************************************************************
	void SetXOffset(double dXOffset);
	//********************************************************************
	/// 获取X轴偏移量
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	X轴偏移量
	//********************************************************************
	double GetXOffset();

	//********************************************************************
	/// 设置Y轴偏移量
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dYOffset  Y轴偏移量
	//********************************************************************
	void SetYOffset(double dYOffset);
	//********************************************************************
	/// 获取Y轴偏移量
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	Y轴偏移量
	//********************************************************************
	double GetYOffset();

	//********************************************************************
	/// 设置Z轴偏移量
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dZOffset  Z轴偏移量
	//********************************************************************
	void SetZOffset(double dZOffset);
	//********************************************************************
	/// 获取Z轴偏移量
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	Z轴偏移量
	//********************************************************************
	double GetZOffset();

private:
	CGfxControlBox*              m_pCGfxControlBox;			//C对象控制盒指针
};
