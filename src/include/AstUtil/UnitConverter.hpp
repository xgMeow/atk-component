/// @file      UnitConverter.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-15

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Unit.hpp"

AST_NAMESPACE_BEGIN


/// @brief 单位转换器
/// @ingroup Quantity
class UnitConverter
{
public:
    UnitConverter()
        :fromUnit_(Unit())
        , toUnit_(Unit())
    {}

    UnitConverter(Unit fromUnit, Unit toUnit)
        : fromUnit_(fromUnit)
        , toUnit_(toUnit)
    {}

    /// @brief 转换单位
    /// @param value 待转换的值
    /// @return 转换后的值
    double convert(double value) const{return fromUnit_.convertTo(value, toUnit_);}

    /// @brief 获取转换前的单位
    /// @return 转换前的单位
    Unit getFromUnit() const{return fromUnit_;}

    /// @brief 获取转换后的单位
    /// @return 转换后的单位
    Unit getToUnit() const{return toUnit_;}

    /// @brief 设置转换前的单位
    void setFromUnit(Unit fromUnit){fromUnit_ = fromUnit;}

    /// @brief 设置转换后的单位
    void setToUnit(Unit toUnit){toUnit_ = toUnit;}

protected:
    Unit fromUnit_;                 ///< 转换前的单位
    Unit toUnit_;                   ///< 转换后的单位
};

AST_NAMESPACE_END
