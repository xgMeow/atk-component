/// @file      TraitObject.hpp
/// @brief     
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      23.11.2025

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN


template<typename Interface>
class TraitObject : public Interface
{
public:

    void* data_;
};


template<typename I, typename T>
class ImplFor
{
    // you need to impl the trial for the type
};


AST_NAMESPACE_END

