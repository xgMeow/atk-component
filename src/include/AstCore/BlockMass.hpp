/// @file      BlockMass.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-09

#pragma once

#include "AstGlobal.h"
#include "AstCore/BlockDerivative.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 质量函数块
/// @details
/// 提供固定的航天器质量值，通过输出端口供其他力模型块（BlockDrag、BlockSRP）使用。
///
/// 当前为恒定质量模型，未来可扩展为变质量模型（考虑燃料消耗）。
///
/// 输出端口：
///   - "Mass"：航天器质量（标量）
///
/// @note run() 为空操作，质量值在构造时固定
class AST_CORE_API BlockMass: public BlockDerivative
{
public:
    explicit BlockMass(double mass);

    BlockMass(const BlockMass&) = delete;
    BlockMass& operator=(const BlockMass&) = delete;

    ~BlockMass();
    errc_t run(const SimTime& simTime) final{return 0;}
protected:
    double* massPtr_{&mass_};   ///< 指向质量值的指针（用于输出端口信号）
    double mass_{};             ///< 航天器质量 [kg]
};

/*! @} */

AST_NAMESPACE_END
