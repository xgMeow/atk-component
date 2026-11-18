/// @file      ModeratorObserverMultiplexer.hpp
/// @brief
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-08

#pragma once

#include "AstGlobal.h"
#include "ModeratorObserver.hpp"
#include <vector>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/


/// @brief 多路复用观察者：聚合分发到多个子观察者（可嵌套），不拥有子观察者
/// @details 自身实现 ModeratorObserver 接口，把收到的通知依次转发给全部子观察者；
class AST_ENGINE_API ModeratorObserverMultiplexer final: public ModeratorObserver
{
public:
    ModeratorObserverMultiplexer() = default;

    /// @brief 析构时切断所有子订阅者对自身的反向引用，避免悬垂
    ~ModeratorObserverMultiplexer();

    ModeratorObserverMultiplexer(const ModeratorObserverMultiplexer&) = delete;
    ModeratorObserverMultiplexer& operator=(const ModeratorObserverMultiplexer&) = delete;

    /// @brief 注册子观察者
    /// @param observer 子观察者指针（可为另一复用器）
    void addObserver(ModeratorObserver* observer);

    /// @brief 移除子观察者（不 delete）
    /// @param observer 子观察者指针
    void removeObserver(ModeratorObserver* observer);

    /// @brief 清空所有子观察者
    void clear();

    /// @brief 转发：对象被添加（后）
    void onObjectAdded(Object& obj) override;

    /// @brief 转发：对象将被移除（前）
    void onBeforeObjectRemove(Object& obj) override;

    /// @brief 转发：对象已被移除（后）
    void onObjectRemoved(Object& obj) override;

    /// @brief 转发：对象将被重命名（前）
    void onBeforeObjectRename(Object& obj, StringView oldName, StringView newName) override;

    /// @brief 转发：对象已被重命名（后）
    void onObjectRenamed(Object& obj, StringView oldName, StringView newName) override;

private:
    std::vector<ModeratorObserver*> observers_{};   ///< 子观察者（不拥有）
};


/*! @} */

AST_NAMESPACE_END
