/// @file      TimeScale.hpp
/// @brief     
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      21.11.2025

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN


/// @brief 时间尺度，例如TT TDB TAI UTC 等
class TimeScale
{
public:
    enum ETimeScale
    {
        eTT,
        eTAI,
        eUTC,
        eTDB
    };
};


class TAIScale
{
public:

};

class UTCScale
{
public:

};


class TDBScale
{
public:

};



AST_NAMESPACE_END

