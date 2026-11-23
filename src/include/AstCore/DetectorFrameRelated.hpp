/// @file      DetectorFrameRelated.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-03

#pragma once

#include "AstGlobal.h"
#include "EventDetector.hpp"
#include "AstCore/Frame.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


class AST_CORE_API DetectorFrameRelated : public EventDetector
{
public:
    AST_OBJECT(DetectorFrameRelated)
    AST_PROPERT(frame)
PROPERTIES:
    Frame* frame() const {return frame_.get();}
    void setFrame(Frame* frame) {frame_ = frame;}
private:
    WeakPtr<Frame> frame_;
};

/*! @} */

AST_NAMESPACE_END

