/// @file      UiStateKeplerian.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-31

#pragma once

#include "AstGlobal.h"
#include "UiState.hpp"
#include "AstUiCore/UiTimePoint.hpp"
#include "AstUiCore/UiQuantity.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/

class StateKeplerian;
class Frame;

class AST_UICORE_API UiStateKeplerian : public UiState
{
    Q_OBJECT
public:
    explicit UiStateKeplerian(Object* object, QWidget *parent = nullptr);
    explicit UiStateKeplerian(QWidget *parent = nullptr);
    ~UiStateKeplerian() = default;
    UiStateKeplerian(const UiStateKeplerian&) = delete;
    UiStateKeplerian& operator=(const UiStateKeplerian&) = delete;

    StateKeplerian* getStateKeplerian() const;
    void setStateKeplerian(StateKeplerian* state);
    void refreshUi();
    // void apply();
    // void applyTo(StateKeplerian* state);

private slots:
    void onSelectFrame();

protected:
    void onSizeTypeChanged();
    void onSizeParamChanged();
    void onShapeTypeChanged();
    void onShapeParamChanged();
    void onOrientationTypeChanged();
    void onOrientationParamChanged();
    void onPositionTypeChanged();
    void onPositionParamChanged();
    void onEpochChanged();
    void onFrameChanged();
    void onIncChanged();
    void onArgPeriChanged();
protected:
    void refreshSizeType();
    void refreshSizeParam();
    void refreshShapeType();
    void refreshShapeParam();
    void refreshOrientationType();
    void refreshOrientationParam();
    void refreshPositionType();
    void refreshPositionParam();
    void refreshEpoch();
    void refreshFrame();
    void refreshInc();
    void refreshArgPeri();

signals:
    void stateKeplerianChanged(StateKeplerian* state);
private:
    // 轨道历元
    UiTimePoint* epochEdit_{nullptr};
    // 坐标系
    QLineEdit*   frameEdit_{nullptr};
    QPushButton* frameSelectBtn_{nullptr};
    // 轨道大小
    QHBoxLayout* sizeLayout_{nullptr};
    QLabel* sizeLabel_{nullptr};
    QComboBox* sizeTypeCombo_{nullptr};
    UiQuantity* sizeEdit_{nullptr};
    // 轨道形状
    QHBoxLayout* shapeLayout_{nullptr};
    QLabel* shapeLabel_{nullptr};
    QComboBox* shapeTypeCombo_{nullptr};
    UiQuantity* shapeEdit_{nullptr};
    // 倾角
    QHBoxLayout* incLayout_{nullptr};
    QLabel* incLabel_{nullptr};
    UiQuantity* incEdit_{nullptr};
    // 轨道面方向
    QHBoxLayout* orientationLayout_{nullptr};
    QLabel* orientationLabel_{nullptr};
    QComboBox* orientationTypeCombo_{nullptr};
    UiQuantity* orientationEdit_{nullptr};
    // 近地点幅角
    QHBoxLayout* argPeriLayout_{nullptr};
    QLabel* argPeriLabel_{nullptr};
    UiQuantity* argPeriEdit_{nullptr};
    // 轨道位置
    QHBoxLayout* positionLayout_{nullptr};
    QLabel* positionLabel_{nullptr};
    QComboBox* positionTypeCombo_{nullptr};
    UiQuantity* positionEdit_{nullptr};
};

/*! @} */

AST_NAMESPACE_END
