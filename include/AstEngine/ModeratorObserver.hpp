/// @file      ModeratorObserver.hpp
/// @brief
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-08

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"
#include <vector>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/


class ModeratorObserverMultiplexer; 

/// @brief 引擎事件监听者接口（观察者）
/// @details 不继承 Object/引用计数；复用器/Moderator 不拥有订阅者，
///          订阅者析构时通过 sources_ 自动从所有登记它的复用器注销。
class AST_ENGINE_API ModeratorObserver
{
public:
    /// @brief 析构时自动从所有登记它的复用器注销
    virtual ~ModeratorObserver();

    /// @brief 对象被添加后通知
    /// @param obj 被添加的对象
    virtual void onObjectAdded(Object& obj) { A_UNUSED(obj); }

    /// @brief 对象将被移除前通知
    /// @param obj 被移除的对象
    virtual void onBeforeObjectRemove(Object& obj) { A_UNUSED(obj); }

    /// @brief 对象已被移除后通知
    /// @param obj 被移除的对象
    virtual void onObjectRemoved(Object& obj) { A_UNUSED(obj); }

    /// @brief 对象将被重命名前通知
    /// @param obj 被重命名的对象
    /// @param oldName 重命名前的旧名称
    virtual void onBeforeObjectRename(Object& obj, StringView oldName, StringView newName) { A_UNUSED(obj); A_UNUSED(newName); A_UNUSED(oldName); }

    /// @brief 对象已被重命名后通知
    /// @param obj 被重命名的对象
    /// @param oldName 重命名前的旧名称
    virtual void onObjectRenamed(Object& obj, StringView oldName, StringView newName) { A_UNUSED(obj); A_UNUSED(newName); A_UNUSED(oldName); }

private:
    friend class ModeratorObserverMultiplexer;

    /// @brief 复用器登记本订阅者时调用（记录反向注册表）
    /// @param src 登记了本订阅者的复用器
    void addSource(ModeratorObserverMultiplexer* src);

    /// @brief 复用器移除本订阅者时调用（清空反向注册表对应项）
    /// @param src 移除了本订阅者的复用器
    void removeSource(ModeratorObserverMultiplexer* src);

    std::vector<ModeratorObserverMultiplexer*> sources_{};   ///< 反向注册表：登记了本订阅者的复用器
};


/*! @} */

AST_NAMESPACE_END
