/// @file      RotationElement.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-02-20

#pragma once

#include "AstGlobal.h"
#include <vector>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup SolarSystem
    @{
*/

class BKVParser;

/// @brief 行星旋转根数
/// @details 描述行星旋转状态的系数
class AST_CORE_API RotationElement
{
public:
    struct Coefficient
    {
        double amplitude_ {0.0};
        double constant_ {0.0};
        double rate_ {0.0};
        double rateDot_ {0.0};
    };

    RotationElement() = default;
    ~RotationElement() = default;

    double constant() const { return constant_; }
    double rate() const { return rate_; }
    double rateDot() const { return rateDot_; }
    bool isSine() const { return isSine_; }
    errc_t load(BKVParser &parser);
protected:
    friend class RotationalData;

    /// @brief 计算导数值
    double evaluateDot(bool isRotation, double t, double d) const;
    /// @brief 计算多项式项和三角函数项
    double evaluate(double t_or_d,double t, double d) const;
    /// @brief 计算t=d=0时的多项式项和三角函数项
    double evaluateZero() const;

    /// @brief 仅计算多项式项
    double evaluatePoly(double t_or_d, double t) const;
    /// @brief 计算t=d=0时的多项式项
    double evaluatePolyZero() const;
protected:
    double constant_ {0.0};
    double rate_ {0.0};
    double rateDot_ {0.0};
    bool isSine_ {false};
    std::vector<Coefficient> coefficients_{};
};


/*! @} */

AST_NAMESPACE_END
