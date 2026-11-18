/// @file      EphemerisLagrangeVar.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-14

#pragma once

#include "AstGlobal.h"
#include "AstCore/Ephemeris.hpp"
#include "AstCore/TimePoint.hpp"
#include "AstCore/TimeList.hpp"
#include "AstCore/Frame.hpp"
#include "AstMath/Vector.hpp"
#include <vector>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 可变步长拉格朗日插值星历
class AST_CORE_API EphemerisLagrangeVar: public Ephemeris
{
public:
    AST_OBJECT(EphemerisLagrangeVar)
    EphemerisLagrangeVar() = default;
    explicit EphemerisLagrangeVar(Frame* frame) : frame_(frame){}
    ~EphemerisLagrangeVar() = default;
public:
    Frame* getFrame() const override;
    errc_t getPos(const TimePoint& tp, Vector3d& pos) const override;
    errc_t getPosVel(const TimePoint& tp, Vector3d& pos, Vector3d& vel) const override;
    errc_t getInterval(TimeInterval& interval) const override;
public:
    void setFrame(Frame* frame){frame_ = frame;}
    void setTimes(const std::vector<double>& times);
    void setTimes(std::vector<double>&& times);
    void setPositions(const std::vector<Vector3d>& positions){positions_ = positions;}
    void setPositions(std::vector<Vector3d>&& positions){positions_ = std::move(positions);}
    void setVelocities(const std::vector<Vector3d>& velocities){velocities_ = velocities;}
    void setVelocities(std::vector<Vector3d>&& velocities){velocities_ = std::move(velocities);}
    void setEpoch(const TimePoint& epoch){epoch_ = epoch;}
    void setInterpolateOrder(int order){interpolateOrder_ = order;}
    const TimePoint& getEpoch() const{return epoch_;}
    const std::vector<double>&   getTimes()     const{return times_;}
    const std::vector<Vector3d>& getPositions() const{return positions_;}
    const std::vector<Vector3d>& getVelocities()const{return velocities_;}
    int interpolateOrder() const{return interpolateOrder_;}
    void getTimes(TimeList& list) const;
public:
    size_t size() const{return times_.size();}
private:
    int findIndex(double delta) const;
protected:
    SharedPtr<Frame>      frame_{};                  ///< 参考坐标系
    std::vector<double>   times_{};                  ///< 时间(单位：秒)
    std::vector<Vector3d> positions_{};              ///< 位置(单位：米)
    std::vector<Vector3d> velocities_{};             ///< 速度(单位：米/秒)
    TimePoint             epoch_{};                 ///< 历元时间
    double                averageStep_{60};         ///< 平均时间步长，用于估计插值开始的时间
    int                   interpolateOrder_{5};     ///< 插值阶数
};


/*! @} */

AST_NAMESPACE_END
