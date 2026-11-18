/// @file      ValVector.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-27

#pragma once

#include "AstGlobal.h"
#include "ValArray.hpp"
#include "AstUtil/SharedPtr.hpp"
#include <string>

AST_NAMESPACE_BEGIN

/// @brief 向量值类
/// @tparam T 向量元素类型
/// @ingroup Script
template<typename T>
class ValVector: public ValArray<T, 1>
{
public:
    AST_OBJECT(ValVector)
protected:

};

// template<> class AST_SCRIPT_API ValVector<SharedPtr<Value>>;

typedef ValVector<bool> ValVectorBool;
typedef ValVector<int> ValVectorInt;
typedef ValVector<double> ValVectorDouble;
typedef ValVector<std::string> ValVectorString;
typedef ValVector<SharedPtr<Value>> ValVectorAny;

AST_NAMESPACE_END
