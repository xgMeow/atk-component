/// @file      UiHPOPForceModel.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-22

#pragma once

#include "AstGlobal.h"
#include "AstUiCore/UiObject.hpp"
#include <QVBoxLayout>
#include <QGroupBox>
#include <QComboBox>
#include <QRadioButton>
#include <QCheckBox>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QLabel>
#include <QTabWidget>
#include <QFileDialog>

#include "AstUiCore/UiDragForce.hpp"
#include "AstUiCore/UiSolarRadiationPressure.hpp"
#include "AstUiCore/UiGravityForce.hpp"
#include "AstUiCore/UiThirdBodyForce.hpp"
#include "AstUiCore/UiThirdBodyForceList.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class HPOPForceModel;

class AST_UICORE_API UiHPOPForceModel: public UiObject
{
    Q_OBJECT
public:
    UiHPOPForceModel(const UiHPOPForceModel&) = delete;
    UiHPOPForceModel& operator=(const UiHPOPForceModel&) = delete;
    UiHPOPForceModel(Object* object, QWidget *parent = nullptr);
    UiHPOPForceModel(QWidget *parent = nullptr);
    ~UiHPOPForceModel() = default;

    HPOPForceModel* getHPOPForceModel() const;
    void setHPOPForceModel(HPOPForceModel* hpop);
    void refreshUi();
    void apply();
protected:
    void setupUi();
private slots:
    void applyTo(HPOPForceModel* hpop);
private:
    // 布局
    QVBoxLayout* mainLayout_{};
    QTabWidget* tabWidget_{};

    // 引力模型标签页
    QWidget* gravityTab_{};
    QVBoxLayout* gravityTabLayout_{};
    UiGravityForce* gravityWidget_{};

    // 三体引力配置
    QWidget* thirdBodyTab_{};
    QVBoxLayout* thirdBodyTabLayout_{};
    UiThirdBodyForceList* thirdBodyWidget_{};

    // 大气阻力标签页
    QWidget* dragTab_{};
    QVBoxLayout* dragTabLayout_{};
    UiDragForce* dragWidget_{};

    // 太阳光压标签页
    QWidget* srpTab_{};
    QVBoxLayout* srpTabLayout_{};
    UiSolarRadiationPressure* srpWidget_{};


};


/*! @} */

AST_NAMESPACE_END