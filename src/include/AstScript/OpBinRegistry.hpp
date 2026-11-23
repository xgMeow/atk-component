/// @file      OpBinRegistry.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-22

#pragma once

#include "AstGlobal.h"
#include "AstScript/ScriptAPI.hpp"
#include <tuple>
#include <unordered_map>

AST_NAMESPACE_BEGIN

#ifndef SWIG
class OpBinRegistry
{
public:
    //  @brief 运算函数注册表键类型
    typedef std::tuple<int, Class*, Class*> OpBinKey;

    //  @brief 运算函数注册表哈希函数
    struct OpBinKeyHash {
        std::size_t operator()(const OpBinKey& key) const {
            // 组合哈希值
            std::size_t h1 = std::hash<int>()(static_cast<int>(std::get<0>(key)));
            std::size_t h2 = std::hash<const void*>()(std::get<1>(key));
            std::size_t h3 = std::hash<const void*>()(std::get<2>(key));
            // 使用位运算组合哈希值
            return h1 ^ (h2 << 1) ^ (h3 << 2);
        }
    };
    typedef std::unordered_map<OpBinKey, void*, OpBinKeyHash> OpBinMap;
public:
    OpBinRegistry() = default;
    ~OpBinRegistry() = default;

    void* getFunc(EOpBinType op, Class* leftType, Class* rightType)
    {
        auto key = OpBinKey{static_cast<int>(op), leftType, rightType};
        auto it = map_.find(key);
        if(it == map_.end()){
            return nullptr;
        }
        return it->second;
    }
    void regFunc(EOpBinType op, Class* leftType, Class* rightType, void* func)
    {
        map_[OpBinKey{static_cast<int>(op), leftType, rightType}] = func;
    }
protected:
    OpBinMap map_{};
};

#endif

AST_NAMESPACE_END
