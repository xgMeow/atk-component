/// @file      AstPlotAPI.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-10-08

#pragma once

#include "AstGlobal.h"

namespace matplot{
    namespace backend{
        class backend_interface;
    }
}

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

AST_PLOT_CAPI matplot::backend::backend_interface* aNewAggBackend();

/*! @} */

AST_NAMESPACE_END
