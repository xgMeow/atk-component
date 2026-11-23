/// @file      IdentifierTable.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-18

#pragma once

#include "AstGlobal.h"
#include "Identifier.hpp"
#include <vector>
#include <mutex>
#include <algorithm>        
#include <unordered_map>    //  for std::unordered_map
#include <memory>           //  for std::unique_ptr
#include <new>              //  for ::operator new

AST_NAMESPACE_BEGIN

// #define _AST_ENABLE_IDENTIFIER_TABLE_MUTEX


class IdentifierTable {
private:
    // 使用哈希表存储符号
    std::unordered_multimap<size_t, std::unique_ptr<Identifier>> table_{};
#ifdef _AST_ENABLE_IDENTIFIER_TABLE_MUTEX
    mutable std::mutex mutex_;
#endif

    // 计算字符串的哈希值（DJB2哈希算法）
    size_t compute_hash(const char* data, size_t length) const {
        return Identifier::hash(data, length);
    }

public:
    // 查找或创建符号
    Identifier* intern(const char* data, size_t length) {
        size_t hash = compute_hash(data, length);

#ifdef _AST_ENABLE_IDENTIFIER_TABLE_MUTEX
        std::lock_guard<std::mutex> lock(mutex_);
#endif
        // 查找现有符号
        auto range = table_.equal_range(hash);
        for (auto it = range.first; it != range.second; ++it) {
            Identifier* sym = it->second.get();
            if (sym->length() == length && 
                memcmp(sym->data(), data, length) == 0) {
                return sym;  // 返回现有符号
            }
            // ++it;
        }

        // 创建新符号
        // 注意：这里必须使用 ::operator new 而非 new char[] 分配。
        // 符号最终由 std::unique_ptr<Identifier> 释放（即 operator delete），
        // 用 new char[] 分配会构成 new[]/delete 不匹配的未定义行为，ASan 会报 alloc-dealloc-mismatch。
        size_t alloc_size = sizeof(Identifier) + length; 
        void* memory = ::operator new(alloc_size);
        Identifier* sym = new (memory) Identifier(static_cast<uint32_t>(length));
        memcpy(sym->data(), data, length);
        sym->data()[length] = '\0';

        table_.emplace(hash, std::unique_ptr<Identifier>(sym));
        return sym;
    }

    // 重载版本，接受C字符串
    Identifier* intern(const char* str) {
        return intern(str, strlen(str));
    }

    // 重载版本，接受std::string
    Identifier* intern(const std::string& str) {
        return intern(str.c_str(), str.length());
    }

    // 查找符号（不创建）
    Identifier* lookup(const char* data, size_t length) const {
        size_t hash = compute_hash(data, length);

#ifdef _AST_ENABLE_IDENTIFIER_TABLE_MUTEX
        std::lock_guard<std::mutex> lock(mutex_);
#endif
        auto range = table_.equal_range(hash);

        for (auto it = range.first; it != range.second; ++it) {
            Identifier* sym = it->second.get();
            if (sym->length() == length && 
                memcmp(sym->data(), data, length) == 0) {
                return sym;
            }
        }

        return nullptr;
    }

    // 获取符号数量
    size_t size() const {
#ifdef _AST_ENABLE_IDENTIFIER_TABLE_MUTEX
        std::lock_guard<std::mutex> lock(mutex_);
#endif
        return table_.size();
    }

    // 清理符号表（移除所有符号）
    void clear() {
#ifdef _AST_ENABLE_IDENTIFIER_TABLE_MUTEX
        std::lock_guard<std::mutex> lock(mutex_);
#endif
        table_.clear();
    }
};


AST_NAMESPACE_END
