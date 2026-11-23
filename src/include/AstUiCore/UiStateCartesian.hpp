/// @file      UiStateCartesian.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-28

#pragma once

#include "AstGlobal.h"
#include "AstUiCore/UiState.hpp"
#include "AstUiCore/UiQuantity.hpp"
#include "AstUiCore/UiTimePoint.hpp"
#include <QLineEdit>

class QPushButton;

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/

class StateCartesian;
class Frame;

class AST_UICORE_API UiStateCartesian: public UiState
{
    Q_OBJECT
public:
    explicit UiStateCartesian(Object* object, QWidget *parent = nullptr);
    explicit UiStateCartesian(QWidget *parent = nullptr);
    ~UiStateCartesian() = default;
    UiStateCartesian(const UiStateCartesian&) = delete;
    UiStateCartesian& operator=(const UiStateCartesian&) = delete;

    void refreshUi();
    void apply();
    void applyTo(StateCartesian* state);

    void setStateCartesian(StateCartesian* state);
    StateCartesian* getStateCartesian() const;

private slots:
    void onSelectFrame();

signals:
    void stateCartesianChanged(StateCartesian* state);
private:
    // 左侧控件
    UiTimePoint* epochEdit_{nullptr};
    QLineEdit*   frameEdit_{nullptr};
    QPushButton* frameSelectBtn_{nullptr};

    // 右侧控件
    UiQuantity* posXEdit_{nullptr};
    UiQuantity* posYEdit_{nullptr};
    UiQuantity* posZEdit_{nullptr};
    UiQuantity* velXEdit_{nullptr};
    UiQuantity* velYEdit_{nullptr};
    UiQuantity* velZEdit_{nullptr};
};


/*! @} */

AST_NAMESPACE_END
