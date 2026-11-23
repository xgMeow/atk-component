/// @file      BurnLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-18

#pragma once

#include "AstGlobal.h"
#include "AstUtil/SharedPtr.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class Burn;
class BurnFinite;
class BurnImpulsive;
class BurnCollocation;

/// @brief 加载有限推力点火
/// @param value 值
/// @param burn 有限推力点火
/// @return 错误码
errc_t aLoadBurnFinite(const Value &value, BurnFinite &burn);


/// @brief 加载脉冲推力点火
/// @param value 值
/// @param burn 脉冲推力点火
/// @return 错误码
errc_t aLoadBurnImpulsive(const Value &value, BurnImpulsive &burn);


/// @brief 加载正交配置推力点火
/// @param value 值
/// @param burn 正交配置推力点火
/// @return 错误码
errc_t aLoadBurnCollocation(const Value &value, BurnCollocation &burn);



/// @brief 加载发动机点火
/// @param value 值
/// @param burn 发动机点火
/// @return 错误码
errc_t aLoadBurn(const Value& value, SharedPtr<Burn>& burn);

/*! @} */

AST_NAMESPACE_END
