/// @file      ReportSection.hpp
/// @brief     报表数据段定义
/// @details   定义报表中的数据段（ReportSection）类型，
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-02

#pragma once

#include "AstGlobal.h"
#include "ReportLine.hpp"

#include <string>
#include <vector>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup AstReport
    @{
*/

/// @brief 报表数据段
/// @details 对应 ReportStyle 文件中的 Section 块。
///          一个 Section 包含多个 Line，每个 Line 包含多个 Element。
class AST_REPORT_API ReportSection
{
public:
    std::string name_{};             ///< 段名称（如 "Section 1"）
    std::string className_{};        ///< 对象类型名（如 "Satellite", "Facility"）
    bool        nameInTitle_ = true;
    EExpandMethod expandMethod_ = EExpandMethod::eNone; ///< 展开方式
    int         propMask_     = 2;
    bool        showIntervals_ = false;
    int         numIntervals_  = 0;

    std::vector<ReportLine> lines_{};
};

/*! @} */

AST_NAMESPACE_END
