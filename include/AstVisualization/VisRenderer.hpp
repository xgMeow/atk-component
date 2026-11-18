/// @file      VisRenderer.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-06

#pragma once

#include "AstGlobal.h"
#include "AstVisualizationGlobal.h"
#include "AstUtil/ObjectNamed.hpp"
#include "AstCore/TimePoint.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_VISUALIZATION_API VisRenderer
{
public:
    static VisRenderer* Default();
    static void SetDefault(VisRenderer* renderer);

    virtual ~VisRenderer() = default;

    /// @brief 渲染一个视图
    /// @param view 可视化视图
    /// @param epoch 渲染时刻（用于定位随时间变化的天体等场景元素）
    /// @return 错误码
    virtual errc_t render(const VisView& view, const TimePoint& epoch) = 0;
};

/*! @} */

AST_NAMESPACE_END
