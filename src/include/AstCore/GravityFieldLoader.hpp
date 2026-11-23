/// @file      GravityFieldLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-02-24

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"
#include "AstUtil/BKVParser.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class GravityFieldHead;
class GravityField;

/// @brief 重力场加载器
/// @details 用于加载重力场文件并解析其中的系数或头信息
/// 这个类记录了加载重力场时的一些选项参数
/// 如最大加载阶数、最大加载次数、重力场模型文件所在目录路径等
/// @warning 注意单个Loader实例不能同时加载多个重力场文件
class GravityFieldLoader
{
public:
    explicit GravityFieldLoader(StringView dirpath)
        : dirpath_(dirpath)
    {}

    GravityFieldLoader(const GravityFieldLoader&) = delete;
    GravityFieldLoader& operator=(const GravityFieldLoader&) = delete;

    GravityFieldLoader(int maxLoadDegree, int maxLoadOrder, StringView dirpath)
        : dirpath_(dirpath), maxLoadDegree_(maxLoadDegree), maxLoadOrder_(maxLoadOrder)
    {}
    ~GravityFieldLoader() = default;

    AST_CORE_API
    errc_t load(StringView filePath, GravityField& gravityField);

    AST_CORE_API
    errc_t load(StringView filePath, GravityFieldHead& head);

    /// @brief 获取最大加载阶数
    int getMaxLoadDegree() const { return maxLoadDegree_; }

    /// @brief 获取最大加载次数
    int getMaxLoadOrder() const { return maxLoadOrder_; }

    /// @brief 设置最大加载阶数
    void setMaxLoadDegree(int maxLoadDegree) { maxLoadDegree_ = maxLoadDegree; }

    /// @brief 设置最大加载次数
    void setMaxLoadOrder(int maxLoadOrder) { maxLoadOrder_ = maxLoadOrder; }

public:    
    BKVParser parser_{};                     ///< 解析器
    GravityFieldHead* head_{nullptr};       ///< 重力场头
    GravityField* coeff_{nullptr};          ///< 重力场系数
    StringView dirpath_{};                    ///< 重力场模型文件所在目录路径
    int maxLoadDegree_ {-1};                ///< 最大加载阶数
    int maxLoadOrder_ {-1};                 ///< 最大加载次数
};



/*! @} */

AST_NAMESPACE_END
