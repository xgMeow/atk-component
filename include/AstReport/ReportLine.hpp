/// @file      ReportLine.hpp
/// @brief     报表数据行定义
/// @details   定义报表中的数据行（ReportLine）类型，
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-02

#pragma once

#include "AstGlobal.h"
#include "ReportElement.hpp"

#include <vector>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup AstReport
    @{
*/

/// @brief 报表数据行
/// @details 对应 ReportStyle 文件中 Section 内的 Line 块。
///          每个 Line 包含多个 Element，在表格报告中对应一行数据列定义，
///          在图形样式中对应一条数据曲线。
class AST_REPORT_API ReportLine
{
public:
    std::string name_{};   ///< 行名称（如 "Line 1"）
    std::string title_{};  ///< 图形样式的 Y 轴/序列标题（表格样式不适用）

    std::vector<ReportElement> elements_{};
};

/*! @} */

AST_NAMESPACE_END
