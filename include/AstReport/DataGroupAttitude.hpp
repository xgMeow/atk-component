/// @file      DataGroupAttitude.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-06

#pragma once

#include "AstGlobal.h"
#include "AstReport/DataGroupTimeVar.hpp"
#include "AstUtil/Span.hpp"
#include "AstCore/Axes.hpp"
#include "AstMath/KinematicRotation.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 姿态数据组
class DataGroupAttitude : public DataGroupTimeVar
{
public:
    struct Data
    {
        KinematicRotation rotation{};
    };
    static DataElements Elements();

    DataGroupAttitude() = default;
    ~DataGroupAttitude() = default;
public:
    errc_t calculate(const TimeList& timeList, VariantVector& result) const override;
    const DataElements& getElements() const override;
public:
    errc_t calculate(const TimeList& timeList, std::vector<Data>& result) const;
    errc_t calculate(const TimeList& timeList, Span<Data> result) const;
public:
    Axes* getAxes() const { return axes_.get(); }
    Axes* getReferenceAxes() const { return referenceAxes_.get(); }
private:
    WeakPtr<Axes> axes_;                ///< 姿态轴
    WeakPtr<Axes> referenceAxes_;       ///< 参考轴
};


/*! @} */

AST_NAMESPACE_END
