/// @file      GlobalContext.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-24

#pragma once

#include "AstGlobal.h"
#include "AstCore/IAUXYS.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Data
    @{
*/

/// @brief     全局上下文
/// @details   ~
class GlobalContext
{
public:
    GlobalContext() = default;
    ~GlobalContext() = default;

    /// @brief IAU XYS数据
	const IAUXYS* iauXYS() const {return &iauXYS_;}
    IAUXYS* iauXYS() {return &iauXYS_;}
protected:
	IAUXYS                  iauXYS_{};				///< IAU XYS数据 @todo: 这个考虑更改为静态数据
};

/*! @} */

AST_NAMESPACE_END
