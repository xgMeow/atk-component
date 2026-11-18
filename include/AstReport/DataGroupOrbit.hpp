/// @file      DataGroupOrbit.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-06

#pragma once

#include "AstGlobal.h"
#include "AstReport/DataGroupTimeVar.hpp"
#include "AstCore/Point.hpp"
#include "AstMath/Vector.hpp"
#include "AstUtil/Span.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 轨道数据组
class DataGroupOrbit : public DataGroupTimeVar
{
public:
    struct Data
    {
        double gm_{};
        Vector3d pos_{};
        Vector3d vel_{};
    };
    static DataElements Elements();
    DataGroupOrbit() = default;
    ~DataGroupOrbit() = default;
public:
    errc_t calculate(const TimeList& timeList, VariantVector& result) const override;
    const DataElements& getElements() const override;
public:
    errc_t calculate(const TimeList& timeList, std::vector<Data>& result) const;
    errc_t calculate(const TimeList& timeList, Span<Data> result) const;
public:
    Point* getPoint() const;
    Frame* getFrame() const;
    Body* getBody() const;
    double getGM() const;
private:
    WeakPtr<Point> point_;              ///< 点
    WeakPtr<Frame> frame_;              ///< 坐标系
    WeakPtr<Body> body_;                ///< 天体
    bool useBodyInertial_{true};        ///< 是否使用天体惯性坐标系
};


/*! @} */

AST_NAMESPACE_END
