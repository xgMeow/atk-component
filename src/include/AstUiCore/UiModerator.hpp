/// @file      UiModerator.hpp
/// @brief     引擎总控
/// @details   将引擎相关事件转发为 Qt 信号广播给 UI 层。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-08

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"
#include <QObject>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 引擎总控（QObject 单例）
/// @details 订阅 Moderator 的相关事件，转换为 Qt 信号，供 UI 控件连接以获得引擎相关事件的通知。
class AST_UICORE_API UiModerator : public QObject
{
    Q_OBJECT
public:
    explicit UiModerator(QObject* parent = nullptr);
    ~UiModerator() override;

    UiModerator(const UiModerator&) = delete;
    UiModerator& operator=(const UiModerator&) = delete;

    /// @brief 获取全局 UI 仲裁器单例
    /// @return UiModerator& 全局单例引用
    static UiModerator& Instance();

signals:
    /// @brief 对象已被添加后通知
    void objectAdded(Object& obj);
    /// @brief 对象将被移除前通知
    void beforeObjectRemove(Object& obj);
    /// @brief 对象已被移除后通知
    void objectRemoved(Object& obj);
    /// @brief 对象将被重命名前通知
    void beforeObjectRename(Object& obj, StringView oldName, StringView newName);
    /// @brief 对象已被重命名后通知
    void objectRenamed(Object& obj, StringView oldName, StringView newName);

private:
    /// @brief 引擎事件桥接适配器
    class Observer;
    Observer* observer_{};
};

/*! @} */

AST_NAMESPACE_END
