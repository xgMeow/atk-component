/// @file      FacilityLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class Facility;


/// @brief 加载设施
/// @param parser BKV解析器
/// @param objectType 对象类型
/// @param facility 设施引用
/// @return 错误码
AST_LOADER_API errc_t aLoadFacility(BKVParser& parser, StringView objectType, Facility& facility);

/// @brief 加载设施
/// @details 从文件加载设施
/// @param parser BKV解析器
/// @param facility 设施引用
/// @return 错误码
AST_LOADER_API errc_t aLoadFacility(BKVParser& parser, Facility& facility);


/// @brief 加载设施
/// @details 从文件加载设施
/// @param filepath 文件路径
/// @param objectType 对象类型
/// @param facility 设施引用
/// @return 错误码
AST_LOADER_API errc_t aLoadFacility(StringView filepath, StringView objectType, Facility& facility);

/// @brief 加载设施
/// @details 从文件加载设施
AST_LOADER_API errc_t aLoadFacility(StringView filepath, Facility& facility);

/*! @} */

AST_NAMESPACE_END
