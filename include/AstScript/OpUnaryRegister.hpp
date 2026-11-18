/// @file      OpUnaryRegister.hpp
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
class OpUnaryRegister
{
public:
//  @brief 运算函数注册表键类型
    typedef std::tuple<int, Class*> OpUnaryKey;

    //  @brief 运算函数注册表哈希函数
    struct OpUnaryKeyHash {
        std::size_t operator()(const OpUnaryKey& key) const {
            // 组合哈希值
            std::size_t h1 = std::hash<int>()(static_cast<int>(std::get<0>(key)));
            std::size_t h2 = std::hash<const void*>()(std::get<1>(key));
            // 使用位运算组合哈希值
            return h1 ^ (h2 << 1);
        }
    };
    typedef std::unordered_map<OpUnaryKey, void*, OpUnaryKeyHash> OpUnaryMap;

public:
    OpUnaryRegister() = default;
    ~OpUnaryRegister() = default;
    void* getFunc(EOpUnaryType op, Class* type)
    {
        auto key = OpUnaryKey{static_cast<int>(op), type};
        auto it = map_.find(key);
        if(it == map_.end()){
            return nullptr;
        }
        return it->second;
    }
    void regFunc(EOpUnaryType op, Class* type, void* func)
    {
        map_[OpUnaryKey{static_cast<int>(op), type}] = func;
    }
protected:
    OpUnaryMap map_{};
};
#endif

AST_NAMESPACE_END
