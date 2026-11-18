/// @file      UiTimeInterval.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-28

#pragma once

#include "AstGlobal.h"
#include "AstCore/TimeInterval.hpp"
#include "UiTimePoint.hpp"
#include <QWidget>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup GUI
    @{
*/

/// @brief 时间区间编辑控件
/// @details 用于编辑和显示时间区间，由两个时间点编辑控件组成
class AST_UICORE_API UiTimeInterval : public QWidget
{
    Q_OBJECT
public:
    explicit UiTimeInterval(QWidget* parent = nullptr);
    ~UiTimeInterval() = default;
    UiTimeInterval(const UiTimeInterval&) = delete;
    UiTimeInterval& operator=(const UiTimeInterval&) = delete;

    /// @brief 设置时间区间
    /// @param timeInterval 时间区间
    void setTimeInterval(const TimeInterval& timeInterval);

    /// @brief 获取时间区间
    /// @return 时间区间
    const TimeInterval& getTimeInterval() const { return timeInterval_; }
signals:
    void timeIntervalChanged(const TimeInterval& timeInterval);
private:
    void updateTimeInterval();
private:
    UiTimePoint* startTimeEdit_{nullptr};
    UiTimePoint* stopTimeEdit_{nullptr};
    TimeInterval timeInterval_{};
};

/*! @} */

AST_NAMESPACE_END
