/// @file      ForceModel.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-21

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Object.hpp"
#include "AstUtil/ObjectNamed.hpp"
#include "AstCore/SunPosition.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup ForceModel
    @{
*/



/// @brief 引力常数来源
enum class EGMSource
{
    eBodyGravity,           ///< 天体的引力常数
    eSystemGravity,         ///< 天体系引力常数（考虑天体的卫星）
    eJplDE,                 ///< 来自JPL DE星历的引力常数
    eSpecifiedValue,        ///< 用户指定的引力常数
};


/// @brief 力模型
/// @details 力模型用于表示动力学系统中的摄动力，例如重力、大气阻力、太阳光压、三体摄动等
class AST_CORE_API ForceModel: public ObjectNamed
{
public:
    AST_OBJECT(ForceModel)

    ForceModel() = default;
    virtual ~ForceModel() = default;

};

/*! @} */

AST_NAMESPACE_END
