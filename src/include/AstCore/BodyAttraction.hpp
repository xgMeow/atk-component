/// @file      BodyAttraction.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-21

#pragma once

#include "AstGlobal.h"
#include "AstCore/ForceModel.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class GravityForce;
class PointMassForce;
class ThirdBodyForce;

/// @brief 天体引力模型类型
enum class EBodyAttractionType
{
    eGravity,       ///< 中心天体重力场模型
    ePointMass,     ///< 中心天体点质量引力模型
    eUnknown,       ///< 未知引力模型类型
};


/// @brief 天体引力模型
class AST_CORE_API BodyAttraction: public ForceModel
{
public:
    AST_OBJECT(BodyAttraction)

    /// @brief 获取引力模型类型
    /// @return 引力模型类型
    virtual EBodyAttractionType getBodyAttractionType() const = 0;

    /// @brief 克隆引力模型
    /// @return 引力模型指针
    virtual BodyAttraction* clone() const = 0;

    /// @brief 检查是否为指定引力模型类型
    /// @param type 引力模型类型
    /// @return 是否为指定类型
    bool isAttractionType(EBodyAttractionType type) const{
        return getBodyAttractionType() == type;
    }

    /// @brief 尝试将引力模型转换为重力场模型
    /// @return 重力场模型指针
    const GravityForce* asGravityForce() const;
    GravityForce* asGravityForce();

    /// @brief 尝试将引力模型转换为点质量引力模型
    /// @return 点质量引力模型指针
    const PointMassForce* asPointMassForce() const;
    PointMassForce* asPointMassForce();
};



/*! @} */

AST_NAMESPACE_END
