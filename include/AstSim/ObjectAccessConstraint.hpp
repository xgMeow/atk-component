/// @file      ObjectAccessConstraint.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-10-08

#pragma once

#include "AstGlobal.h"
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 访问约束类型
enum class EAccessConstraint
{
    eNone,                  ///< 无访问约束
    eFieldOfView,           ///< 视场约束
    eLineOfSight,           ///< 线视约束
    eElevationAngle,        ///< 仰角约束
    eRange,                 ///< 距离约束

    eAtFieldOfView,         ///< 暂不支持(含义尚不清楚)
};


AST_SIM_API std::string toString(EAccessConstraint type);
AST_SIM_API errc_t parse(StringView type, EAccessConstraint& result);


/// @brief 对象访问约束
class AST_SIM_API ObjectAccessConstraint
{
public:
    ObjectAccessConstraint() = default;
    explicit ObjectAccessConstraint(EAccessConstraint type) : type_(type) {}
    explicit ObjectAccessConstraint(StringView type);
    ~ObjectAccessConstraint() = default;

    EAccessConstraint type() const { return type_; }
    void setType(EAccessConstraint type) { type_ = type; }
    errc_t setType(StringView type);

    bool enabled() const { return enabled_; }
    void setEnabled(bool enabled) { enabled_ = enabled; }

    bool useMin() const { return useMin_; }
    void setUseMin(bool useMin) { useMin_ = useMin; }

    bool useMax() const { return useMax_; }
    void setUseMax(bool useMax) { useMax_ = useMax; }

    bool exclude() const { return exclude_; }
    void setExclude(bool exclude) { exclude_ = exclude; }

    double min() const { return min_; }
    void setMin(double min) { min_ = min; }

    double max() const { return max_; }
    void setMax(double max) { max_ = max; }

private:
    EAccessConstraint type_{EAccessConstraint::eNone};  ///< 访问约束类型
    bool enabled_{true};                                ///< 是否启用该访问约束
    bool exclude_{false};                               ///< 是否将满足本约束的时段从访问区间中剔除
    bool useMin_{false};                                ///< 是否使用最小值
    bool useMax_{false};                                ///< 是否使用最大值
    double min_{0.0};                                   ///< 最小值
    double max_{0.0};                                   ///< 最大值
};


/*! @} */

AST_NAMESPACE_END
