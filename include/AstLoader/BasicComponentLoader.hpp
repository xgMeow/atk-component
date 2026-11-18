/// @file      BasicComponentLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-19

#pragma once

#include "AstGlobal.h"
#include "AstCore/EventInterval.hpp"
#include "AstCore/EventTime.hpp"
#include "AstCore/CelestialBody.hpp"


AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


struct VehiclePathData
{
    SharedPtr<CelestialBody> centralBody_{};
    bool storeEphemeris_ = false;
    bool smoothInterp_ = false;

    /// @brief 获取中心天体
    Body& getCentralBody() { return centralBody_?*centralBody_:*aGetDefaultBody(); }
};

/// @brief 获取对象文件扩展名
/// @details objectType 对象类型
/// @return 文件扩展名，例如 "sc", "sa", "fa", "sn"
AST_LOADER_API StringView aClassSTKExtension(StringView objectType);


errc_t _aLoadEventInterval(BKVParser& parser, SharedPtr<EventInterval>& eventInterval);
errc_t _aLoadEventTime(BKVParser& parser, SharedPtr<EventTime>& eventTime);
errc_t _aLoadSubObjects(BKVParser& parser, Object* parentObject);

/// @brief 跳过未知块
/// @details 跳过未知块，直到遇到指定块名
/// @param parser BKVParser
/// @param blockName 块名
/// @return errc_t 错误码
void _aSkipUnknownBlock(BKVParser& parser, StringView blockName);

/*! @} */

AST_NAMESPACE_END
