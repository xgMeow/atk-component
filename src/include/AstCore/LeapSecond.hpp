/// @file      LeapSecond.hpp
/// @brief     
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      29.11.2025

#pragma once

#include "AstGlobal.h"
#include <cstdio>
#include <vector>

AST_NAMESPACE_BEGIN


/*!
    @addtogroup Data
    @{
*/



class JulianDate;
class TimePoint;
class Date;

/// @brief  闰秒类
/// @details 该类用于读取、存储和处理闰秒数据。
/// @todo 支持读取Spice的闰秒内核文件
class AST_CORE_API LeapSecond
{
public:
    struct Entry
    {
        int mjd;
        int leapSecond;
    };
public:
    LeapSecond();
public:
	/// @brief  从文件加载闰秒数据，按照默认格式进行加载
	/// @param  filepath - 文件路径
	/// @retval          - 错误码
    errc_t load(StringView filepath);

	/// @brief  从HPIERS格式文件加载闰秒数据
	/// @details 见 <https://hpiers.obspm.fr/iers/bul/bulc/Leap_Second.dat>
	/// @param  filepath - 文件路径
	/// @retval          - 错误码
	errc_t loadHPIERS(StringView filepath);

	/// @brief  从ATK格式文件加载闰秒数据
	/// @param  filepath - 文件路径
	/// @retval          - 错误码
	errc_t loadATK(StringView filepath);

    /// @brief 从默认文件加载闰秒数据
    /// @return 错误码
    errc_t loadDefault();

	/// @brief  设置默认数据
	void setDefaultData();

	/// @brief  设置数据
	void setData(const std::vector<int>& mjd, const std::vector<int>& taiMinusUTC);
protected:
	/// @brief  从ATK格式文件加载闰秒数据
	/// @param  file - ATK格式文件指针
	/// @retval          - 错误码
    errc_t loadATK(FILE* file);

	/// @brief  从STK格式文件加载闰秒数据
	/// @param  file - STK格式文件指针
	/// @retval          - 错误码
	errc_t loadSTK(FILE* file);

	/// @brief  从HPIERS格式文件加载闰秒数据
	/// @details 见 <https://hpiers.obspm.fr/iers/bul/bulc/Leap_Second.dat>
	/// @param  file - HPIERS格式文件指针
	/// @retval          - 错误码
    errc_t loadHPIERS(FILE* file);

	/// @brief  从SPICE内核文件加载闰秒数据
	/// @details 见 <https://naif.jpl.nasa.gov/pub/naif/toolkit_docs/C/req/kernel.html>
	/// @param  file - SPICE内核文件指针
	/// @retval          - 错误码
	errc_t loadSpice(FILE* file);
public:
	/// @brief  获取UTC秒数
	/// @param  jdUTC -  儒略日Julian Date (UTC)
	/// @retval       -  闰秒数
	double leapSecondUTC(ImpreciseJD jdUTC);
	double leapSecondUTCMJD(ImpreciseMJD mjdUTC);

	/// @brief  获取TAI秒数
	/// @param  jdTAI -  儒略日Julian Date (TAI)
	/// @retval       -  闰秒数
	double leapSecondTAI(ImpreciseJD jdTAI);
	double leapSecondTAIMJD(ImpreciseMJD mjdTAI);


    /// @brief  获取当天的UTC秒数
	/// @param  utcDate -  UTC日期
	/// @retval          -  当天的UTC秒数
	double getLodUTC(const Date& utcDate);

	/// @brief  获取当天的UTC秒数
	/// @param  mjdUTC -   简约儒略日Modified Julian Date (UTC)
	/// @retval          -  当天的UTC秒数
	double getLodUTCMJD(ImpreciseMJD mjdUTC);

	/// @brief  获取闰秒数据
	const std::vector<Entry>& data() const { return data_; }
	std::vector<Entry>& data() { return data_; }


protected:
    std::vector<Entry> data_{};
};


/*! @} */


AST_NAMESPACE_END
