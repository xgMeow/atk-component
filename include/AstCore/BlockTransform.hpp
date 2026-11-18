/// @file      BlockTransform.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-25

#pragma once

#include "AstGlobal.h"
#include "BlockDerivative.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 坐标系转换函数块（待实现）
/// @details
/// 计划实现通用的坐标系变换功能，将坐标转换矩阵作为公共信号，避免一些重复计算。
///
/// 当前 run() 返回 -1（未实现）。
///
/// @todo 待实现：定义输出端口
class AST_CORE_API BlockTransform : public BlockDerivative
{
public:
    BlockTransform() = default;
    ~BlockTransform() = default;

    errc_t run(const SimTime& simTime) override;
protected:

};

/*! @} */

AST_NAMESPACE_END
