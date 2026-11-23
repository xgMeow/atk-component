/// @file      UiTimePoint.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-28

#pragma once

#include "AstGlobal.h"
#include "AstCore/TimePoint.hpp"
#include "UiValueEdit.hpp"
#include <QLineEdit>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_UICORE_API UiTimePoint : public UiValueEdit
{
    Q_OBJECT
public:
    explicit UiTimePoint(QWidget* parent = nullptr);
    ~UiTimePoint() = default;
    const TimePoint& getTimePoint() const { return timePoint_; }
    void setTimePoint(const TimePoint& timePoint);
signals:
    void timePointChanged(const TimePoint& timePoint);
private:
    void updateTimePoint();
private:
    TimePoint timePoint_{};
};

/*! @} */

AST_NAMESPACE_END