/// @file      UiOrbitWizard.hpp
/// @brief     轨道向导对话框
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-08

#pragma once

#include "AstGlobal.h"
#include <QDialog>
#include <QComboBox>
#include <QLineEdit>
#include <QRadioButton>
#include <QCheckBox>
#include <QSlider>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QColorDialog>
#include <QFrame>

AST_NAMESPACE_BEGIN

class AST_UICORE_API UiOrbitWizard : public QDialog
{
    Q_OBJECT

public:
    explicit UiOrbitWizard(QWidget *parent = nullptr);
    ~UiOrbitWizard();
    UiOrbitWizard(const UiOrbitWizard&) = delete;
    UiOrbitWizard& operator=(const UiOrbitWizard&) = delete;

private:
    void setupUi();
    void setupConnections();

private slots:
    void onInclinationRadioClicked();
    void onAltitudeRadioClicked();
    void onAscendingNodeRadioClicked();
    void onDescendingNodeRadioClicked();
    void onInclinationSliderChanged(int value);
    void onAltitudeSliderChanged(int value);
    void onAscendingNodeSliderChanged(int value);
    void onDescendingNodeSliderChanged(int value);
    void onColorButtonClicked();
    void onModelBrowseClicked();
    void onApplyClicked();
    void onOkClicked();

private:
    QComboBox* typeComboBox{nullptr};
    QLineEdit* satelliteNameEdit{nullptr};

    QGroupBox* geometryGroup{nullptr};
    QRadioButton* inclinationRadio{nullptr};
    QLineEdit* inclinationEdit{nullptr};
    QSlider* inclinationSlider{nullptr};

    QRadioButton* altitudeRadio{nullptr};
    QLineEdit* altitudeEdit{nullptr};
    QSlider* altitudeSlider{nullptr};

    QGroupBox* nodeGroup{nullptr};
    QRadioButton* ascendingNodeRadio{nullptr};
    QLineEdit* ascendingNodeEdit{nullptr};
    QSlider* ascendingNodeSlider{nullptr};

    QRadioButton* descendingNodeRadio{nullptr};
    QLineEdit* descendingNodeEdit{nullptr};
    QSlider* descendingNodeSlider{nullptr};

    QCheckBox* defaultObjectCheckBox{nullptr};

    QGroupBox* timePeriodGroup{nullptr};
    QComboBox* intervalComboBox{nullptr};

    QGroupBox* graphicsGroup{nullptr};
    QCheckBox* showAllObjectsCheckBox{nullptr};
    QPushButton* colorButton{nullptr};
    QLineEdit* modelEdit{nullptr};
    QPushButton* modelBrowseButton{nullptr};

    QFrame* mapFrame{nullptr};
    QLabel* latLonLabel{nullptr};
    QLabel* displayingLabel{nullptr};

    QPushButton* okButton{nullptr};
    QPushButton* cancelButton{nullptr};
    QPushButton* applyButton{nullptr};
    QPushButton* helpButton{nullptr};

    QColor currentColor;
};

AST_NAMESPACE_END
