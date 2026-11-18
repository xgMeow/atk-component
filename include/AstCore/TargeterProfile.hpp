/// @file      TargeterProfile.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-28

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Object.hpp"
#include "AstUtil/ObjectNamed.hpp"
#include "AstCore/Command.hpp"
#include <vector>
#include <string>

AST_NAMESPACE_BEGIN


class TargeterProfile;

using HTargeterProfile = SharedPtr<TargeterProfile>;
using PTargeterProfile = TargeterProfile*;

/// @brief 目标器配置文件基类
class AST_CORE_API TargeterProfile : public Command
{
public:
    AST_OBJECT(TargeterProfile)

    /// @brief 执行目标器配置
    virtual errc_t execute() override = 0;

    TargeterProfile() = default;
    ~TargeterProfile() override = default;
};





AST_NAMESPACE_END