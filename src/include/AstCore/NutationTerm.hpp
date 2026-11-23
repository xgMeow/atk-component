/// @file      NutationTerm.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-10

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN


/// @brief IERS 2003/2010 岁差章动模型XYS系数
/// 参考 NutationSeries 类
class NutationTerm
{
public:
    AST_DEF_ACCESS_METHOD(double, sinCoeff)
    AST_DEF_ACCESS_METHOD(double, cosCoeff)
    AST_DEF_ACCESS_METHOD(int, nL)
    AST_DEF_ACCESS_METHOD(int, nLP)
    AST_DEF_ACCESS_METHOD(int, nF)
    AST_DEF_ACCESS_METHOD(int, nD)
    AST_DEF_ACCESS_METHOD(int, nOm)
    AST_DEF_ACCESS_METHOD(int, nMe)
    AST_DEF_ACCESS_METHOD(int, nVe)
    AST_DEF_ACCESS_METHOD(int, nE)
    AST_DEF_ACCESS_METHOD(int, nMa)
    AST_DEF_ACCESS_METHOD(int, nJu)
    AST_DEF_ACCESS_METHOD(int, nSa)
    AST_DEF_ACCESS_METHOD(int, nUr)
    AST_DEF_ACCESS_METHOD(int, nNe)
    AST_DEF_ACCESS_METHOD(int, nPa)
public:
    double sinCoeff_;
    double cosCoeff_;
    // 日月章动系数
    int nL_;
    int nLP_;
    int nF_;
    int nD_;
    int nOm_;
    // 行星章动系数
    int nMe_;
    int nVe_;
    int nE_;
    int nMa_;
    int nJu_;
    int nSa_;
    int nUr_;
    int nNe_;
    int nPa_;
};


AST_NAMESPACE_END
