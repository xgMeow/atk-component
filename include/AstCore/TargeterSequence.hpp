/// @file      TargeterSequence.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-28

#pragma once

#include "AstGlobal.h"
#include "Sequence.hpp"
#include "AstCore/TargeterProfile.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 目标序列段，用于建模并求解轨迹规划问题，可以定义多个控制变量、约束条件、目标函数等，调用求解器求解满足约束和最优的轨迹
class AST_CORE_API TargeterSequence : public Sequence
{
public:
    AST_OBJECT(TargeterSequence)

    TargeterSequence() = default;
    ~TargeterSequence() = default;

    /// @brief 设置目标序列段的目标配置
    /// @param profiles 目标配置列表
    void setProfiles(const std::vector<HTargeterProfile>& profiles){profiles_ = profiles;}

    TargeterProfile* getTargeterProfile(StringView name) const;


    errc_t execute() override;

private:
    std::vector<HTargeterProfile> profiles_{};
};




/*! @} */

AST_NAMESPACE_END
