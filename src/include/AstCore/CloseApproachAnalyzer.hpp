/// @file      CloseApproachAnalyzer.hpp
/// @brief     接近分析编排器
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-08-19

#pragma once

#include "AstGlobal.h"
#include "CloseApproachOptions.hpp"
#include "CloseApproachResult.hpp"
#include "AstCore/TLE.hpp"
#include "AstCore/TLEDatabase.hpp"
#include <vector>

AST_NAMESPACE_BEGIN

/// @brief 接近分析编排器
/// @details 给定参考对象（TLE）与候选目录，按 STK CAT 顺序执行
///          过期 → 近/远地点 → 轨道路径 → 时间 四级预过滤，再对幸存对象
///          做暴力采样检测与最近点精化，输出接近结果。
class AST_CORE_API CloseApproachAnalyzer
{
public:
    explicit CloseApproachAnalyzer(const CloseApproachOptions& opts);

    /// @brief 在 TLE 目录中搜索与参考对象的接近事件
    /// @param reference 参考对象 TLE
    /// @param catalog   TLE 目录
    /// @param report    输出报告
    /// @return 错误码
    errc_t analyze(const TLE& reference, const TLEDatabase& catalog, CloseApproachReport& report);

    /// @brief 在 TLE 列表中搜索与参考对象的接近事件
    /// @param reference  参考对象 TLE
    /// @param candidates 候选 TLE 列表
    /// @param report     输出报告
    /// @return 错误码
    errc_t analyze(const TLE& reference, const std::vector<TLE>& candidates, CloseApproachReport& report);

private:
    CloseApproachOptions opts_;
};

AST_NAMESPACE_END
