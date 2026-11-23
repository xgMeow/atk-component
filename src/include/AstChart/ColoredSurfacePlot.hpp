/// @file      ColoredSurfacePlot.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-22

#pragma once

#include "AstGlobal.h"
#ifdef AST_WITH_QWT
#include "qwt3d_surfaceplot.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


class ColoredSurfacePlot : public Qwt3D::SurfacePlot {
public:
    using Qwt3D::SurfacePlot::SurfacePlot;
protected:
    void createEnrichment(Qwt3D::Enrichment& p) override;
};

/*! @} */

AST_NAMESPACE_END


#endif