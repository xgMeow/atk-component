/// @file      LocaleGuard.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"
#include <clocale>      // std::setlocale
#include <string>       // std::string
#include <stdexcept>    // std::runtime_error
#include "AstUtil/Logger.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 用于切换和恢复 locale 的 RAII 类。
class LocaleGuard
{
public:
    /// @brief 构造并切换到指定的 locale。
    /// @param new_locale  要设置的 locale 名称，例如 "en_US.UTF-8" 或 "C"
    /// @param category    要修改的类别，默认为 LC_ALL（也可用 LC_CTYPE 等）
    explicit LocaleGuard(const char* new_locale, int category = LC_ALL)
        : active_(false)
        , category_(category)
    {
        // 1. 保存当前 locale 的字符串表示
        const char* old = std::setlocale(category_, nullptr);
        if (old != nullptr) {
            old_locale_ = old;   // 复制一份字符串
        }
        // 2. 尝试设置新 locale
        if (std::setlocale(category_, new_locale) != nullptr) {
            active_ = true;      // 设置成功，析构时需要恢复
        } else {
            // 设置失败，不改变当前 locale
            aError(_("设置 locale '%s' 失败"), new_locale);
        }
    }


    ~LocaleGuard() {
        if (active_ && !old_locale_.empty()) {
            std::setlocale(category_, old_locale_.c_str());
        }
    }

    // 可选：提前恢复并停止自动恢复（类似 lock_guard 的 release 语义）
    void release() {
        active_ = false;
    }
    A_DISABLE_COPY(LocaleGuard);

private:
    bool active_{};           // 是否需要在析构时恢复
    int category_{};          // 影响哪个 locale 类别（LC_ALL, LC_CTYPE 等）
    std::string old_locale_{};// 保存的原 locale 字符串
};

/*! @} */

AST_NAMESPACE_END
