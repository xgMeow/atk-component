/// @file      ColoredMeshEnrichment.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-22

#pragma once

#include "AstGlobal.h"
#ifdef AST_WITH_QWT
#include <qwt3d_surfaceplot.h>
#include <qwt3d_enrichment.h>


AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/



/// Qwt3D Enrichment 子类 — 在 drawBegin() 中渲染遮挡面 + 逐顶点着色的网格线
/// 配合 ColoredMeshPlot 使用
class ColoredSurfaceEnrichment : public Qwt3D::VertexEnrichment {
public:
    ColoredSurfaceEnrichment() = default;
    explicit ColoredSurfaceEnrichment(Qwt3D::PLOTSTYLE plotStyle)
        : plotStyle_(plotStyle) {}
    ColoredSurfaceEnrichment(const ColoredSurfaceEnrichment&) = default;
    ColoredSurfaceEnrichment& operator=(const ColoredSurfaceEnrichment&) = default;
    ColoredSurfaceEnrichment* clone() const override { return new ColoredSurfaceEnrichment(*this); }
    void drawBegin() override;
    void draw(Qwt3D::Triple const &) override;
public:
    /// 在 createEnrichment() 覆写中，drawBegin() 调用前设置数据
    void setData(const Qwt3D::GridData* grid);
    void setPlotStyle(Qwt3D::PLOTSTYLE plotStyle){plotStyle_ = plotStyle;}
    Qwt3D::PLOTSTYLE plotStyle() const {return plotStyle_;}
    const Qwt3D::SurfacePlot* surface() const;

private:
    const Qwt3D::GridData* grid_{nullptr};
    Qwt3D::PLOTSTYLE plotStyle_{Qwt3D::WIREFRAME};

    void drawFaces();               ///< 面渲染
    void drawColoredMeshLines();    ///< 逐顶点着色的网格线
};


/*! @} */

AST_NAMESPACE_END

#endif
