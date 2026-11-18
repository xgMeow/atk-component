/// @file      UiTimelineView.hpp
/// @brief     任务分析时间轴视图控件
/// @details   自绘小时刻度轴 + 彩色区间条，数据来自
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-07

#pragma once

#include "AstGlobal.h"
#include "AstCore/TimePoint.hpp"
#include "AstCore/TimeInterval.hpp"
#include <QWidget>
#include <QColor>
#include <QString>
#include <vector>

AST_NAMESPACE_BEGIN

/// @brief 时间轴视图控件
///
/// 布局：
/// - 底部时间轴视口：顶端为小时刻度轴，刻度线正下方为彩色区间条，
///   左侧固定一列显示当前时刻（格式 "07 Sep 2026 04:00:00.000"）。
/// - 通过 setTimeSpan / setCurrentTime / setBars 填充数据。
class AST_UICORE_API UiTimelineView : public QWidget
{
    Q_OBJECT

public:
    /// @brief 时间轴区间条
    struct Bar
    {
        TimePoint start;    ///< 区间开始时间
        TimePoint stop;     ///< 区间结束时间
        QString   label;    ///< 区间名称
        QColor    color;    ///< 区间填充颜色
    };

public:
    explicit UiTimelineView(QWidget* parent = nullptr);
    ~UiTimelineView() override;

    UiTimelineView(const UiTimelineView&) = delete;
    UiTimelineView& operator=(const UiTimelineView&) = delete;

    /// @brief 设置时间轴整体显示区间
    void setTimeSpan(const TimeInterval& span);

    /// @brief 设置当前时刻（用于左侧时间标签）
    void setCurrentTime(const TimePoint& current);

    /// @brief 设置彩色区间条
    void setBars(const std::vector<Bar>& bars);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    /// @brief 将时间点映射到视口水平像素坐标
    qreal xFor(const TimePoint& t) const;

    TimePoint   start_{TimePoint::Epoch()};      ///< 时间轴起点
    TimePoint   stop_{TimePoint::Epoch()};       ///< 时间轴终点
    TimePoint   current_{TimePoint::Epoch()};    ///< 当前时刻
    std::vector<Bar> bars_{};                    ///< 区间条
};

AST_NAMESPACE_END
