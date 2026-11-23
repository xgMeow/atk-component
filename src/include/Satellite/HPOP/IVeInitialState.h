#pragma once
#include "../../IAtkObj.h"
class CObjManage;
class CSatellite;
class CPreOrbitParam;
class ISatellite;
class IOrbitState;

///
/// 轨道状态
///
class IATKOBJECT_API IVeInitialState
{
public:
    IVeInitialState(const IVeInitialState&) = delete;
    IVeInitialState& operator=(const IVeInitialState&) = delete;

	IVeInitialState(CSatellite* pSate, ISatellite* pISate, CObjManage* IAsGObjManage);
	~IVeInitialState();

	//********************************************************************
	/// 获得HPOP轨道的轨道状态属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	轨道状态属性指针
	//********************************************************************
	IOrbitState* GetRepresentation();

private:
	CSatellite*                     m_pSate;
	CObjManage*                     m_IAsGObjManage;
	CPreOrbitParam*                 m_pPreOrbitParam;

	IOrbitState*                    m_Representation;   //HPOP轨道的轨道状态属性

};
