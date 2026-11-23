/// @file      J2Analytical.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-31

#pragma once

#include "AstGlobal.h"
#include "AstCore/OrbitElement.hpp"
#include "AstCore/TimePoint.hpp"
#include "J2J4Analytical.hpp"

AST_NAMESPACE_BEGIN



/*!
    @ingroup   Core
    @defgroup Propagator 轨道预报
    @brief 提供二体、J2、J4、HPOP等轨道预报器
*/

/*!
    @addtogroup Propagator
    @{
*/



class ModOrbElem;       ///< 改进轨道根数
class TimePoint;        ///< 时间点



class AST_CORE_API J2Analytical : public J2J4Analytical
{
public:
    /// @brief     构造函数
    /// @details   ~
    /// @param     modOrbElem 改进轨道根数
    /// @param     epoch      参考时间点
    /// @param     gm         引力常数
    /// @param     j2         J2项
    /// @param     re         天体半径
    J2Analytical(const ModOrbElem& modOrbElem, const TimePoint& epoch, double gm, double j2, double re);

    /// @brief     构造函数
    /// @details   ~
    /// @param     pos        位置向量
    /// @param     vel        速度向量
    /// @param     epoch      参考时间点
    /// @param     gm         引力常数
    /// @param     j2         J2项
    /// @param     re         天体半径
    J2Analytical(const Vector3d& pos, const Vector3d& vel, const TimePoint& epoch, double gm, double j2, double re);


protected:
    double j2_;              ///< J2项
    double re_;              ///< 天体半径
};


/// @brief     J2轨道预报
/// @details   
/// @param     duration 时间间隔
/// @param     gm       引力常数
/// @param     j2       J2项
/// @param     re       天体半径
/// @param     r        位置向量
/// @param     v        速度向量
/// @return    错误码
AST_CORE_API errc_t aJ2AnalyticalProp(double duration, double gm, double j2, double re, Vector3d& r, Vector3d& v);


/// @brief     J2轨道预报
/// @details   
/// @param     duration 时间间隔
/// @param     gm       引力常数
/// @param     j2       J2项
/// @param     re       天体半径
/// @param     modOrbElem 改进轨道根数
/// @return    错误码
AST_CORE_API errc_t aJ2AnalyticalProp(double duration, double gm, double j2, double re, ModOrbElem& modOrbElem);


/*! @} */

AST_NAMESPACE_END
