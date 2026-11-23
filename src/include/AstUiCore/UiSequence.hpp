/// @file      UiSequence.hpp
/// @brief     Sequence / TargeterSequence 段编辑器
/// @details   重复次数、脚本工具、打靶配置
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-17

#pragma once

#include "AstGlobal.h"
#include "AstUiCore/UiObject.hpp"
#include <QSpinBox>
#include <QCheckBox>

AST_NAMESPACE_BEGIN

class Sequence;
class TargeterSequence;

/// @brief Sequence 段编辑器
class AST_UICORE_API UiSequence : public UiObject
{
    Q_OBJECT
public:
    explicit UiSequence(Object* object, QWidget* parent = nullptr);
    explicit UiSequence(QWidget* parent = nullptr);
    ~UiSequence() override;
    UiSequence(const UiSequence&) = delete;
    UiSequence& operator=(const UiSequence&) = delete;

    void setSequence(Sequence* seq);
    Sequence* getSequence() const;

private slots:
    void onRepeatCountChanged(int value);

private:
    void setupUi();

    QSpinBox* repeatCountSpin_ = nullptr;
};

/// @brief TargeterSequence 段编辑器（在 Sequence 基础上增加打靶配置）
class AST_UICORE_API UiTargeterSequence : public UiObject
{
    Q_OBJECT
public:
    explicit UiTargeterSequence(Object* object, QWidget* parent = nullptr);
    explicit UiTargeterSequence(QWidget* parent = nullptr);
    ~UiTargeterSequence() override;

    UiTargeterSequence(const UiTargeterSequence&) = delete;
    UiTargeterSequence& operator=(const UiTargeterSequence&) = delete;

    void setTargeterSequence(TargeterSequence* seq);
    TargeterSequence* getTargeterSequence() const;

private:
    void setupUi();

    QSpinBox* repeatCountSpin_ = nullptr;
};

AST_NAMESPACE_END
