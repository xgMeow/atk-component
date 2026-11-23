#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
#include "ICrdnAxes.h"


///
/// VGT元素 轨迹相关坐标轴
///
class IATKOBJECT_API ICrdnAxesTrajectory :public ICrdnAxes
{
public:
    ICrdnAxesTrajectory(const ICrdnAxesTrajectory&) = delete;
    ICrdnAxesTrajectory& operator=(const ICrdnAxesTrajectory&) = delete;

	ICrdnAxesTrajectory(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnAxesTrajectory();

	IATKOBJECT_VGT_SETGET_DECL(AxesType, ETrajectoryAxesType);
	IATKOBJECT_VGT_SETGET_VGT_DECL(Point);
	IATKOBJECT_VGT_SETGET_VGT_DECL(ReferenceSystem);
};
