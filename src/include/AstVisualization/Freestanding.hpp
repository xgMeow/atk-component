/// @file      FreeStanding.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-06

#pragma once

#include "AstGlobal.h"
#include "AstVisualizationGlobal.h"
#include "AstCore/TimePoint.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


namespace visualization
{

/// @brief 获取当前的可视化视图，如果当前没有可视化视图，则会新建一个
/// @return 
AST_VISUALIZATION_API VisView* gcv();


AST_VISUALIZATION_API VisTrajectory* trajectory(Point* point=nullptr);


AST_VISUALIZATION_API VisGroundTrack* groundTrack(Point* point=nullptr);


AST_VISUALIZATION_API VisCelestialBody* planet(Body* body);


/// @brief 显示当前视图（在指定时刻渲染，用于定位随时间变化的天体等元素）
/// @param epoch 渲染时刻
AST_VISUALIZATION_API void show(const TimePoint& epoch);

/// @brief 显示当前视图（在当前时刻渲染）
AST_VISUALIZATION_API void show();

}

/*! @} */

AST_NAMESPACE_END
