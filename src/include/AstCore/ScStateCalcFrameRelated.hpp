/// @file      ScStateCalcFrameRelated.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-02

#pragma once

#include "AstGlobal.h"
#include "AstCore/Frame.hpp"
#include "AstCore/ScStateCalculation.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_CORE_API ScStateCalcFrameRelated: public ScStateCalculation
{
public:
    AST_OBJECT(ScStateCalcFrameRelated)
    AST_PROPERT(frame)
;

    ScStateCalcFrameRelated() = default;
    ~ScStateCalcFrameRelated() = default;
PROPERTIES:
    Frame* frame() const { return frame_.get(); }
    void setFrame(Frame* frame) { frame_ = frame; }
private:
    WeakPtr<Frame> frame_{};
};

/*! @} */

AST_NAMESPACE_END
