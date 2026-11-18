/// @file      DataGroupTimeVar.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-05

#pragma once

#include "AstGlobal.h"
#include "DataGroup.hpp"
#include "AstCore/TimeList.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 随时间变化的数据组
class AST_REPORT_API DataGroupTimeVar : public DataGroup
{
public:
    DataGroupTimeVar() = default;
    ~DataGroupTimeVar() = default;

    /// @brief 计算数据组
    /// @param timeList 时间列表
    /// @param result 结果向量
    /// @return errc_t 错误码
    virtual errc_t calculate(const TimeList& timeList, VariantVector& result) const = 0;


};




/*! @} */

AST_NAMESPACE_END
