/// @file      ScopeExit.hpp
/// @brief     作用域退出守卫
/// @details   在其作用域结束时自动执行一次清理动作的 RAII 工具
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-10-09

#pragma once

#include "AstGlobal.h"
#include "AstUtil/TypeTraits.hpp"
#include <utility>          // std::move, std::forward
#include <type_traits>      // std::decay, std::is_nothrow_move_constructible

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Util
    @{
*/

/// @brief 作用域退出守卫
/// @details 持有一个无参可调用对象，在守卫析构时执行一次，从而保证提前返回、
///          跳出循环或抛出异常时清理动作都能完成——等价于其它语言的 defer 语句。
///          动作只执行一次：移动或 @ref release() 之后原守卫不再执行。
/// @tparam F 无参可调用对象类型，如 lambda、函数对象、函数指针、std::function<void()> 等
/// @note 析构函数是隐式的 noexcept，清理动作一旦抛出异常将直接终止程序，因此动作本身不应抛出。
/// @warning 守卫不可拷贝，但可以移动，以便从工厂函数 @ref aScopeExit() 返回。
/// @code
///     auto guard = aScopeExit([&]{ file.close(); });   // 离开作用域时自动 close
///     ...
///     guard.release();                                 // 若不需要清理，则放弃动作
/// @endcode
/// @ingroup Util
template <typename F>
class ScopeExit
{
    static_assert(is_callable<F&>::value, "type F must be callable with no arguments");
public:
    /// @brief 以左值可调用对象构造（拷贝一份）
    explicit ScopeExit(const F& fn)
        : fn_(fn), active_(true)
    {}

    /// @brief 以右值可调用对象构造（接管所有权）
    explicit ScopeExit(F&& fn)
        : fn_(std::move(fn)), active_(true)
    {}

    /// @brief 移动构造：接管另一守卫的动作，被移动者不再执行
    ScopeExit(ScopeExit&& other) noexcept(std::is_nothrow_move_constructible<F>::value)
        : fn_(std::move(other.fn_)), active_(other.active_)
    {
        other.active_ = false;
    }

    /// @brief 析构时执行清理动作
    ~ScopeExit()
    {
        invoke();
    }

    A_DISABLE_COPY(ScopeExit);

    /// @brief 立即执行清理动作并解除守卫
    /// @details 先解除再执行，因此即使动作抛出异常也不会被重复执行。
    void invoke()
    {
        if (active_) {
            active_ = false;
            fn_();
        }
    }

    /// @brief 放弃清理动作，析构时不再执行
    void release() noexcept
    {
        active_ = false;
    }

    /// @brief 是否仍持有待执行的清理动作
    bool isActive() const noexcept { return active_; }

    /// @brief 布尔转换：仍在活动状态
    operator bool() const noexcept { return isActive(); }

protected:
    F fn_;               ///< 离开作用域时执行的动作
    bool active_{true};  ///< 是否仍持有待执行的清理动作
};


/// @brief 创建一个作用域退出守卫，在离开当前作用域时执行给定动作
/// @tparam F 可调用对象类型
/// @param fn 无参可调用对象，通常是一个捕获了所需上下文引用的 lambda
/// @return 作用域退出守卫对象
/// @note 返回值必须绑定到具名变量上并存活到需要清理的时刻。
///       若临时对象被丢弃，临时对象会在该语句结束时立即析构并执行动作。
/// @code
///     auto guard = aScopeExit([&]{ aScopeExitCounter++; });
/// @endcode
/// @ingroup Util
template <typename F>
A_NODISCARD A_ALWAYS_INLINE ScopeExit<typename std::decay<F>::type> aScopeExit(F&& fn)
{
    return ScopeExit<typename std::decay<F>::type>(std::forward<F>(fn));
}

/*! @} */

AST_NAMESPACE_END
