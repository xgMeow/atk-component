/// @file      LagrangeInterpolator.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-22

#pragma once

#include "AstGlobal.h"
#include "Interpolator.hpp"

AST_NAMESPACE_BEGIN

/*!
   @ingroup Interpolator
   @{
*/



/// @brief 拉格朗日插值
/// @param arrX 插值节点
/// @param tableY 插值节点对应函数值
/// @param n 节点数
/// @param dimy 向量维度
/// @param x 输入值
/// @param y 输出向量，长度需大于等于向量维度
AST_MATH_API void aLagrangeInterpolate(const double arrX[], const double tableY[], int n, int dimy, double x, double* y);
AST_MATH_API void aLagrangeInterpolate2(const double arrX[], const double tableY[], int n, int dimy, double x, double* y);


/// @brief 拉格朗日插值
/// @param arrX 插值节点
/// @param tableY 插值节点对应函数值
/// @param n 节点数
/// @param dimy 向量维度
/// @param x 输入值
/// @param y 输出向量，长度需大于等于向量维度
/// @param workArray 工作数组，长度需大于等于节点数
AST_MATH_API void aLagrangeInterpolate(const double arrX[], const double tableY[], int n, int dimy, double x, double* y, double* workArray);

/// @brief 拉格朗日插值（针对等距节点优化）
/// @param arrX 插值节点
/// @param tableY 插值节点对应函数值
/// @param n 节点数
/// @param dimy 向量维度
/// @param x 输入值
/// @param y 输出向量，长度需大于等于向量维度
/// @param denomArray 分母数组，长度需大于等于节点数
AST_MATH_API void aLagrangeInterpolateFixedStep(const double arrX[], const double tableY[], int n, int dimy, double x, double* y, const double* denomArray);


/// @brief 计算拉格朗日插值的分母数组
/// @param n 节点数
/// @param step 等距节点间隔
/// @param denomArray 分母数组，长度需大于等于节点数
AST_MATH_API void aLagrangeInterpolateDenomArray(int n, double step, double* denomArray);

#if 0  // @todo

/// @brief 拉格朗日插值器
class LagrangeInterpolator: public Interpolator
{
public:
    /// @brief 构造函数
    /// @param x 插值节点
    /// @param y 插值节点对应函数值
    /// @param n 节点数
    LagrangeInterpolator(int order, bool fixedStep, double step);

    /// @brief 析构函数
    ~LagrangeInterpolator() override;
    LagrangeInterpolator(const LagrangeInterpolator&) = delete;
    LagrangeInterpolator& operator=(const LagrangeInterpolator&) = delete;

    /// @brief 计算插值结果
    /// @param x 输入值
    /// @param out 输出向量，长度需大于等于向量维度
    void evaluate(double x, double* out) const override;

    /// @brief 获取维度
    /// @return 维度
    int getDimension() const override;

protected:
    double* workArray_;     ///< 工作数组
    double* denomArray_;    ///< 分母数组
    double* xtable_;        ///< 
    double* ytable_;        ///<
    int dimtable_;          ///< 表格维度
    int dim_;               ///< 向量维度
    int order_;             ///< 插值阶数
};

#endif


/*! @} */


AST_NAMESPACE_END
