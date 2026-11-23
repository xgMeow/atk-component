/// @file      Bounds.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-08-28

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 参数的上下界
template <typename T = double>
class Bounds
{
public:
    Bounds() = default;
    Bounds(T lower, T upper) : lower_(lower), upper_(upper) {}
    T lower() const { return lower_; }
    T upper() const { return upper_; }
    T& lower() { return lower_; }
    T& upper() { return upper_; }
    void setLower(T lower) { lower_ = lower; }
    void setUpper(T upper) { upper_ = upper; }
private:
    T lower_{};
    T upper_{};
};


using DoubleBounds = Bounds<double>;
using IntBounds = Bounds<int>;


/*! @} */

AST_NAMESPACE_END
