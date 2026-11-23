/// @file      VolumeGrid.hpp
/// @brief     体积网格基类
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-29

#pragma once

#include "AstGlobal.h"
#include "AstUtil/ObjectNamed.hpp"
#include "AstMath/Vector.hpp"
#include "VolumeGridVisitor.hpp"

#include <vector>

AST_NAMESPACE_BEGIN

class Frame;

/// @brief 体积网格基类
/// @ingroup Spatial
class AST_CORE_API VolumeGrid : public ObjectNamed
{
public:
    VolumeGrid();
    ~VolumeGrid() override = default;

    /// @brief 接受访问者
    virtual void accept(VolumeGridVisitor& visitor) = 0;

    /// @brief 获取网格点总数
    virtual size_t getGridPointCount() const = 0;

    /// @brief 枚举所有网格点坐标
    /// @param points 输出的网格点坐标列表
    virtual void enumerateGridPoints(std::vector<Vector3d>& points) const = 0;

    /// @brief 获取包围盒
    /// @param[out] minCorner 最小角点坐标
    /// @param[out] maxCorner 最大角点坐标
    virtual void getBoundingBox(Vector3d& minCorner, Vector3d& maxCorner) const = 0;

    /// @brief 获取参考坐标系
    /// @return 参考坐标系指针，无坐标系时返回 nullptr
    virtual Frame* getFrame() const = 0;
};

AST_NAMESPACE_END
