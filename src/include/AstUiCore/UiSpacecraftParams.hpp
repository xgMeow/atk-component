/// @file      UiSpacecraftParams.hpp
/// @brief     航天器参数编辑器
/// @details   编辑航天器气动、光压等属性参数
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-17

#pragma once

#include "AstGlobal.h"
#include "AstUiCore/UiObject.hpp"
#include <QWidget>

AST_NAMESPACE_BEGIN

class SpacecraftState;
class UiQuantity;

/// @brief 航天器参数编辑器（阻力、光压、反照压等）
class AST_UICORE_API UiSpacecraftParams : public UiObject
{
    Q_OBJECT
public:
    explicit UiSpacecraftParams(Object* object, QWidget* parent = nullptr);
    explicit UiSpacecraftParams(QWidget* parent = nullptr);
    ~UiSpacecraftParams() override;
    UiSpacecraftParams(const UiSpacecraftParams&) = delete;
    UiSpacecraftParams& operator=(const UiSpacecraftParams&) = delete;

    void setSpacecraftState(SpacecraftState* state);
    SpacecraftState* getSpacecraftState() const;

private:
    void setupUi();
    void refreshFromState(SpacecraftState* state);

    // 航天器参数控件
    UiQuantity*     dryMassEdit_ = nullptr;
    UiQuantity*     cdEdit_ = nullptr;
    UiQuantity*     dragAreaEdit_ = nullptr;
    UiQuantity*     crEdit_ = nullptr;
    UiQuantity*     srpAreaEdit_ = nullptr;
    UiQuantity*     ckEdit_ = nullptr;
    UiQuantity*     radPressureAreaEdit_ = nullptr;
    UiQuantity*     k1Edit_ = nullptr;
    UiQuantity*     k2Edit_ = nullptr;
};

AST_NAMESPACE_END
