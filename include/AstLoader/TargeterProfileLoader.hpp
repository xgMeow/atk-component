/// @file      TargeterProfileLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-28

#pragma once

#include "AstGlobal.h"
#include "AstUtil/SharedPtr.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class TargeterProfile;



/// @brief 加载目标器配置
/// @param value 值
/// @param profile 目标器配置
/// @return 错误码
errc_t aLoadTargeterProfile(const Value& value, SharedPtr<TargeterProfile>& profile, Object* scope);


/*! @} */

AST_NAMESPACE_END
