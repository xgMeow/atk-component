/// @file      CentroidPosition.hpp
/// @brief     质心位置类
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"
#include "AstUtil/SharedPtr.hpp"
#include "AstCore/GeodeticPoint.hpp"
#include "AstCore/PointCartographic.hpp"


AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

#if 0
/// @brief 质心位置类
/// @details 表示对象在空间中的质心位置
class AST_SIM_API CentroidPosition
{
public:
    CentroidPosition() = default;
    ~CentroidPosition() = default;

    void setBody(Body* body);
    Body* body() const{return body_.get();}
    const GeodeticPoint& getPosition() const{return position_;}
    void setPosition(const GeodeticPoint& position){position_ = position;}
    void setLatitude(double latitude) {position_.setLatitude(latitude);}
    void setLongitude(double longitude) {position_.setLongitude(longitude);}
    void setAltitude(double altitude) {position_.setAltitude(altitude);}
    double latitude() const {return position_.latitude();}
    double longitude() const {return position_.longitude();}
    double altitude() const {return position_.altitude();}
private:
    SharedPtr<Body>     body_{};               ///< 天体名称
    GeodeticPoint       position_{};          ///< 质心位置点
};

#endif


/*! @} */

AST_NAMESPACE_END