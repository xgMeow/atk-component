/// @file      UiMotionTwoBody.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-28

#pragma once

#include "AstGlobal.h"
#include "AstUiCore/UiMotionProfile.hpp"
#include "AstUiCore/UiTimeInterval.hpp"
#include "AstUiCore/UiTimePoint.hpp"
#include "AstUiCore/UiQuantity.hpp"
#include "AstUiCore/UiStateCartesian.hpp"
#include "AstUiCore/UiStateKeplerian.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QComboBox>



AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class MotionTwoBody;

class AST_UICORE_API UiMotionTwoBody: public UiMotionProfile
{
    Q_OBJECT
public:
    UiMotionTwoBody(Object* object, QWidget *parent = nullptr);
    UiMotionTwoBody(QWidget *parent = nullptr);
    ~UiMotionTwoBody() = default;
    UiMotionTwoBody(const UiMotionTwoBody&) = delete;
    UiMotionTwoBody& operator=(const UiMotionTwoBody&) = delete;

    MotionTwoBody* getMotionTwoBody() const;
    void setMotionTwoBody(MotionTwoBody* motion);
    void refreshUi();
    void apply();
protected:
    void onStateTypeChanged();
    void onStepSizeChanged();
    void onIntervalChanged();
    void onPropagationFrameChanged();
protected:
    void refreshStateType();
private slots:
    void applyTo(MotionTwoBody* motion);
private:
    // 布局
    QVBoxLayout* mainLayout_{nullptr};
    QGridLayout* gridLayout_{nullptr};
    QVBoxLayout* leftLayout_{nullptr};
    QVBoxLayout* rightLayout_{nullptr};

    // 左侧控件
    QHBoxLayout* timeIntervalLayout_{nullptr};
    QLabel* timeIntervalLabel_{nullptr};
    UiTimeInterval* timeIntervalEdit_{nullptr};
    QHBoxLayout* stepSizeLayout_{nullptr};
    QLabel* stepSizeLabel_{nullptr};
    UiQuantity* stepSizeEdit_{nullptr};
    QHBoxLayout* propagationFrameLayout_{nullptr};
    QLabel* propagationFrameLabel_{nullptr};
    QComboBox* propagationFrameCombo_{nullptr};
    QHBoxLayout* stateTypeLayout_{nullptr};
    QLabel* stateTypeLabel_{nullptr};
    QComboBox* stateTypeCombo_{nullptr};

    // 右侧控件
    UiStateCartesian* stateCartesianEdit_{nullptr};
    UiStateKeplerian* stateKeplerianEdit_{nullptr};

    // 数据
    MotionTwoBody* motionTwoBody_{nullptr};
};




/*! @} */

AST_NAMESPACE_END
