/// @file      TypeTrait.hpp
/// @brief     类型特征
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-02-04

#pragma once

#include "AstGlobal.h"
#include <type_traits>

AST_NAMESPACE_BEGIN


/// @brief 判断类型是否可调用
template<typename F, typename... Args>
struct is_callable {
private:
    template<typename U>
    static auto test(int) -> decltype(
        std::declval<U>()(std::declval<Args>()...), // 可调用
        std::true_type{}
    );

    template<typename>
    static std::false_type test(...);

public:
    static constexpr bool value = decltype(test<F>(0))::value;
};



AST_NAMESPACE_END
