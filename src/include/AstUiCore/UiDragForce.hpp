/// @file      UiDragForce.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-22

#pragma once

#include "AstGlobal.h"
#include "AstUiCore/UiObject.hpp"
#include "AstUiCore/UiFilePath.hpp"
#include "AstUiCore/UiDouble.hpp"
#include "AstUiCore/UiQuantity.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QComboBox>
#include <QGroupBox>

AST_NAMESPACE_BEGIN

class DragForce;

class AST_UICORE_API UiDragForce: public UiObject
{
    Q_OBJECT
public:
    UiDragForce(Object* object, QWidget *parent = nullptr);
    UiDragForce(QWidget *parent = nullptr);
    ~UiDragForce() = default;
    UiDragForce(const UiDragForce&) = delete;
    UiDragForce& operator=(const UiDragForce&) = delete;

    DragForce* getDragForce() const;
    void setDragForce(DragForce* drag);
    void refreshUi();
    void apply();
    void applyTo(DragForce* drag);
protected:
    void setupUi();
    void refreshAtmDensityModel();
    void refreshGeoMagFluxSource();
    void refreshGeoMagFluxUpdateRate();
    void refreshSunPosition();
private slots:
    void onFluxApFileChanged(bool checked);
private:
    // 布局
    QVBoxLayout* mainLayout_{nullptr};

    // 模型配置
    QGroupBox* modelGroup_{nullptr};
    QGridLayout* modelLayout_{nullptr};
    QHBoxLayout* typeLayout_{nullptr};
    QLabel* typeLabel_{nullptr};
    QComboBox* typeCombo_{nullptr};
    QHBoxLayout* cdLayout_{nullptr};
    QLabel* cdLabel_{nullptr};
    UiDouble* cdEdit_{nullptr};
    QHBoxLayout* areaMassLayout_{nullptr};
    QLabel* areaMassLabel_{nullptr};
    UiQuantity* areaMassEdit_{nullptr};

    // 大气密度模型
    QGroupBox* atmDensityGroup_{nullptr};
    QGridLayout* atmDensityLayout_{nullptr};
    QHBoxLayout* mainAtmLayout_{nullptr};
    QLabel* mainAtmLabel_{nullptr};
    QComboBox* mainAtmCombo_{nullptr};
    QHBoxLayout* lowAltAtmLayout_{nullptr};
    QLabel* lowAltAtmLabel_{nullptr};
    QComboBox* lowAltAtmCombo_{nullptr};
    QHBoxLayout* blendingRangeLayout_{nullptr};
    QLabel* blendingRangeLabel_{nullptr};
    UiQuantity* blendingRangeEdit_{nullptr};

    // 太阳通量/地磁指数
    QGroupBox* solarGeoMagGroup_{nullptr};
    QGridLayout* solarGeoMagLayout_{nullptr};
    QHBoxLayout* fluxSourceLayout_{nullptr};
    QLabel* fluxSourceLabel_{nullptr};
    QComboBox* fluxSourceCombo_{nullptr};

    // 手动输入参数
    QHBoxLayout* f10p7DailyLayout_{nullptr};
    QLabel* f10p7DailyLabel_{nullptr};
    UiDouble* f10p7DailyEdit_{nullptr};
    QHBoxLayout* f10p7AverageLayout_{nullptr};
    QLabel* f10p7AverageLabel_{nullptr};
    UiDouble* f10p7AverageEdit_{nullptr};
    QHBoxLayout* kpLayout_{nullptr};
    QLabel* kpLabel_{nullptr};
    UiDouble* kpEdit_{nullptr};

    // 文件输入参数
    QHBoxLayout* fluxApFileLayout_{nullptr};
    QLabel* fluxApFileLabel_{nullptr};
    UiFilePath* fluxApFileEdit_{nullptr};
    QHBoxLayout* geoMagFluxUpdateRateLayout_{nullptr};
    QLabel* geoMagFluxUpdateRateLabel_{nullptr};
    QComboBox* geoMagFluxUpdateRateCombo_{nullptr};
    QHBoxLayout* geoMagFluxSourceLayout_{nullptr};
    QLabel* geoMagFluxSourceLabel_{nullptr};
    QComboBox* geoMagFluxSourceCombo_{nullptr};

    // 计算选项
    QGroupBox* calcOptionsGroup_{nullptr};
    QVBoxLayout* calcOptionsLayout_{nullptr};
    QHBoxLayout* useApproxAltLayout_{nullptr};
    QCheckBox* useApproxAltCheck_{nullptr};
    QHBoxLayout* sunPositionLayout_{nullptr};
    QLabel* sunPositionLabel_{nullptr};
    QComboBox* sunPositionCombo_{nullptr};


};

AST_NAMESPACE_END
