/// @file      QwtPlotVisitor.hpp
/// @brief     matplot++ visitor that creates Qwt plot items
/// @details   Implements matplot::visitor to convert axes_objects into Qwt plot items
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-19

#pragma once

#include "AstGlobal.h"
A_SUPPRESS_WARNINGS_BEGIN
#include <matplot/util/visitor.h>
A_SUPPRESS_WARNINGS_END
#include <array>
#include <QColor>


class QwtPlot;

AST_NAMESPACE_BEGIN

class ColoredSurfacePlot;

inline QColor toQColor(const std::array<float, 4>& c) {
    return QColor::fromRgbF(
        static_cast<double>(c[1]),
        static_cast<double>(c[2]),
        static_cast<double>(c[3]),
        static_cast<double>(1.0 - c[0]));
}

class QwtPlotVisitor : public matplot::visitor {
public:
    explicit QwtPlotVisitor(QwtPlot* plot);
    explicit QwtPlotVisitor(ColoredSurfacePlot* surface);
    ~QwtPlotVisitor() override;
    QwtPlotVisitor(const QwtPlotVisitor&) = delete;
    QwtPlotVisitor& operator=(const QwtPlotVisitor&) = delete;

    void visit(class matplot::line& l) override;
    void visit(class matplot::histogram& h) override;
    void visit(class matplot::function_line& fl) override;
    void visit(class matplot::stair& s) override;
    void visit(class matplot::surface& s) override;

private:
    QwtPlot* plot_{nullptr};
    ColoredSurfacePlot* surface_{nullptr};
};



AST_NAMESPACE_END
