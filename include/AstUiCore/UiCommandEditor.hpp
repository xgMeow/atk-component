/// @file      UiCommandEditor.hpp
/// @brief     段属性编辑器，根据选中段类型切换子编辑器
/// @details   基于 QStackedWidget，注册各类 Segment 对应的编辑页面
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-17

#pragma once

#include "AstGlobal.h"
#include "AstCore/MissionCommand.hpp"
#include <QStackedWidget>
#include <unordered_map>

AST_NAMESPACE_BEGIN

class Class;
class UiInitialState;
class UiPropagate;
class UiManeuver;
class UiSequence;
class UiTargeterSequence;
class UiFeasibleRegionStudy;

/// @brief 命令属性编辑器，根据 RTTI 类型自动切换编辑页面
class AST_UICORE_API UiCommandEditor : public QStackedWidget
{
    Q_OBJECT
public:
    explicit UiCommandEditor(QWidget* parent = nullptr);
    ~UiCommandEditor() override;
    UiCommandEditor(const UiCommandEditor&) = delete;
    UiCommandEditor& operator=(const UiCommandEditor&) = delete;

    /// @brief 编辑指定命令 — 根据 RTTI 类型切换编辑器
    void editCommand(MissionCommand* cmd);

    /// @brief 清除当前编辑
    void clear();

signals:
    void commandModified(MissionCommand* cmd);

private:
    void registerEditors();
    void setupUi();

    UiInitialState*         initStatePage_ = nullptr;
    UiPropagate*            propagatePage_ = nullptr;
    UiManeuver*             maneuverPage_ = nullptr;
    UiSequence*             sequencePage_ = nullptr;
    UiTargeterSequence*     targetSeqPage_ = nullptr;
    UiFeasibleRegionStudy*  feasibleRegionPage_ = nullptr;

    int initStateIdx_ = -1;
    int propagateIdx_ = -1;
    int maneuverIdx_ = -1;
    int sequenceIdx_ = -1;
    int targetSeqIdx_ = -1;
    int feasibleRegionIdx_ = -1;
};

AST_NAMESPACE_END
