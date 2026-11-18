/// @file      DataGroupFixed.hpp
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

class AST_REPORT_API DataGroupFixed: public DataGroup
{
public:
    DataGroupFixed() = default;
    ~DataGroupFixed() = default;

    /// @brief 计算数据组
    /// @param result 结果向量
    /// @return errc_t 错误码
    virtual errc_t calculate(VariantVector& result) const = 0;
};


/*! @} */

AST_NAMESPACE_END
