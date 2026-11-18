/// @file      MockUninitializedPointer.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-08

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Object.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class MockUninitializedPointer
{
public:
    MockUninitializedPointer();
    ~MockUninitializedPointer();

    MockUninitializedPointer(const MockUninitializedPointer&) = delete;
    MockUninitializedPointer& operator=(const MockUninitializedPointer&) = delete;

    void doSomething();
private:
    Object* object_{};
};

/*! @} */

AST_NAMESPACE_END
