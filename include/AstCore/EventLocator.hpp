/// @file      EventLocator.hpp
/// @brief     事件区间定位
/// @details   在给定区间内搜索一元标量函数的事件区间。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-10-11

#pragma once

#include "AstGlobal.h"
#include "AstCore/Interval.hpp"
#include "AstCore/IntervalList.hpp"
#include "AstMath/Function.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/

class Stepper;

/// @brief 在给定区间内搜索一元标量函数的事件区间
/// @details 
/// 按步进策略对函数采样，检测相邻采样点之间的符号翻转，再用Brent/二分法精化过零点（即事件）
/// 最后输出函数值非负（含零容差）的子区间集合。
/// 另根据相邻步的采样斜率符号变化检测步内是否局部极值：
/// 极值可能跨零时做一次极小化，
/// 非事件区间内的凸起会输出区间，事件区间内的凹陷会排除该区间（仅在极值唯一时可靠）
/// @param func 一元标量函数，自变量通常为相对时间（秒）
/// @param stepper 步进策略，其自变量与 func 的自变量为同一坐标
/// @param interval 搜索区间
/// @param intervals 输出的事件区间列表（先清空）
/// @return 错误码
AST_CORE_API errc_t aFindEventIntervals(
    UnaryScalarFunc& func,
    Stepper& stepper,
    const Interval& interval,
    IntervalList& intervals
);

#ifdef AST_BUILD_LIB
errc_t _aFindEventIntervals_Append(
    UnaryScalarFunc& func,
    Stepper& stepper,
    const Interval& interval,
    IntervalList& intervals
);
#endif

/*! @} */

AST_NAMESPACE_END
