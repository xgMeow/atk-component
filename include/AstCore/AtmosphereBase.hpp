/// @file      AtmosphereBase.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-25

#pragma once

#include "AstGlobal.h"
#include "Atmosphere.hpp"
#include "AstUtil/I18n.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

constexpr const char* kInfoInvalidHeight = N_("高度低于 %d km, 该模型不适用, 返回无效值");

class AST_CORE_API AtmosphereBase: public Atmosphere
{
public:
    AtmosphereBase(Frame* frame, BodyShape* bodyShape);
    ~AtmosphereBase() override = default;

    AtmosphereBase(const AtmosphereBase&) = delete;
    AtmosphereBase& operator=(const AtmosphereBase&) = delete;

    /// @brief 获取大气密度
    /// @param tp 当前时间
    /// @param posInBodyFixed 当前位置(相对于getFrame()返回的坐标系)
    /// @return 大气密度（单位：kg/m³）
    double getDensity(const TimePoint& tp, const Vector3d& posInBodyFixed) const override = 0;

    /// @brief 获取大气模型的参考坐标系
    Frame* getFrame() const override{return frame_;}

    /// @brief 获取大气模型对应天体形状
    BodyShape* getShape() const override {return bodyShape_;}
public:
    /// @brief 是否使用近似高度计算
    bool useApproximateAltitude() const {return useApproximateAltitude_;}

    /// @brief 设置是否使用近似高度计算
    void setUseApproximateAltitude(bool useApproximateAltitude) {useApproximateAltitude_ = useApproximateAltitude;}

    /// @brief 获取位置的地理坐标
    /// @param posInBodyFixed 当前位置(相对于getFrame()返回的坐标系)
    /// @param latitude 纬度（单位：弧度）
    /// @param longitude 经度（单位：弧度）
    /// @param altitude 高度（单位：米），根据是否使用近似高度计算，其返回值不同
    void getGeodetic(const Vector3d& posInBodyFixed, double& latitude, double& longitude, double& altitude) const;

    /// @brief 获取位置的高度
    /// @param posInBodyFixed 当前位置(相对于getFrame()返回的坐标系)
    /// @param altitude 高度（单位：米），根据是否使用近似高度计算，其返回值不同
    double getAltitude(const Vector3d& posInBodyFixed) const;
protected:
    Frame* frame_{nullptr};              ///< 大气模型的参考坐标系
    BodyShape* bodyShape_{nullptr};      ///< 大气模型对应天体形状
    bool useApproximateAltitude_{false}; ///< 是否使用近似高度计算
};

/*! @} */

AST_NAMESPACE_END
