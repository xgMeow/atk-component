/// @file      SGP4.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-18

#pragma once

#include "AstGlobal.h"
#include "TLELines.hpp"  // TLELines (TLE.hpp 依赖但未包含)
#include "TLE.hpp"
#include "AstCore/Ephemeris.hpp"

struct elsetrec;

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/



/// @brief SGP4 预报器
class AST_CORE_API SGP4: public Ephemeris
{
public:
    SGP4();
    SGP4(const TLE& tle);
    SGP4(const TLELines& lines);
    ~SGP4();
public:
    Frame* getFrame() const override;
    errc_t getPos(const TimePoint& tp, Vector3d& pos) const override;
    errc_t getPosVel(const TimePoint& tp, Vector3d& pos, Vector3d& vel) const override;
    errc_t getInterval(TimeInterval& interval) const override;
public:
    void setTLE(const TLE& tle);
    void setTLE(const TLELines& lines);
public:
    /// @brief 获取内部 SGP4 元素集（用于诊断）
    struct elsetrec& elementSet() const;
    /// @brief 获取 SGP4 错误码（0=正常，非0表示初始化或传播失败）
    int getError() const;
private:
    mutable std::aligned_storage<1000>::type storage_{};
};

/*! @} */

AST_NAMESPACE_END
