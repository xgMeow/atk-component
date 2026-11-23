#pragma once
#include "../../../ICEnum.h"
#include "../IComponentInfo.h"

///
/// 停止条件
///
class IATKOBJECT_API IVAStoppingConditionComponent : public IComponentInfo
{
public:
    IVAStoppingConditionComponent(const IVAStoppingConditionComponent&) = delete;
    IVAStoppingConditionComponent& operator=(const IVAStoppingConditionComponent&) = delete;

	IVAStoppingConditionComponent();
	~IVAStoppingConditionComponent();

	EVAStoppingCondition GetStoppingConditionType();
};
