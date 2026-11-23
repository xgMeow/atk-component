/// @file      TwoBody.hpp
/// @brief     
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      15.11.2025

#pragma once

#include "AstGlobal.h"
#include "Propagator.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Propagator
    @{
*/

/// @brief     二体传播
/// @details   
/// @param     duration  传播时间
/// @param     gm        引力常数
/// @param     r         位置向量
/// @param     v         速度向量
/// @return    错误码
AST_CORE_CAPI errc_t aTwoBodyProp(double duration, double gm, Vector3d& r, Vector3d& v);



class TwoBody : public Propagator
{
public:

};

/*! @} */


AST_NAMESPACE_END



