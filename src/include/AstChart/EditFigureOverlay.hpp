/// @file      EditFigureOverlay.hpp
/// @brief     QwtFigureWidgetOverlay 子类，编辑模式下 Inner 区域点击穿透给 picker
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-06

#pragma once

#include "AstGlobal.h"
#ifdef AST_WITH_QWT
#include <qwt_figure_widget_overlay.h>

AST_NAMESPACE_BEGIN

/// @brief 编辑模式专用 QwtFigureWidgetOverlay 子类
/// @details 重写 mousePressEvent：子图内部（Inner）区域点击时 ignore() 穿透给 PlotElementPicker，
///          边框/边角仍由父类处理缩放和选中切换。
class AST_CHART_API EditFigureOverlay : public QwtFigureWidgetOverlay {
public:
    using QwtFigureWidgetOverlay::QwtFigureWidgetOverlay;

protected:
    void mousePressEvent(QMouseEvent* me) override;
    void mouseMoveEvent(QMouseEvent* me) override;
    void drawControlLine(QPainter* painter, const QRect& actualRect, const QRectF& normRect) const override;
};

AST_NAMESPACE_END

#endif
