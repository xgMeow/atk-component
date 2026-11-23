/// @file      DifferentialCorrectorLoader.hpp
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


class DifferentialCorrectorProfile;
class Value;

/// @brief 加载DifferentialCorrector配置
/// @details value 值
/// @param profile 输出载入的DifferentialCorrector对象
/// @return errc_t 加载结果
errc_t aLoadDifferentialCorrectorProfile(const Value& value, DifferentialCorrectorProfile& profile);


/*! @} */

AST_NAMESPACE_END
