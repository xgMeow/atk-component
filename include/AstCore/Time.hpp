/// @file      Time.hpp
/// @brief     
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      21.11.2025

#pragma once

#include "AstGlobal.h"
#include <cmath>        // for std::isinf

AST_NAMESPACE_BEGIN


/*!
    @addtogroup Time
    @{
*/



class Time;


/// @brief 规范化时间对象
/// @details 将时间中的秒、分进行进位或借位调整，使其处于合理范围内（0-59）
/// @param time 要规范化的时间对象
AST_CORE_CAPI void aTimeNormalize(Time& time);


/// @brief 从总秒数创建时间对象
/// @details 根据总秒数计算时、分、秒，并将结果存储在时间对象中
/// @param totalSecond 总秒数
/// @param time 要存储结果的时间对象
AST_CORE_CAPI void aTimeFromTotalSecond(double totalSecond, Time& time);


/// @brief 时间
class Time
{
public:
    int hour() const{return hour_;}
    int& hour(){return hour_;}
    int minute() const{return minute_;}
    int& minute(){return minute_;}
    double second() const{return second_;}
    double& second(){return second_;}
    void setHour(int hour){hour_ = hour;}
    void setMinute(int minute){minute_ = minute;}
    void setSecond(double second){second_ = second;}
    /// @brief 获取时间对象的总秒数
    /// @details 计算时间对象表示的总秒数，包括时、分、秒
    /// @return 时间对象的总秒数
    double totalSecond() const{return hour_ * 3600 + minute_ * 60 + second_;}
    /// @brief 获取时间对象的日分数
    /// @details 计算时间对象表示的日分数，范围为0-1
    /// @return 时间对象的日分数
    double dayFraction() const{return second_ / 86400.0 + minute_ / 1440.0 + hour_ / 24.0;}

    /// @brief 检查时间对象是否为无穷大
    bool isInf() const{return std::isinf(second_);}
public:
    /// @brief 规范化时间对象
    /// @details 将时间中的秒、分进行进位或借位调整，使其处于合理范围内（0-59）
    void normalize(){
        aTimeNormalize(*this);
    }

    /// @brief 获取规范化后的时间对象副本
    Time normalized() const{
        Time t = *this;
        aTimeNormalize(t);
        return t;
    }
public:
    int    hour_;       ///< 时
    int    minute_;     ///< 分
    double second_;     ///< 秒
};


/*! @} */

AST_NAMESPACE_END

