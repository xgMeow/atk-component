/// @file      UiObject.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-28

#pragma once

#include "AstGlobal.h"
#include <QWidget>
#include "AstUtil/Object.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 与对象关联的 QWidget
class AST_UICORE_API UiObject: public QWidget
{
    Q_OBJECT
public:
    explicit UiObject(QWidget *parent = nullptr);
    explicit UiObject(Object* object, QWidget *parent = nullptr);
    ~UiObject() = default;

    /// @brief 获取关联的对象
    /// @return 关联的对象指针
    /// @note 如果对象已被销毁，返回 nullptr
    Object* getObject() const{return object_.get();}

    /// @brief 设置关联的对象
    /// @param object 关联的对象指针
    void setObject(Object* object);
private:
    WeakPtr<Object> object_{};
};


/*! @} */

AST_NAMESPACE_END
