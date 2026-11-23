/// @file      UiSelectFrame.hpp
/// @brief     坐标系选择器 — 天体列表 + Frame 列表，仿 STK VGT
/// @details   左侧列出 SolarSystem 中所有天体，右侧列出选中天体下的 Frame 子对象。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-17

#pragma once

#include "AstGlobal.h"
#include <QWidget>

class QListWidget;
class QListWidgetItem;

AST_NAMESPACE_BEGIN

class Frame;
class CelestialBody;

/// @brief 坐标系选择器 — 天体 + Frame 双列表选择
///
///      [天体列表]        [坐标系列表]
///      Earth         →  Inertial
///      Moon              ICRF
///      Mars              J2000
///      ...               ...
///
/// 数据源:
///   - 天体: aGetSolarSystem() → aFindChildren(CelestialBody)
///   - Frame: aFindChildren(body, Frame::StaticType())
///           若为空则先调用工厂方法创建并注册到天体下，再重新查询
class AST_UICORE_API UiSelectFrame : public QWidget
{
    Q_OBJECT
public:
    explicit UiSelectFrame(QWidget* parent = nullptr);
    ~UiSelectFrame() override;
    UiSelectFrame(const UiSelectFrame&) = delete;
    UiSelectFrame& operator=(const UiSelectFrame&) = delete;

    Frame* getSelectedFrame();
    void setSelectedFrame(Frame* frame);
    void setBody(CelestialBody* body);
    CelestialBody* getSelectedBody() const;

signals:
    void frameChanged(Frame* frame);

private slots:
    void onBodySelected();
    void onFrameSelected();

private:
    void setupUi();
    void populateBodies();
    void ensureFramesInitialized(CelestialBody* body);
    void populateFrames(CelestialBody* body);
    void resolveAndEmit();

    /// @brief 筛选天体 — 返回 true 表示该天体应在列表中显示（待扩展）
    static bool filterBody(CelestialBody* body);

    QListWidget* bodyList_ = nullptr;
    QListWidget* frameList_ = nullptr;
};

/// @brief 弹出模态对话框选择坐标系
AST_UICORE_CAPI Frame* aUiSelectFrame();

AST_NAMESPACE_END
