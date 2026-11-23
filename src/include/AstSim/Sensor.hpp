/// @file      Sensor.hpp
/// @brief     传感器对象
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Object.hpp"
#include "AstUtil/StringView.hpp"
#include "AstCore/Point.hpp"
#include "AstCore/FieldOfView.hpp"
#include "AstSim/Platform.hpp"
#include <memory>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 传感器对象
class AST_SIM_API Sensor: public Platform
{
public:
    AST_OBJECT(Sensor)
    Sensor();
    ~Sensor() override = default;
public:
    /// @brief 设置传感器视场
    /// @param fov 视场对象指针
    void setFieldOfView(FieldOfView* fov);

    /// @brief 获取传感器视场
    /// @return 视场对象指针
    FieldOfView* getFieldOfView() const { return fov_; }
    FieldOfView* fieldOfView() const { return fov_; }

private:
    SharedPtr<FieldOfView> fov_{};    ///< 传感器视场定义
};

/*! @} */

AST_NAMESPACE_END