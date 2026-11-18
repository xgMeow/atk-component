/// @file      NutationSeries.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-10

#pragma once

#include "AstGlobal.h"
#include "NutationTerm.hpp"
#include "AstUtil/Polynomial.hpp"
#include <vector>

AST_NAMESPACE_BEGIN

class BKVParser;
class FundamentalArguments;

/// @brief IERS 2003/2010 岁差章动模型XYS系数表
/// @details 
/// 参考IERS技术手册36的表5.2a 5.2b 5.2d
/// 下载地址：ftp://tai.bipm.org
class AST_CORE_API NutationSeries{
public:
    /// @brief 从文件加载nutation series
    /// @param filepath 文件路径
    /// @return errc_t
    errc_t load(StringView filepath);

    /// @brief 从STK文件加载nutation series
    /// @param filepath STK文件路径
    /// @return errc_t
    errc_t loadSTK(StringView filepath);

    /// @brief 从IERS文件加载nutation series
    /// @param filepath IERS文件路径
    /// @return errc_t
    errc_t loadIERS(StringView filepath);

    /// @brief 根据系数表计算值
    /// @param t 时间
    /// @param args 章动理论所涉及的行星基本轨道参数
    /// @return double
    double eval(double t, const FundamentalArguments& fundargs) const;

    /// @brief 根据系数表计算值
    /// @param tp 时间点
    /// @param args 章动理论所涉及的行星基本轨道参数
    /// @return double
    double eval(const TimePoint& tp, const FundamentalArguments& fundargs) const;

    /// @brief 检查是否加载了系数表
    /// @return bool
    bool isLoaded() const {return !terms_.empty();}
protected:

    errc_t loadSTK(BKVParser& parser);

    errc_t loadIERS(BKVParser& parser);

protected:
    Polynomial polynomial_{};             ///< nutation series多项式
    std::vector<NutationTerm> terms_{};   ///< nutation series系数表
    std::vector<int> jlist_{};            ///< 
};


AST_NAMESPACE_END
