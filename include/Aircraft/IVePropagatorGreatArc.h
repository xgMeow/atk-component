#pragma once
#include "../Satellite/Propagator/IVePropagator.h"
#include "IVeWaypointsCollection.h"
struct CObjData;

///
/// 路径生成预报器
///
class IATKOBJECT_API IVePropagatorGreatArc : public IVePropagator
{
public:
    IVePropagatorGreatArc(const IVePropagatorGreatArc&) = delete;
    IVePropagatorGreatArc& operator=(const IVePropagatorGreatArc&) = delete;

	IVePropagatorGreatArc(CObjData* pObjData);
	~IVePropagatorGreatArc();

	IVeWaypointsCollection* GetWaypoints();

private:
	CObjData*							m_pObjData;
	IVeWaypointsCollection*		m_Waypoints;		//路径点

};
