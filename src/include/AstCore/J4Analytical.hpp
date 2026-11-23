/// @file      J4Analytical.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-05

#pragma once

#include "AstGlobal.h"
#include "J2J4Analytical.hpp"

AST_NAMESPACE_BEGIN


/*!
    @addtogroup Propagator
    @{
*/

class ModOrbElem;

class AST_CORE_API J4Analytical: public J2J4Analytical
{
public:
    /// @brief     构造函数
    /// @details   ~
    /// @param     modOrbElem 改进轨道根数
    /// @param     epoch      历元
    /// @param     gm         引力常数
    /// @param     j2         J2项
    /// @param     j4         J4项
    /// @param     re         天体半径
    J4Analytical(const ModOrbElem& modOrbElem, const TimePoint& epoch, double gm, double j2, double j4, double re);

    /// @brief     构造函数
    /// @details   ~
    /// @param     pos       位置向量
    /// @param     vel       速度向量
    /// @param     epoch     历元
    /// @param     gm        引力常数
    /// @param     j2        J2项
    /// @param     j4        J4项
    /// @param     re        天体半径
    J4Analytical(const Vector3d& pos, const Vector3d& vel, const TimePoint& epoch, double gm, double j2,  double j4, double re);

private:
    // double j2_;
    // double j4_;
    // double re_;
};

/// @brief     J4轨道预报
/// @details   
/// @param     duration 时间间隔
/// @param     gm       引力常数
/// @param     j2       J2项
/// @param     j4       J4项
/// @param     re       天体半径
/// @param     r        位置向量
/// @param     v        速度向量
/// @return    错误码
AST_CORE_API errc_t aJ4AnalyticalProp(double duration, double gm, double j2, double j4, double re, Vector3d& r, Vector3d& v);


/// @brief     J4轨道预报
/// @details   
/// @param     duration 时间间隔
/// @param     gm       引力常数
/// @param     j2       J2项
/// @param     j4       J4项
/// @param     re       天体半径
/// @param     modOrbElem 改进轨道根数
/// @return    错误码
AST_CORE_API errc_t aJ4AnalyticalProp(double duration, double gm, double j2, double j4, double re, ModOrbElem& modOrbElem);



/*! @} */


AST_NAMESPACE_END
