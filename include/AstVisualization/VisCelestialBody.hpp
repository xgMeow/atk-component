/// @file      VisCelestialBody.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-06

#pragma once

#include "AstGlobal.h"
#include "VisObject.hpp"
#include "AstCore/CelestialBody.hpp"
#include "AstUtil/StringView.hpp"

#include <string>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


class AST_VISUALIZATION_API VisCelestialBody: public VisObject
{
public:
    VisCelestialBody() = default;
    ~VisCelestialBody() = default;

    /// @brief 访问者分派
    void accept(VisVisitor& visitor) override;

    /// @brief 获取天体指针
    Body* body() const { return body_.get(); }
    void setBody(Body* body) { body_ = body; }

    /// @brief 天体半径（米），无天体时返回 0
    double radius() const { Body* b = body_.get(); return b ? b->getRadius() : 0.0; }

    /// @brief 显式纹理路径（空表示自动探测）
    /// @return 纹理路径
    const std::string& texture() const { return texture_; }

    /// @brief 设置显式纹理路径
    /// @param path 纹理文件路径
    void setTexture(StringView path) { texture_ = std::string(path); }

    /// @brief 实际纹理路径：显式设置优先，否则按 <天体目录>/<天体名><扩展名> 自动探测
    /// @return 纹理文件路径；找不到时返回空
    std::string effectiveTexture() const;

private:
    WeakPtr<Body>     body_{};
    std::string       texture_{};
};


/// @brief 自动探测天体纹理文件路径
/// @details 按 <天体目录>/<天体名>.<扩展名> 依次尝试 .jpg/.jpeg/.png/.bmp
/// @param body 天体指针；可为 nullptr
/// @return 纹理文件路径；找不到时返回空
AST_VISUALIZATION_API std::string aFindBodyTexture(const Body* body);

/*! @} */

AST_NAMESPACE_END
