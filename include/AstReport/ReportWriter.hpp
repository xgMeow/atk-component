/// @file      ReportWriter.hpp
/// @brief     数据报表生成
/// @details   根据 ReportStyle 模板，从对象中提取数据并写出报表。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-02

#pragma once

#include "AstGlobal.h"
#include "ReportStyle.hpp"
#include "AstCore/TimeInterval.hpp"

#include <cstdio>

AST_NAMESPACE_BEGIN

// 前置声明
class Object;

/*!
    @addtogroup AstReport
    @{
*/

class ReportGenerateOptions
{
public:
    bool useObjectInterval_{true};
    TimeInterval interval_{};
};

/// @brief 根据报表模板生成对象的数据报告
/// @param file   输出流
/// @param report 报表模板定义（Section → Line → Element 结构）
/// @param object 数据源对象
/// @return 错误码
AST_REPORT_API errc_t aWriteReport(const ReportStyle& report, const Object* object, FILE* file, const ReportGenerateOptions& options = ReportGenerateOptions{});

/*! @} */

AST_NAMESPACE_END
