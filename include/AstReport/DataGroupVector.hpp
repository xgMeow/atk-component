/// @file      DataGroupVector.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-06

#pragma once

#include "AstGlobal.h"
#include "AstReport/DataGroupTimeVar.hpp"
#include "AstCore/Vector.hpp"
#include "AstCore/Axes.hpp"
#include "AstUtil/Span.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 向量数据组
class DataGroupVector : public DataGroupTimeVar
{
public:
    struct Data
    {
        Vector3d vector;
        Vector3d velocity;
    };
    static DataElements Elements();
    DataGroupVector() = default;
    ~DataGroupVector() = default;
public:
    errc_t calculate(const TimeList& timeList, VariantVector& result) const override;
    const DataElements& getElements() const override;
public:
    errc_t calculate(const TimeList& timeList, std::vector<Data>& result) const;
    errc_t calculate(const TimeList& timeList, Span<Data> result) const;
public:
    Vector* getVector() const{return vector_.get();}
    Axes* getAxes() const{return axes_.get();}
private:
    WeakPtr<Vector> vector_;                ///< 向量
    WeakPtr<Axes> axes_;                    ///< 坐标系
};

/*! @} */

AST_NAMESPACE_END
