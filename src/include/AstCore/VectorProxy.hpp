/// @file      VectorProxy.hpp
/// @brief
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-10-09

#pragma once

#include "AstGlobal.h"
#include "AstCore/Vector.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Geometry
    @{
*/

/// @brief 向量代理类
/// @details 将向量接口原样转发给被代理的向量对象，自身不产生任何计算。
class AST_CORE_API VectorProxy final: public Vector
{
public:
    VectorProxy() = default;
    explicit VectorProxy(Vector* vector):impl_(vector){}
    ~VectorProxy() override = default;

public:
    void setImpl(Vector* impl){impl_ = impl;}
    Vector* impl() const {return impl_.get();}
public:
    Axes* getAxes() const override;
    errc_t getVector(const TimePoint& tp, Vector3d& vec) const override;
    errc_t getVector(const TimePoint& tp, Vector3d& vec, Vector3d& vel) const override;
    errc_t getVector(const TimePoint& tp, Vector3d& vec, Vector3d& vel, Vector3d& acc) const override;
private:
    WeakPtr<Vector> impl_{};
};




/*! @} */

AST_NAMESPACE_END
