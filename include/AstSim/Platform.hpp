/// @file      Platform.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-01

#pragma once

#include "AstGlobal.h"
#include "AstCore/Point.hpp"
#include "AstCore/Axes.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 通用平台类，用于表示空间中的平台对象，例如卫星、飞机、地面站等，具有位置、姿态两个属性
/// @details 内部分别用Point和Axes抽象类来表示位置、姿态两个属性
/// @note 为什么继承Point类？
/// 因为一个对象的位置是确定的，但是姿态可以存在多种定义，例如体轴、对地定向、对速度定向、对三维模型定向等
class AST_SIM_API Platform : public Point
{
public:
    AST_OBJECT(Platform)
    Platform();
    Platform(Point* location, Axes* orientation);
    ~Platform() = default;
public:
    Frame* getFrame() const override;
    errc_t getPos(const TimePoint& tp, Vector3d& pos) const override;
    errc_t getPosVel(const TimePoint& tp, Vector3d& pos, Vector3d& vel) const override;
    errc_t getInterval(TimeInterval& interval) const override;
public:
    Point* location() const {return location_.get();}
    Axes* orientation() const {return orientation_.get();}
    void setLocation(Point* location);
    void setOrientation(Axes* orientation);
public:
    Frame& bodyFrame() const {return *bodyFrame_;}
    Axes& bodyAxes() const {return *bodyAxes_;}
private:
    SharedPtr<Point> location_{};         ///< 平台位置
    SharedPtr<Axes>  orientation_{};      ///< 平台姿态
private:
    SharedPtr<Frame> bodyFrame_{};        ///< 平台体坐标系
    SharedPtr<Axes> bodyAxes_{};          ///< 平台体轴系
};



/*! @} */

AST_NAMESPACE_END
