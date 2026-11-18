/// @file      Util.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-30

#pragma once

#include "AstGlobal.h"
#include <complex>
#include <string>

AST_NAMESPACE_BEGIN

/// @brief 将列主序矩阵转换为字符串
/// @param matrix 列主序矩阵
/// @param rows 矩阵行数
/// @param cols 矩阵列数
/// @return 矩阵字符串表示
AST_MATH_API std::string aColMajorMatrixToString(const double* matrix, int rows, int cols);


/// @brief 打印列主序矩阵到文件
/// @param matrix 列主序矩阵
/// @param rows 矩阵行数
/// @param cols 矩阵列数
/// @param file 输出文件指针，默认打印到标准输出
AST_MATH_CAPI void aColMajorMatrixPrint(const double* matrix, int rows, int cols, FILE* file = stdout);


/// @brief 求解一元二次方程 ax² + bx + c = 0
/// @param a 二次项系数
/// @param b 一次项系数
/// @param c 常数项
/// @param root1 第一个实根（当有实根时）
/// @param root2 第二个实根（当有两个实根时）
/// @return 实根个数：2（两个不同实根），1（一个重根），0（无实根，有一对共轭复根）
/// @note 当 a=0 时方程退化为 bx + c = 0，此时若 b≠0 则返回 1 个根，否则返回 0
AST_MATH_API int aSolveQuadratic(double a, double b, double c, double& root1, double& root2);


/// @brief 求解一元二次方程 ax² + bx + c = 0（含复根）
/// @param a 二次项系数
/// @param b 一次项系数
/// @param c 常数项
/// @param root1 第一个根
/// @param root2 第二个根
/// @note 实根时虚部为零，复根时互为共轭且 root1 为负虚部
AST_MATH_API void aSolveQuadraticComplex(double a, double b, double c,
                                         std::complex<double>& root1,
                                         std::complex<double>& root2);


AST_NAMESPACE_END
