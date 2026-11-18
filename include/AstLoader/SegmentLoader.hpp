/// @file      SegmentLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-28

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class Segment;

/// @brief 加载段的公共属性
/// @param dict 段字典
/// @param segment 段
/// @return 错误码
errc_t aLoadSegment(const Value& dict, Segment& segment);



/*! @} */

AST_NAMESPACE_END
