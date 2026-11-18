/// @file      AggBackend.hpp
/// @brief     matplot++ Agg 后端 — 基于 Anti-Grain Geometry 的离屏渲染
/// @details   实现 matplot::backend::backend_interface, 将 figure_type 图元树
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-07

#pragma once

#include "AstGlobal.h"

#if defined(AST_WITH_AGG) && defined(AST_WITH_MATPLOT)
A_SUPPRESS_WARNINGS_BEGIN
#include <matplot/backend/backend_interface.h>
A_SUPPRESS_WARNINGS_END

#include <memory>
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// matplot++ Agg 后端
///
/// 非交互式后端，将 matplot figure 渲染到内存像素缓冲区 (RGBA32)，
/// 然后输出为 BMP 文件。
class AST_PLOT_API AggBackend : public matplot::backend::backend_interface {
public:
    AggBackend();
    virtual ~AggBackend() override;

    // ---- backend_interface 实现 ----

    bool consumes_gnuplot_commands() override;   // false
    bool is_interactive() override;              // false

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

/*! @} */

AST_NAMESPACE_END

#endif  // AST_WITH_AGG && AST_WITH_MATPLOT
