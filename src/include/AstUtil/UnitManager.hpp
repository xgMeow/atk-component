/// @file      UnitManager.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-15

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Unit.hpp"
#include <unordered_map>
#include <map>
#include <string>
#include <vector>


AST_NAMESPACE_BEGIN

/*!
    @addtogroup Quantity
    @{
*/

class Unit;

/// @brief 获取单位
/// @param name 单位名称
/// @return 单位
AST_UTIL_API Unit* aUnitGet(StringView name);

/// @brief 获取国际制单位
/// @param dim 量纲
/// @return 国际制单位
AST_UTIL_API Unit* aUnitGetSI(Dimension dim);

/// @brief 获取默认单位
/// @param dim 量纲
/// @return 默认单位
AST_UTIL_API Unit* aUnitGetDefault(Dimension dim);


/// @brief 添加单位
/// @param unit 要添加的单位
/// @return errc_t 错误码
AST_UTIL_API errc_t aUnitAdd(const Unit& unit);


/// @brief 添加单位
/// @param name 单位名称
/// @param unit 要添加的单位
/// @return errc_t 错误码
AST_UTIL_API errc_t aUnitAdd(StringView name, const Unit& unit);

/// @brief 获取指定量纲下的所有单位
/// @param dim 量纲
/// @return 单位列表
AST_UTIL_API std::vector<Unit> aUnitsGetByDimension(Dimension dim);


/// @brief 单位管理器
class AST_UTIL_API UnitManager
{
public:
    /// @brief 获取单位管理器默认实例
    /// @return 单位管理器默认实例  
    static UnitManager& Instance();

    UnitManager();

    ~UnitManager();

    /// @brief 添加单位
    /// @param unit 要添加的单位
    errc_t addUnit(const Unit& unit);

    /// @brief 添加单位
    /// @param name 单位名称
    /// @param scale 单位缩放因子
    errc_t addUnit(StringView name, const Unit& unit);

    /// @brief 获取单位
    /// @param name 单位名称
    /// @return 单位
    Unit* getUnit(StringView name);

    /// @brief 获取国际制单位
    /// @param dim 单位维度
    /// @return 国际制单位
    Unit* getSiUnit(Dimension dim);

    /// @brief 获取指定量纲下的所有单位
    /// @param dim 量纲
    /// @return 单位列表（已按 scale+dimension 去重，同名单位保留名称最短者）
    std::vector<Unit> getUnitsByDimension(Dimension dim) const;

protected:

    /// @brief 添加单位
    /// @param name 单位名称
    /// @param unit 要添加的单位
    /// @return errc_t 错误码
    errc_t _addUnit(const std::string& name, const Unit& unit);

    Unit* _getSiUnitCache(Dimension dim);
protected:
    std::unordered_map<std::string, Unit*> units_{};      ///< 单位映射表
    std::map<Dimension, Unit*> siUnits_{};                ///< 国际制单位映射表
};

/*! @} */

AST_NAMESPACE_END
