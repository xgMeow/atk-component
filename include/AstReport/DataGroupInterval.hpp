/// @file      DataGroupInterval.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-08-15

#pragma once

#include "AstGlobal.h"
#include "DataGroup.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_REPORT_API DataGroupInterval: public DataGroup
{
public:
    DataGroupInterval() = default;
    ~DataGroupInterval() = default;

    /// @brief 计算数据组
    /// @param interval 时间区间
    /// @param result 结果向量
    /// @return errc_t 错误码
    virtual errc_t calculate(const TimeInterval& interval, VariantVector& result) const = 0;
};

/*! @} */

AST_NAMESPACE_END
