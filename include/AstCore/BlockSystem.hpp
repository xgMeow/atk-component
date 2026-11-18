/// @file      BlockSystem.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-19

#pragma once

#include "AstGlobal.h"
#include "AstCore/FuncBlock.hpp"

AST_NAMESPACE_BEGIN

/// @brief 子系统块(subsystem block)
/// @details 
/// 参考 symlink 的子系统块，
/// 子系统块是多个函数块的集合，
/// 这些函数块组合起来形成一个子系统块，具有输入和输出
class AST_CORE_API BlockSystem : public FuncBlock
{
public:
    BlockSystem();
    ~BlockSystem();
    A_DISABLE_COPY(BlockSystem);

    errc_t run(const SimTime& simTime) override;

    /// @brief 添加函数块到子系统中
    /// @param block 要添加的函数块指针
    void addBlock(FuncBlock* block);

    /// @brief 清除子系统中的所有函数块
    void clearBlocks();

protected:
    std::vector<FuncBlock*> blocks_{};    // 子系统块中的函数块
};


AST_NAMESPACE_END
