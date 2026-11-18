/// @file      QwtBackend.hpp
/// @brief     matplot++ Qwt backend
/// @details   Qt/Qwt rendering backend for matplot++
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-19

#pragma once

#include "AstGlobal.h"

#if defined(AST_WITH_MATPLOT) && defined(AST_WITH_QWT)

A_SUPPRESS_WARNINGS_BEGIN
#include <matplot/backend/backend_interface.h>
A_SUPPRESS_WARNINGS_END
#include <memory>
#include <string>

class QwtFigure;

AST_NAMESPACE_BEGIN

class UiFigure;

class AST_CHART_API QwtBackend : public matplot::backend::backend_interface {
public:
    QwtBackend();
    virtual ~QwtBackend() override;

    bool consumes_gnuplot_commands() override;
    bool is_interactive() override;

    const std::string& output() override;
    const std::string& output_format() override;
    bool output(const std::string& filename) override;
    bool output(const std::string& filename,
                const std::string& file_format) override;

    unsigned int width() override;
    unsigned int height() override;
    void width(unsigned int new_width) override;
    void height(unsigned int new_height) override;

    unsigned int position_x() override;
    unsigned int position_y() override;
    void position_x(unsigned int new_position_x) override;
    void position_y(unsigned int new_position_y) override;

    void window_title(const std::string& title) override;
    std::string window_title() override;

    bool new_frame() override;
    bool render_data() override;
    void show(matplot::figure_type* f) override;
    bool should_close() override;
    bool supports_fonts() override;

    void draw(matplot::figure_type* f) override;
private:
    struct Impl;
    std::unique_ptr<Impl> impl_;
};

AST_NAMESPACE_END
#endif


AST_NAMESPACE_BEGIN

AST_CHART_API void aUseQwtBackend();

AST_NAMESPACE_END
