/// @file      Function.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-25

#pragma once

#include "AstGlobal.h"
#include "UnaryScalarFunc.hpp"
#include "UnaryVectorFunc.hpp"
#include "ScalarFunc.hpp"
#include "VectorFunc.hpp"


AST_NAMESPACE_BEGIN

/*
 * 含义解释：
 * 1. 一元：指函数只有一个变量，如 f(x) = x^2
 * 2. 多元：指函数有多个变量，如 f(x, y) = x^2 + y^2
 * 3. 标量：指函数的返回值是一个标量，如 f(x) = x^2
 * 4. 向量：指函数的返回值是一个向量，如 f(x) = [x, x^2]
 * 
 * 单词解释：
 * unary/univariate 一元
 * multivariate  多元
 * scalar 标量
 * vector 向量
 * 
 * 类型命名规则：
 * 1. 一元标量值函数：UnaryScalarFunc  (一元函数/标量函数)
 * 2. 一元向量值函数：UnaryVectorFunc 
 * 3. 多元标量值函数：MultivariateScalarFunc 
 * 4. 多元向量值函数：MultivariateVectorFunc 
 * 
 * 注意，在**不严格的定义**下，多元可以涵盖一元，向量可以涵盖标量。
 * 
 */


const double kDefaultRelTol = 1e-14;
const double kDefaultAbsTol = 1e-12;
const int kDefaultMaxIter = 100;


AST_NAMESPACE_END
