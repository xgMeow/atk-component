/// @file      PointCartographic.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-01

#pragma once

#include "AstGlobal.h"
#include "AstCore/Point.hpp"
#include "AstCore/CelestialBody.hpp"
#include "AstCore/GeodeticPoint.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 天地制图坐标点(天体大地坐标点)
class AST_CORE_API PointCartographic final: public Point
{
public:
    PointCartographic() = default;
    /// @param body 天体
    PointCartographic(Body* body);
    /// @param body 天体
    /// @param position 在天体上的位置点（大地坐标）
    PointCartographic(Body* body, const GeodeticPoint& position);
    ~PointCartographic() override = default;
public:
    Frame* getFrame() const override;
    errc_t getPos(const TimePoint& tp, Vector3d& pos) const override;
    errc_t getPosVel(const TimePoint& tp, Vector3d& pos, Vector3d& vel) const override;
public:
    Body* body() const { return body_.get(); }
    void setBody(Body* body);
    BodyShape* shape() const { return shape_.get(); }
    const GeodeticPoint& position() const { return position_; }
    void setPosition(const GeodeticPoint& position) { position_ = position; }
public:
    void setLatitude(double latitude) {position_.setLatitude(latitude);}
    void setLongitude(double longitude) {position_.setLongitude(longitude);}
    void setAltitude(double altitude) {position_.setAltitude(altitude);}
    double latitude() const {return position_.latitude();}
    double longitude() const {return position_.longitude();}
    double altitude() const {return position_.altitude();}
private: // 模型配置参数
    GeodeticPoint position_{};              ///< 在天体上的位置点（大地坐标）
    WeakPtr<Body> body_{};                  ///< 天体
private: // 内部缓存
    WeakPtr<BodyShape> shape_{};            ///< 天体形状
};


/*! @} */

AST_NAMESPACE_END
