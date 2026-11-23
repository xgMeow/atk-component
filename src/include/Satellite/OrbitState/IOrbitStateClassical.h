#pragma once
#include "../../ICEnum.h"
#include <vector>
#include <string>
#include "IOrbitState.h"
class CObjManage;
class CSatellite;
class CPreOrbitParam;
class IClassicalLocation;
class IClassicalOrientation;
class IClassicalSizeShape;

///
/// 预报器轨道根数设置
///
class IATKOBJECT_API IOrbitStateClassical : public IOrbitState
{
public:
    IOrbitStateClassical(const IOrbitStateClassical&) = delete;
    IOrbitStateClassical& operator=(const IOrbitStateClassical&) = delete;

	IOrbitStateClassical(CSatellite* pSate, CObjManage* IAsGObjManage, CPreOrbitParam* pPreOrbitParam);
	~IOrbitStateClassical();

	//********************************************************************
	/// 获得Location类型属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	Location类型属性
	//********************************************************************
	IClassicalLocation* GetLocation();

	//********************************************************************
	/// 设置Location类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eLType Location类型
	//********************************************************************
	void SetLocationType(EClassicalLocation eLType);
	//********************************************************************
	/// 获得Location类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	Location类型
	//********************************************************************
	EClassicalLocation GetLocationType();

	//********************************************************************
	/// 获得方向属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	方向属性
	//********************************************************************
	IClassicalOrientation* GetOrientation();

	//********************************************************************
	/// 获得SizeShape类型属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	SizeShape类型属性指针
	//********************************************************************
	IClassicalSizeShape* GetSizeShape();

	//********************************************************************
	/// 设置SizeShape类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eSSType SizeShape类型
	//********************************************************************
	void SetSizeShapeType(EClassicalSizeShape eSSType);
	//********************************************************************
	/// 获得SizeShape类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	SizeShape类型
	//********************************************************************
	EClassicalSizeShape GetSizeShapeType();

private:
	CSatellite*                  m_pSate;
	CPreOrbitParam*              m_pPreOrbitParam;

	IClassicalLocation*          m_Location;                         //Location类型属性
	IClassicalOrientation*       m_Orientation;                      //方向属性
	IClassicalSizeShape*         m_SizeShape;                        //SizeShape类型属性
};
