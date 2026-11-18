/// @file      DataGroup.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-02

#pragma once

#include "AstGlobal.h"
#include "DataElements.hpp"
#include "AstUtil/StringView.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 数据组基类
class AST_REPORT_API DataGroup
{
public:
    virtual ~DataGroup() = default;

    virtual const DataElements& getElements() const = 0;

    /// @brief 从数据组中提取数据
    /// @param data 数据
    /// @param name 数据名称
    /// @param result 结果
    /// @return 错误码
    errc_t extract(const VariantVector& data, StringView name, VariantVector& result) const;
};



/*! @} */

AST_NAMESPACE_END
