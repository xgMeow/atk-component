/// @file      FundamentalArguments.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-10

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN


class FundamentalArguments;


/// @brief 计算IERS 2010年规范章动理论所涉及的行星基本轨道参数
/// @details 
/// 参考IERS技术手册36(IERS Technical Note 36)的公式5.43和公式5.44
/// https://www.iers.org/IERS/EN/Publications/TechnicalNotes/TechnicalNotes
/// @param t 儒略世纪数（Julian Century），以2000年1月1日12:00:00 TDB为基准
/// @param fundargs 输出行星基本轨道参数
AST_CORE_CAPI void aFundamentalArguments_IERS2010(double t, FundamentalArguments& fundargs);


/// @brief 计算IERS 2003年规范章动理论所涉及的行星基本轨道参数
/// @details 
/// 参考IERS技术手册32(IERS Technical Note 32)的公式 40 和公式 41
/// https://www.iers.org/IERS/EN/Publications/TechnicalNotes/TechnicalNotes
/// @param t 儒略世纪数（Julian Century），以2000年1月1日12:00:00 TDB为基准
/// @param fundargs 输出行星基本轨道参数
AST_CORE_CAPI void aFundamentalArguments_IERS2003(double t, FundamentalArguments& fundargs);


/// @brief 归一化章动理论所涉及的行星基本轨道参数的角度到[0, 2π)区间
/// @param fundargs 输入输出行星基本轨道参数
AST_CORE_CAPI void aFundamentalArgumentsNormalizeAngle0To2Pi(FundamentalArguments& fundargs);

/// @brief IERS规范中章动理论所涉及的行星基本轨道参数
class FundamentalArguments
{
public:
    AST_DEF_ACCESS_METHOD(double, l)
    AST_DEF_ACCESS_METHOD(double, lP)
    AST_DEF_ACCESS_METHOD(double, f)
    AST_DEF_ACCESS_METHOD(double, d)
    AST_DEF_ACCESS_METHOD(double, om)
    AST_DEF_ACCESS_METHOD(double, lMe)
    AST_DEF_ACCESS_METHOD(double, lVe)
    AST_DEF_ACCESS_METHOD(double, lE)
    AST_DEF_ACCESS_METHOD(double, lMa)
    AST_DEF_ACCESS_METHOD(double, lJu)
    AST_DEF_ACCESS_METHOD(double, lSa)
    AST_DEF_ACCESS_METHOD(double, lUr)
    AST_DEF_ACCESS_METHOD(double, lNe)
    AST_DEF_ACCESS_METHOD(double, pa)
public:
    // 日月章动相关轨道参数
    double l_;          ///< Mean Anomaly of the Moon
    double lP_;         ///< Mean Anomaly of the Sun 
    double f_;          ///< Mean longitude of Moon minus mean longitude of Moon's node. (L - Ω), where L is the Mean Longitude of the Moon
    double d_;          ///< Mean Elongation of the Moon from the Sun
    double om_;         ///< Mean Longitude of the Ascending Node of the Moon on the ecliptic, measured from the mean equinox of date. (Ω)
    // 行星章动相关轨道参数
    double lMe_;        ///< Mean Anomaly of the Mercury.
    double lVe_;        ///< Mean Anomaly of the Venus.
    double lE_;         ///< Mean Anomaly of the Earth.
    double lMa_;        ///< Mean Anomaly of the Mars.
    double lJu_;        ///< Mean Anomaly of the Jupiter.
    double lSa_;        ///< Mean Anomaly of the Saturn.
    double lUr_;        ///< Mean Anomaly of the Uranus.
    double lNe_;        ///< Mean Anomaly of the Neptune.
    double pa_;         ///< General accumulated precession in longitude.
};


AST_NAMESPACE_END

