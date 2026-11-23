/// @file      Calculation.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-02-08

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN


/// @brief 计算量基类
/// 该类是一个抽象类，不能直接实例化
/// 具体的计算量类需要继承该类，并实现evaluate方法
/// @note
/// 该模块的类型与参数定义参考了NASA的[WebGeoCalc](https://wgc.jpl.nasa.gov:8443/webgeocalc/)软件的接口设计与相关功能
/// 详细也可以参考WebGeoCalc的[python接口文档](https://webgeocalc.readthedocs.io/en/latest/)
class AST_CALC_API Calculation
{
public:
    Calculation() = default;
    virtual ~Calculation() = default;
    virtual errc_t evaluate(const TimePoint& tp, double& result) const = 0;
};


AST_NAMESPACE_END
