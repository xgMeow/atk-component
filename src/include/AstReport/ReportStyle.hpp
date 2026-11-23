/// @file      ReportStyle.hpp
/// @brief     报表样式定义
/// @details   定义报表样式（ReportStyle）类型及相关枚举，
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-02

#pragma once

#include "AstGlobal.h"
#include "ReportSection.hpp"
#include "AstUtil/Color.hpp"

#include <string>
#include <vector>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup AstReport
    @{
*/

// 枚举定义见 ReportElement.hpp

/// @brief 报表样式
/// @details 对应 ReportStyle 文件的完整结构，包含文件头属性、图形显示参数
///          以及按 Section → Line → Element 组织的报表数据列定义。
class AST_REPORT_API ReportStyle
{
public:
    // ---- 标识 ----
    std::string name_;       ///< 报表名称（如 "Classical Orbit Elements"）
    std::string className_;  ///< 对象类型名（来自 ClassId 块的 Class 字段）

    // ---- 文件头属性 ----
    EStyleType  styleType_ = EStyleType::eTabular;
    std::string title_;          ///< 报表标题
    bool        showDate_      = true;
    bool        showName_      = true;
    bool        showDescShort_ = false;
    bool        showDescLong_  = false;

    // ---- 坐标轴/比例 ----
    bool yLog10_  = false;
    bool y2Log10_ = false;
    bool verticalGridLines_   = false;
    bool horizontalGridLines_ = false;
    int  numAnnotations_       = 3;
    int  annotationRotation_   = 1;

    // ---- 外观 ----
    Color  backgroundColor_  = Color(0xFFFFFFFF);   ///< 背景色（默认白色）
    double viewableDuration_ = 0.0;
    bool   realTimeMode_     = false;
    bool   readOnlyMode_     = false;
    int    dayLinesStatus_   = 1;
    int    legendStatus_     = 1;

    // ---- 数据段 ----
    std::vector<ReportSection> sections_;
};

/*! @} */

AST_NAMESPACE_END
