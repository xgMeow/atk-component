/// @file      MSISBase.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-25

#pragma once

#include "AstGlobal.h"
#include "AtmosphereBase.hpp"
#include "AstCore/ConstantSpaceWeather.hpp"
#include "AstUtil/ScopedPtr.hpp"
#include <type_traits>
#include <array>


typedef struct msisrecord msistype;
typedef struct lpolyrecord lpolytype;
typedef struct fitrecord fittype;
typedef struct lsqvrecord lsqvtype;



AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief MSIS86大气模型基类
class AST_CORE_API MSISBase : public AtmosphereBase
{
public:
    class WorkSpace;
    using ApArray = std::array<double, 7>;

    MSISBase(Frame* frame, BodyShape* bodyShape, double f107Daily, double f107Average, double ap);
    MSISBase(Frame* frame, BodyShape* bodyShape, SpaceWeatherProvider* spaceWeather);
    ~MSISBase();

    void setSpaceWeatherProvider(SpaceWeatherProvider* spaceWeather);
    void setConstantSpaceWeather(double f107Daily, double f107Average, double ap);
    bool useDailyAp() const { return useDailyAp_; }
    void setUseDailyAp(bool useDailyAp);

    static SpaceWeatherProvider* NewConstantSpaceWeather(double f107Daily, double f107Average, double ap);
protected:
    WorkSpace& workSpace() const { return *reinterpret_cast<WorkSpace*>(&storage_); }
    msistype& msis() const;
    lpolytype& lpoly() const;
    fittype& fit() const;
    lsqvtype& lsqv() const;
protected:
    struct MSISParam
    {
        int dayOfYear;
        double secOfDay;
        double lst;
        double alt; // [km]
        double lat; // [deg]
        double lon; // [deg]
        double f107A;
        double f107;
        ApArray ap;
        static constexpr int mass = 48;
    };
    static void getTimeParam(const TimePoint& tp, double lon, int& dayOfYear, double& secOfDay, double& lst);
    void getMSISParam(const TimePoint& tp, const Vector3d& posInBodyFixed, MSISParam& param) const;
    void getSpaceWeather(const TimePoint& tp, double& f107, double& f107Average, ApArray& aparray) const;
protected:
    ScopedPtr<SpaceWeatherProvider> spaceWeather_;    ///< 空间天气数据源
private:
    mutable std::aligned_storage<57000>::type storage_{};
    bool useDailyAp_{true};                           ///< 是否使用每日Ap值，否则使用3小时Ap值
};

/*! @} */

AST_NAMESPACE_END
