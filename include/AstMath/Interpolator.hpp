/// @file      Interpolator.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-21

#pragma once

#include "AstGlobal.h"
#include "AstMath/VectorFunc.hpp"

AST_NAMESPACE_BEGIN

/*!
    @ingroup Math
    @defgroup Interpolator 插值功能
    @brief 提供插值相关计算函数与类
*/

/*!
    @ingroup Interpolator
    @{
*/


/// @brief 插值器接口
class Interpolator: public VectorFunc
{
public:
    virtual ~Interpolator() = default;

    /// @brief 计算插值结果
    /// @param x 输入值
    /// @param out 输出向量，长度需大于等于向量维度
    virtual void evaluate(double x, double* out) const override = 0;

    /// @brief 获取维度
    /// @return 维度
    virtual int getDimension() const override = 0;

};

/*! @} */


AST_NAMESPACE_END
