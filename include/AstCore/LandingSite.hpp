/// @file      LandingSite.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-02

#pragma once

#include "AstGlobal.h"
#include "AstCore/Segment.hpp"
#include "AstCore/GeodeticPoint.hpp"
#include "AstCore/CelestialBody.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_CORE_API LandingSite: public Segment
{
public:
    AST_OBJECT(LandingSite)

    LandingSite() = default;
    ~LandingSite() override = default;
public:
    errc_t execute() override;

public: /* 配置属性 */
    /// @brief 获取着陆天体
    Body* body() const { return body_.get(); }
    /// @brief 设置着陆天体
    void setBody(Body* body) { body_ = body; }

    /// @brief 获取着陆点位置
    const GeodeticPoint& position() const { return position_; }
    /// @brief 设置着陆点位置
    void setPosition(const GeodeticPoint& pos) { position_ = pos; }

    /// @brief 获取着陆时间
    const TimePoint& epoch() const { return epoch_; }
    /// @brief 设置着陆时间
    void setEpoch(const TimePoint& epoch) { epoch_ = epoch; }
private:
    TimePoint     epoch_{};        ///< 着陆时间
    WeakPtr<Body> body_{};          ///< 着陆天体
    GeodeticPoint position_{};     ///< 着陆点位置
};


/*! @} */

AST_NAMESPACE_END

