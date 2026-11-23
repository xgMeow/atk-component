/// @file      Facility.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-13

#pragma once

#include "AstGlobal.h"
#include "AstCore/Point.hpp"
#include "AstCore/GeodeticPoint.hpp"
#include "AstCore/CelestialBody.hpp"
#include "AstCore/PointCartographic.hpp"
#include "AstSim/Platform.hpp"
#include "AstSim/CentroidPosition.hpp"
#include "AstUtil/StringView.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class Facility;
using HFacility = SharedPtr<Facility>;
using PFacility = Facility*;


/// @brief 设施对象
class AST_SIM_API Facility: public Platform
{
public:
    AST_OBJECT(Facility)
    AST_PROPERT(latitude)
    AST_PROPERT(longitude)
    AST_PROPERT(altitude)
    AST_PROPERT(body)
    Facility();
    ~Facility() override = default;
public: // 从Point继承重写的函数
    Frame* getFrame() const final;
    errc_t getPos(const TimePoint& tp, Vector3d& pos) const final;
    errc_t getPosVel(const TimePoint& tp, Vector3d& pos, Vector3d& vel) const final;
public:
    const GeodeticPoint& position() const {return cartographic().position();}
    void setPosition(const GeodeticPoint& position){cartographic().setPosition(position);}
PROPERTIES:
    angle_d latitude() const {return cartographic().latitude();}
    void setLatitude(angle_d latitude) {cartographic().setLatitude(latitude);}

    angle_d longitude() const {return cartographic().longitude();}
    void setLongitude(angle_d longitude) {cartographic().setLongitude(longitude);}

    length_d altitude() const {return cartographic().altitude();}
    void setAltitude(length_d altitude) {cartographic().setAltitude(altitude);}

    Body* body() const {return cartographic().body();}
    void setBody(Body* body) {cartographic().setBody(body);}
protected:
    PointCartographic& cartographic() {return static_cast<PointCartographic&>(*location());}
    const PointCartographic& cartographic() const {return static_cast<const PointCartographic&>(*location());}
private: // 屏蔽基类public函数
    void setLocation(Point* location) = delete;
};

/*! @} */

AST_NAMESPACE_END