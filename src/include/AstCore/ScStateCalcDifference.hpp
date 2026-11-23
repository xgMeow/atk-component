/// @file      ScStateCalcDifference.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-02

#pragma once

#include "AstGlobal.h"
#include "AstCore/ScStateCalculation.hpp"
#include "AstCore/Segment.hpp"

AST_NAMESPACE_BEGIN

enum class EDifferenceOrderToUse
{
    eCurrentMinusInitial,
    eInitialMinusCurrent,
};

class AST_CORE_API ScStateCalcDifference : public ScStateCalculation
{
public:
    AST_OBJECT(ScStateCalcDifference)

    errc_t calculate(const SpacecraftState& scState, double& result) override;

    /// @brief 获取计算对象
    ScStateCalculation* calculation() const{return calculation_.get();}

    /// @brief 设置计算对象
    void setCalculation(ScStateCalculation* calculation);

    /// @brief 获取差值顺序
    EDifferenceOrderToUse differenceOrderToUse() const{return differenceOrderToUse_;}

    /// @brief 设置差值顺序
    void setDifferenceOrderToUse(EDifferenceOrderToUse order){differenceOrderToUse_ = order;}

    Dimension getDimension() const override;
protected:
    Segment* getSegment();
private:
    WeakPtr<Segment> segment_{};
    WeakPtr<ScStateCalculation> calculation_{};
    EDifferenceOrderToUse differenceOrderToUse_{EDifferenceOrderToUse::eCurrentMinusInitial};
};

AST_NAMESPACE_END