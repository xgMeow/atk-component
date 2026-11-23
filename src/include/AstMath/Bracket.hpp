/// @file      Bracket.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-04

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 括号区间，包含左右边界和左右边界对应的值
class Bracket
{
public:
    Bracket(double leftAbscissa, double leftValue, double rightAbscissa, double rightValue)
        : leftAbscissa_(leftAbscissa), leftValue_(leftValue), rightAbscissa_(rightAbscissa), rightValue_(rightValue)
    {}
    /// @brief 获取左边界对应的横坐标
    double leftAbscissa() const{return leftAbscissa_;}
    /// @brief 获取左边界对应的值(函数值)
    double leftValue() const{return leftValue_;}
    /// @brief 获取右边界对应的横坐标
    double rightAbscissa() const{return rightAbscissa_;}
    /// @brief 获取右边界对应的值(函数值)
    double rightValue() const{return rightValue_;}

protected:
    double leftAbscissa_;
    double leftValue_;
    double rightAbscissa_;
    double rightValue_;
};

/*! @} */

AST_NAMESPACE_END

